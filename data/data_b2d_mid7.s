.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"


	.globl gUnknown_830F860
gUnknown_830F860: @ 0x830F860
	.incbin "baserom_jp.gba", 0x30f860, 0x4

	.globl gUnknown_830F864
gUnknown_830F864: @ 0x830F864
	.incbin "baserom_jp.gba", 0x30f864, 0xc

	.globl gUnknown_830F870
gUnknown_830F870: @ 0x830F870
	.incbin "baserom_jp.gba", 0x30f870, 0x38

	.globl gUnknown_830F8A8
gUnknown_830F8A8: @ 0x830F8A8
	.incbin "baserom_jp.gba", 0x30f8a8, 0x8

	.globl gUnknown_830F8B0
gUnknown_830F8B0: @ 0x830F8B0
	.incbin "baserom_jp.gba", 0x30f8b0, 0x8

	.globl gUnknown_830F8B8
gUnknown_830F8B8: @ 0x830F8B8
	.incbin "baserom_jp.gba", 0x30f8b8, 0x8

	.globl gUnknown_830F8C0
gUnknown_830F8C0: @ 0x830F8C0
	.incbin "baserom_jp.gba", 0x30f8c0, 0xc

	.globl gUnknown_830F8CC
gUnknown_830F8CC: @ 0x830F8CC
	.incbin "baserom_jp.gba", 0x30f8cc, 0x8

	.globl gUnknown_830F8D4
gUnknown_830F8D4: @ 0x830F8D4
	.incbin "baserom_jp.gba", 0x30f8d4, 0x3

	.globl gUnknown_830F8D7
gUnknown_830F8D7: @ 0x830F8D7
	.incbin "baserom_jp.gba", 0x30f8d7, 0x5

	.globl gUnknown_830F8DC
gUnknown_830F8DC: @ 0x830F8DC
	.incbin "baserom_jp.gba", 0x30f8dc, 0xd4

	.globl gUnknown_830F9B0
gUnknown_830F9B0: @ 0x830F9B0
	.incbin "baserom_jp.gba", 0x30f9b0, 0x8

	.globl gUnknown_830F9B8
gUnknown_830F9B8: @ 0x830F9B8
	.incbin "baserom_jp.gba", 0x30f9b8, 0x8

	.globl gUnknown_830F9C0
gUnknown_830F9C0: @ 0x830F9C0
	.incbin "baserom_jp.gba", 0x30f9c0, 0x8

	.globl gUnknown_830F9C8
gUnknown_830F9C8: @ 0x830F9C8
	.incbin "baserom_jp.gba", 0x30f9c8, 0x60

	.globl gUnknown_830FA28
gUnknown_830FA28: @ 0x830FA28
	.incbin "baserom_jp.gba", 0x30fa28, 0x8

	.globl gUnknown_830FA30
gUnknown_830FA30: @ 0x830FA30
	.incbin "baserom_jp.gba", 0x30fa30, 0x98

	.globl gUnknown_830FAC8
gUnknown_830FAC8: @ 0x830FAC8
	.incbin "baserom_jp.gba", 0x30fac8, 0x8

	.globl gUnknown_830FAD0
gUnknown_830FAD0: @ 0x830FAD0
	.incbin "baserom_jp.gba", 0x30fad0, 0x44

	.globl gUnknown_830FB14
gUnknown_830FB14: @ 0x830FB14
	.incbin "baserom_jp.gba", 0x30fb14, 0x8

	.globl gUnknown_830FB1C
gUnknown_830FB1C: @ 0x830FB1C
	.incbin "baserom_jp.gba", 0x30fb1c, 0x2c

	.globl gUnknown_830FB48
gUnknown_830FB48: @ 0x830FB48
	.incbin "baserom_jp.gba", 0x30fb48, 0x8

	.globl gUnknown_830FB50
gUnknown_830FB50: @ 0x830FB50
	.incbin "baserom_jp.gba", 0x30fb50, 0x18

	.globl gUnknown_830FB68
gUnknown_830FB68: @ 0x830FB68
	.string "ü$と　こ　い　あ　\l"
	.string "　と　こ　\n"
	.string "$あ　ü$ザ　こ　い　$$\l"
	.string "　ザ　こ　\n"
	.string "$$$"
	.globl gUnknown_830FB90
gUnknown_830FB90: @ 0x830FB90
	.incbin "baserom_jp.gba", 0x30fb90, 0x1e

	.globl gUnknown_830FBAE
gUnknown_830FBAE: @ 0x830FBAE
	.incbin "baserom_jp.gba", 0x30fbae, 0x5

	.globl gUnknown_830FBB3
gUnknown_830FBB3: @ 0x830FBB3
	.incbin "baserom_jp.gba", 0x30fbb3, 0x5

	.globl gUnknown_830FBB8
gUnknown_830FBB8: @ 0x830FBB8
	.string "ふにてはのせすさきなさこうそく$"
	.globl gUnknown_830FBC8
gUnknown_830FBC8: @ 0x830FBC8
	.string "ポケモンレポートに　かきこんでいます　　　　\n"
	.string "でんげんを　きらないで　ください　　　　　　$\n"
	.string "いいTVができました　$\n"
	.string "ダメTVができました　$からい$　しぶい$　あまい$　にがい$　すっぱい$"
	.globl gUnknown_830FC29
gUnknown_830FC29: @ 0x830FC29
	.incbin "baserom_jp.gba", 0x30fc29, 0x5

	.globl gUnknown_830FC2E
gUnknown_830FC2E: @ 0x830FC2E
	.incbin "baserom_jp.gba", 0x30fc2e, 0x5

	.globl gUnknown_830FC33
gUnknown_830FC33: @ 0x830FC33
	.incbin "baserom_jp.gba", 0x30fc33, 0x5

	.globl gUnknown_830FC38
gUnknown_830FC38: @ 0x830FC38
	.string "きのみブレンダー\n"
	.string "さいこうそくど　ランキング！$"
	.globl gUnknown_830FC50
gUnknown_830FC50: @ 0x830FC50
	.incbin "baserom_jp.gba", 0x30fc50, 0x10

	.globl gUnknown_830FC60
gUnknown_830FC60: @ 0x830FC60
	.incbin "baserom_jp.gba", 0x30fc60, 0x8

	.globl sContestWinnerPicDummy
sContestWinnerPicDummy: @ 0x830FC68
	.incbin "baserom_jp.gba", 0x30fc68, 0x20

	.globl gUnknown_830FC88
gUnknown_830FC88: @ 0x830FC88
	.incbin "baserom_jp.gba", 0x30fc88, 0x28

	.globl gDirectionToVectors
gDirectionToVectors: @ 0x830FCB0
	.4byte 0 @ DIR_NONE.x
	.4byte 0 @ DIR_NONE.y
	.4byte 0 @ DIR_SOUTH.x
	.4byte 1 @ DIR_SOUTH.y
	.4byte 0 @ DIR_NORTH.x
	.4byte -1 @ DIR_NORTH.y
	.4byte -1 @ DIR_WEST.x
	.4byte 0 @ DIR_WEST.y
	.4byte 1 @ DIR_EAST.x
	.4byte 0 @ DIR_EAST.y
	.4byte -1 @ DIR_SOUTHWEST.x
	.4byte 1 @ DIR_SOUTHWEST.y
	.4byte 1 @ DIR_SOUTHEAST.x
	.4byte 1 @ DIR_SOUTHEAST.y
	.4byte -1 @ DIR_NORTHWEST.x
	.4byte -1 @ DIR_NORTHWEST.y
	.4byte 1 @ DIR_NORTHEAST.x
	.4byte -1 @ DIR_NORTHEAST.y
	.globl gUnknown_830FCF8
gUnknown_830FCF8: @ 0x830FCF8
	.incbin "baserom_jp.gba", 0x30fcf8, 0x10

	.globl gUnknown_830FD08
gUnknown_830FD08: @ 0x830FD08
	.incbin "baserom_jp.gba", 0x30fd08, 0xc

	.globl gUnknown_830FD14
gUnknown_830FD14: @ 0x830FD14
	.incbin "baserom_jp.gba", 0x30fd14, 0xc

	.globl gUnknown_830FD20
gUnknown_830FD20: @ 0x830FD20
	.incbin "baserom_jp.gba", 0x30fd20, 0x2c

	.globl gUnknown_830FD4C
gUnknown_830FD4C: @ 0x830FD4C
	.globl gUnknown_830FD4C
gUnknown_830FD4C: @ 0x0830FD4C
	.incbin "baserom_jp.gba", 0x30FD4C, 0xA7DD8
	.globl gTileset_PETALBURG_CITY_PRIMARY
gTileset_PETALBURG_CITY_PRIMARY: @ 0x083B7B24
	.byte 0x01, 0x00, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0830FD54  @ tiles
	.4byte 0x08312028  @ palettes
	.4byte 0x0836E510  @ metatiles
	.4byte 0x08370510  @ metatileAttributes
	.4byte 0x080A03E9  @ callback
	.globl gTileset_PETALBURG_CITY_SECONDARY
gTileset_PETALBURG_CITY_SECONDARY: @ 0x083B7B3C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08312228  @ tiles
	.4byte 0x08312B24  @ palettes
	.4byte 0x08370910  @ metatiles
	.4byte 0x08371210  @ metatileAttributes
	.4byte 0x080A0535  @ callback
	.globl gTileset_RUSTBORO_CITY_SECONDARY
gTileset_RUSTBORO_CITY_SECONDARY: @ 0x083B7B54
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08312D24  @ tiles
	.4byte 0x083142E0  @ palettes
	.4byte 0x08371330  @ metatiles
	.4byte 0x08372910  @ metatileAttributes
	.4byte 0x080A055D  @ callback
	.globl gTileset_DEWFORD_TOWN_SECONDARY
gTileset_DEWFORD_TOWN_SECONDARY: @ 0x083B7B6C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x083144E0  @ tiles
	.4byte 0x08315960  @ palettes
	.4byte 0x08372BCC  @ metatiles
	.4byte 0x0837437C  @ metatileAttributes
	.4byte 0x080A0589  @ callback
	.globl gTileset_SLATEPORT_CITY_SECONDARY
gTileset_SLATEPORT_CITY_SECONDARY: @ 0x083B7B84
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08315B60  @ tiles
	.4byte 0x08317B28  @ palettes
	.4byte 0x08374672  @ metatiles
	.4byte 0x08375FD2  @ metatileAttributes
	.4byte 0x080A05B5  @ callback
	.globl gTileset_MAUVILLE_CITY_SECONDARY
gTileset_MAUVILLE_CITY_SECONDARY: @ 0x083B7B9C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08317D28  @ tiles
	.4byte 0x08319B4C  @ palettes
	.4byte 0x083762FE  @ metatiles
	.4byte 0x083782DE  @ metatileAttributes
	.4byte 0x080A05E1  @ callback
	.globl gTileset_LAVARIDGE_TOWN_SECONDARY
gTileset_LAVARIDGE_TOWN_SECONDARY: @ 0x083B7BB4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08319D4C  @ tiles
	.4byte 0x0831B248  @ palettes
	.4byte 0x083786DA  @ metatiles
	.4byte 0x0837A26A  @ metatileAttributes
	.4byte 0x080A0611  @ callback
	.globl gTileset_FALLARBOR_TOWN_SECONDARY
gTileset_FALLARBOR_TOWN_SECONDARY: @ 0x083B7BCC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0831B448  @ tiles
	.4byte 0x0831CBC0  @ palettes
	.4byte 0x0837A5DC  @ metatiles
	.4byte 0x0837BCCC  @ metatileAttributes
	.4byte 0x080A063D  @ callback
	.globl gTileset_FORTREE_CITY_SECONDARY
gTileset_FORTREE_CITY_SECONDARY: @ 0x083B7BE4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0831CDC0  @ tiles
	.4byte 0x0831E440  @ palettes
	.4byte 0x0837BFAA  @ metatiles
	.4byte 0x0837D12A  @ metatileAttributes
	.4byte 0x080A0665  @ callback
	.globl gTileset_LILYCOVE_CITY_SECONDARY
gTileset_LILYCOVE_CITY_SECONDARY: @ 0x083B7BFC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0831E640  @ tiles
	.4byte 0x0831F9E0  @ palettes
	.4byte 0x0837D35A  @ metatiles
	.4byte 0x0837E94A  @ metatileAttributes
	.4byte 0x080A068D  @ callback
	.globl gTileset_MOSSDEEP_CITY_SECONDARY
gTileset_MOSSDEEP_CITY_SECONDARY: @ 0x083B7C14
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0831FBE0  @ tiles
	.4byte 0x08321230  @ palettes
	.4byte 0x0837EC08  @ metatiles
	.4byte 0x08380868  @ metatileAttributes
	.4byte 0x080A06B5  @ callback
	.globl gTileset_EVER_GRANDE_CITY_SECONDARY
gTileset_EVER_GRANDE_CITY_SECONDARY: @ 0x083B7C2C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08321430  @ tiles
	.4byte 0x08322048  @ palettes
	.4byte 0x08380BF4  @ metatiles
	.4byte 0x08381674  @ metatileAttributes
	.4byte 0x080A06DD  @ callback
	.globl gTileset_PACIFIDLOG_TOWN_SECONDARY
gTileset_PACIFIDLOG_TOWN_SECONDARY: @ 0x083B7C44
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08322248  @ tiles
	.4byte 0x083239D4  @ palettes
	.4byte 0x083817C4  @ metatiles
	.4byte 0x08382474  @ metatileAttributes
	.4byte 0x080A0709  @ callback
	.globl gTileset_SOOTOPOLIS_CITY_SECONDARY
gTileset_SOOTOPOLIS_CITY_SECONDARY: @ 0x083B7C5C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08323BD4  @ tiles
	.4byte 0x08324AD4  @ palettes
	.4byte 0x0838260A  @ metatiles
	.4byte 0x083835EA  @ metatileAttributes
	.4byte 0x080A0739  @ callback
	.incbin "baserom_jp.gba", 0x3B7C74, 0x30
	.globl gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY
gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY: @ 0x083B7CA4
	.byte 0x01, 0x00, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08327FA4  @ tiles
	.4byte 0x08328CDC  @ palettes
	.4byte 0x08387F9E  @ metatiles
	.4byte 0x0838801E  @ metatileAttributes
	.4byte 0x080A0411  @ callback
	.globl gTileset_OLDALE_TOWN_MART_SECONDARY
gTileset_OLDALE_TOWN_MART_SECONDARY: @ 0x083B7CBC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08328EDC  @ tiles
	.4byte 0x0832A4FC  @ palettes
	.4byte 0x0838802E  @ metatiles
	.4byte 0x0838923E  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY
gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY: @ 0x083B7CD4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0832A6FC  @ tiles
	.4byte 0x0832B994  @ palettes
	.4byte 0x08389480  @ metatiles
	.4byte 0x0838A300  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_DESERT_RUINS_SECONDARY
gTileset_DESERT_RUINS_SECONDARY: @ 0x083B7CEC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0832BB94  @ tiles
	.4byte 0x0832D680  @ palettes
	.4byte 0x0838A4D0  @ metatiles
	.4byte 0x0838BEB0  @ metatileAttributes
	.4byte 0x080A0805  @ callback
	.globl gTileset_RUSTBORO_CITY_POKEMON_SCHOOL_SECONDARY
gTileset_RUSTBORO_CITY_POKEMON_SCHOOL_SECONDARY: @ 0x083B7D04
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0832D880  @ tiles
	.4byte 0x0832DFC8  @ palettes
	.4byte 0x0838C1EC  @ metatiles
	.4byte 0x0838C58C  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_SLATEPORT_CITY_POKEMON_FAN_CLUB_SECONDARY
gTileset_SLATEPORT_CITY_POKEMON_FAN_CLUB_SECONDARY: @ 0x083B7D1C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0832E1C8  @ tiles
	.4byte 0x0832EAF4  @ palettes
	.4byte 0x0838C600  @ metatiles
	.4byte 0x0838CC80  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.incbin "baserom_jp.gba", 0x3B7D34, 0x18
	.globl gTileset_METEOR_FALLS_1F_1R_SECONDARY
gTileset_METEOR_FALLS_1F_1R_SECONDARY: @ 0x083B7D4C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0832EF40  @ tiles
	.4byte 0x08330C60  @ palettes
	.4byte 0x0838CD74  @ metatiles
	.4byte 0x0838D764  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_SECONDARY
gTileset_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_SECONDARY: @ 0x083B7D64
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08330E60  @ tiles
	.4byte 0x08331DEC  @ palettes
	.4byte 0x0838D8A2  @ metatiles
	.4byte 0x0838E042  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_EVER_GRANDE_CITY_HALL_OF_FAME_SECONDARY
gTileset_EVER_GRANDE_CITY_HALL_OF_FAME_SECONDARY: @ 0x083B7D7C
	.byte 0x00, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08331FEC  @ tiles
	.4byte 0x08336EEC  @ palettes
	.4byte 0x0838E136  @ metatiles
	.4byte 0x0838F136  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.incbin "baserom_jp.gba", 0x3B7D94, 0x18
	.globl gTileset_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_SECONDARY
gTileset_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_SECONDARY: @ 0x083B7DAC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08337BC8  @ tiles
	.4byte 0x083387C0  @ palettes
	.4byte 0x0838F726  @ metatiles
	.4byte 0x0838FBA6  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_ROUTE117_POKEMON_DAY_CARE_SECONDARY
gTileset_ROUTE117_POKEMON_DAY_CARE_SECONDARY: @ 0x083B7DC4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x083389C0  @ tiles
	.4byte 0x083393FC  @ palettes
	.4byte 0x0838FC36  @ metatiles
	.4byte 0x08390076  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY
gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY: @ 0x083B7DDC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x083395FC  @ tiles
	.4byte 0x0833B2B0  @ palettes
	.4byte 0x083900FE  @ metatiles
	.4byte 0x083920EE  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_MAUVILLE_CITY_BIKE_SHOP_SECONDARY
gTileset_MAUVILLE_CITY_BIKE_SHOP_SECONDARY: @ 0x083B7DF4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0833B4B0  @ tiles
	.4byte 0x0833C7E0  @ palettes
	.4byte 0x083924EC  @ metatiles
	.4byte 0x0839346C  @ metatileAttributes
	.4byte 0x080A0881  @ callback
	.globl gTileset_RUSTURF_TUNNEL_SECONDARY
gTileset_RUSTURF_TUNNEL_SECONDARY: @ 0x083B7E0C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0833C9E0  @ tiles
	.4byte 0x0833D428  @ palettes
	.4byte 0x0839365C  @ metatiles
	.4byte 0x08393B8C  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.incbin "baserom_jp.gba", 0x3B7E24, 0xC0
	.globl gTileset_LILYCOVE_CITY_CONTEST_LOBBY_SECONDARY
gTileset_LILYCOVE_CITY_CONTEST_LOBBY_SECONDARY: @ 0x083B7EE4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0834425C  @ tiles
	.4byte 0x08344DB0  @ palettes
	.4byte 0x083955A6  @ metatiles
	.4byte 0x08396436  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_SECONDARY
gTileset_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_SECONDARY: @ 0x083B7EFC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08344FB0  @ tiles
	.4byte 0x083462CC  @ palettes
	.4byte 0x08396608  @ metatiles
	.4byte 0x08396EF8  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY
gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY: @ 0x083B7F14
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x083464CC  @ tiles
	.4byte 0x08347598  @ palettes
	.4byte 0x08397016  @ metatiles
	.4byte 0x08397C56  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_SECONDARY
gTileset_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_SECONDARY: @ 0x083B7F2C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08347798  @ tiles
	.4byte 0x083487FC  @ palettes
	.4byte 0x08397DDE  @ metatiles
	.4byte 0x083987BE  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_UNDERWATER_ROUTE126_SECONDARY
gTileset_UNDERWATER_ROUTE126_SECONDARY: @ 0x083B7F44
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x083489FC  @ tiles
	.4byte 0x08349BB8  @ palettes
	.4byte 0x083988FA  @ metatiles
	.4byte 0x083997BA  @ metatileAttributes
	.4byte 0x080A07BD  @ callback
	.globl gTileset_PETALBURG_CITY_GYM_SECONDARY
gTileset_PETALBURG_CITY_GYM_SECONDARY: @ 0x083B7F5C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0834E8CC  @ tiles
	.4byte 0x0834EF70  @ palettes
	.4byte 0x0839DDB4  @ metatiles
	.4byte 0x0839EBB4  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_SOOTOPOLIS_CITY_GYM_1F_SECONDARY
gTileset_SOOTOPOLIS_CITY_GYM_1F_SECONDARY: @ 0x083B7F74
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0834FD50  @ tiles
	.4byte 0x08350EE4  @ palettes
	.4byte 0x0839FB4E  @ metatiles
	.4byte 0x083A02EE  @ metatileAttributes
	.4byte 0x080A07E1  @ callback
	.globl gTileset_OLDALE_TOWN_HOUSE1_SECONDARY
gTileset_OLDALE_TOWN_HOUSE1_SECONDARY: @ 0x083B7F8C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08349DB8  @ tiles
	.4byte 0x0834B7E4  @ palettes
	.4byte 0x08399992  @ metatiles
	.4byte 0x0839B992  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_MAUVILLE_CITY_GAME_CORNER_SECONDARY
gTileset_MAUVILLE_CITY_GAME_CORNER_SECONDARY: @ 0x083B7FA4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0834B9E4  @ tiles
	.4byte 0x0834C6A8  @ palettes
	.4byte 0x0839BD92  @ metatiles
	.4byte 0x0839C392  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_RUSTBORO_CITY_GYM_SECONDARY
gTileset_RUSTBORO_CITY_GYM_SECONDARY: @ 0x083B7FBC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0834CFD0  @ tiles
	.4byte 0x0834D354  @ palettes
	.4byte 0x0839C866  @ metatiles
	.4byte 0x0839CBE6  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_DEWFORD_TOWN_GYM_SECONDARY
gTileset_DEWFORD_TOWN_GYM_SECONDARY: @ 0x083B7FD4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0834D554  @ tiles
	.4byte 0x0834D820  @ palettes
	.4byte 0x0839CC56  @ metatiles
	.4byte 0x0839D0A6  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_MAUVILLE_CITY_GYM_SECONDARY
gTileset_MAUVILLE_CITY_GYM_SECONDARY: @ 0x083B7FEC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0834DA20  @ tiles
	.4byte 0x0834E1A4  @ palettes
	.4byte 0x0839D130  @ metatiles
	.4byte 0x0839D880  @ metatileAttributes
	.4byte 0x080A0855  @ callback
	.globl gTileset_LAVARIDGE_TOWN_GYM_1F_SECONDARY
gTileset_LAVARIDGE_TOWN_GYM_1F_SECONDARY: @ 0x083B8004
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0834E3A4  @ tiles
	.4byte 0x0834E6CC  @ palettes
	.4byte 0x0839D96A  @ metatiles
	.4byte 0x0839DD3A  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.incbin "baserom_jp.gba", 0x3B801C, 0x18
	.globl gTileset_FORTREE_CITY_GYM_SECONDARY
gTileset_FORTREE_CITY_GYM_SECONDARY: @ 0x083B8034
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0834F170  @ tiles
	.4byte 0x0834F4E4  @ palettes
	.4byte 0x0839ED74  @ metatiles
	.4byte 0x0839F274  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_MOSSDEEP_CITY_GYM_SECONDARY
gTileset_MOSSDEEP_CITY_GYM_SECONDARY: @ 0x083B804C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0834F6E4  @ tiles
	.4byte 0x0834FB50  @ palettes
	.4byte 0x0839F314  @ metatiles
	.4byte 0x0839FA64  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.incbin "baserom_jp.gba", 0x3B8064, 0x30

	.globl gUnknown_83B8094
gUnknown_83B8094: @ 0x83B8094
	.incbin "baserom_jp.gba", 0x3b8094, 0x4

	.globl gUnknown_83B8098
gUnknown_83B8098: @ 0x83B8098
	.globl gUnknown_83B8098
gUnknown_83B8098: @ 0x083B8098
	.incbin "baserom_jp.gba", 0x3B8098, 0x4
	.globl gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY
gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY: @ 0x083B809C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0835B068  @ tiles
	.4byte 0x0835C0E4  @ palettes
	.4byte 0x083A2308  @ metatiles
	.4byte 0x083A37C8  @ metatileAttributes
	.4byte 0x080A0831  @ callback
	.globl gTileset_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_SECONDARY
gTileset_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_SECONDARY: @ 0x083B80B4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0835C2E4  @ tiles
	.4byte 0x0835CFE8  @ palettes
	.4byte 0x083A3A60  @ metatiles
	.4byte 0x083A5A30  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.incbin "baserom_jp.gba", 0x3B80CC, 0xA8
	.globl gTileset_MOSSDEEP_CITY_GAME_CORNER_1F_SECONDARY
gTileset_MOSSDEEP_CITY_GAME_CORNER_1F_SECONDARY: @ 0x083B8174
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08365604  @ tiles
	.4byte 0x08365A24  @ palettes
	.4byte 0x083AF2CE  @ metatiles
	.4byte 0x083AF61E  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.incbin "baserom_jp.gba", 0x3B818C, 0x60
	.globl gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY
gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY: @ 0x083B81EC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0836B2CC  @ tiles
	.4byte 0x0836BD30  @ palettes
	.4byte 0x083B6012  @ metatiles
	.4byte 0x083B70E2  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_SECONDARY
gTileset_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_SECONDARY: @ 0x083B8204
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0836BF30  @ tiles
	.4byte 0x0836D898  @ palettes
	.4byte 0x083B72FC  @ metatiles
	.4byte 0x083B772C  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.incbin "baserom_jp.gba", 0x3B821C, 0x728
	.globl gMapLayout_PETALBURG_CITY
gMapLayout_PETALBURG_CITY: @ 0x083B8944
	.4byte 30  @ width
	.4byte 30  @ height
	.4byte 0x083B8234  @ border
	.4byte 0x083B823C  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3B895C, 0x12C8
	.globl gMapLayout_SLATEPORT_CITY
gMapLayout_SLATEPORT_CITY: @ 0x083B9C24
	.4byte 40  @ width
	.4byte 60  @ height
	.4byte 0x083B895C  @ border
	.4byte 0x083B8964  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3B9C3C, 0x648
	.globl gMapLayout_MAUVILLE_CITY
gMapLayout_MAUVILLE_CITY: @ 0x083BA284
	.4byte 40  @ width
	.4byte 20  @ height
	.4byte 0x083B9C3C  @ border
	.4byte 0x083B9C44  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3BA29C, 0x12C8
	.globl gMapLayout_RUSTBORO_CITY
gMapLayout_RUSTBORO_CITY: @ 0x083BB564
	.4byte 40  @ width
	.4byte 60  @ height
	.4byte 0x083BA29C  @ border
	.4byte 0x083BA2A4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTBORO_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3BB57C, 0x648
	.globl gMapLayout_FORTREE_CITY
gMapLayout_FORTREE_CITY: @ 0x083BBBC4
	.4byte 40  @ width
	.4byte 20  @ height
	.4byte 0x083BB57C  @ border
	.4byte 0x083BB584  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FORTREE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3BBBDC, 0x1908
	.globl gMapLayout_LILYCOVE_CITY
gMapLayout_LILYCOVE_CITY: @ 0x083BD4E4
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte 0x083BBBDC  @ border
	.4byte 0x083BBBE4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3BD4FC, 0x1908
	.globl gMapLayout_MOSSDEEP_CITY
gMapLayout_MOSSDEEP_CITY: @ 0x083BEE04
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte 0x083BD4FC  @ border
	.4byte 0x083BD504  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3BEE1C, 0x1C28
	.globl gMapLayout_SOOTOPOLIS_CITY
gMapLayout_SOOTOPOLIS_CITY: @ 0x083C0A44
	.4byte 60  @ width
	.4byte 60  @ height
	.4byte 0x083BEE1C  @ border
	.4byte 0x083BEE24  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SOOTOPOLIS_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C0A5C, 0x1908
	.globl gMapLayout_EVER_GRANDE_CITY
gMapLayout_EVER_GRANDE_CITY: @ 0x083C2364
	.4byte 40  @ width
	.4byte 80  @ height
	.4byte 0x083C0A5C  @ border
	.4byte 0x083C0A64  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C237C, 0x328
	.globl gMapLayout_LITTLEROOT_TOWN
gMapLayout_LITTLEROOT_TOWN: @ 0x083C26A4
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte 0x083C237C  @ border
	.4byte 0x083C2384  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C26BC, 0x328
	.globl gMapLayout_OLDALE_TOWN
gMapLayout_OLDALE_TOWN: @ 0x083C29E4
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte 0x083C26BC  @ border
	.4byte 0x083C26C4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C29FC, 0x328
	.globl gMapLayout_DEWFORD_TOWN
gMapLayout_DEWFORD_TOWN: @ 0x083C2D24
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte 0x083C29FC  @ border
	.4byte 0x083C2A04  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DEWFORD_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C2D3C, 0x328
	.globl gMapLayout_LAVARIDGE_TOWN
gMapLayout_LAVARIDGE_TOWN: @ 0x083C3064
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte 0x083C2D3C  @ border
	.4byte 0x083C2D44  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C307C, 0x328
	.globl gMapLayout_FALLARBOR_TOWN
gMapLayout_FALLARBOR_TOWN: @ 0x083C33A4
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte 0x083C307C  @ border
	.4byte 0x083C3084  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C33BC, 0x328
	.globl gMapLayout_VERDANTURF_TOWN
gMapLayout_VERDANTURF_TOWN: @ 0x083C36E4
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte 0x083C33BC  @ border
	.4byte 0x083C33C4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C36FC, 0x648
	.globl gMapLayout_PACIFIDLOG_TOWN
gMapLayout_PACIFIDLOG_TOWN: @ 0x083C3D44
	.4byte 20  @ width
	.4byte 40  @ height
	.4byte 0x083C36FC  @ border
	.4byte 0x083C3704  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C3D5C, 0x328
	.globl gMapLayout_ROUTE101
gMapLayout_ROUTE101: @ 0x083C4084
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte 0x083C3D5C  @ border
	.4byte 0x083C3D64  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C409C, 0x7D8
	.globl gMapLayout_ROUTE102
gMapLayout_ROUTE102: @ 0x083C4874
	.4byte 50  @ width
	.4byte 20  @ height
	.4byte 0x083C409C  @ border
	.4byte 0x083C40A4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C488C, 0xDC8
	.globl gMapLayout_ROUTE103
gMapLayout_ROUTE103: @ 0x083C5654
	.4byte 80  @ width
	.4byte 22  @ height
	.4byte 0x083C488C  @ border
	.4byte 0x083C4894  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C566C, 0x1908
	.globl gMapLayout_ROUTE104
gMapLayout_ROUTE104: @ 0x083C6F74
	.4byte 40  @ width
	.4byte 80  @ height
	.4byte 0x083C566C  @ border
	.4byte 0x083C5674  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTBORO_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C6F8C, 0x1908
	.globl gMapLayout_ROUTE105
gMapLayout_ROUTE105: @ 0x083C8894
	.4byte 40  @ width
	.4byte 80  @ height
	.4byte 0x083C6F8C  @ border
	.4byte 0x083C6F94  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DEWFORD_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C88AC, 0xC88
	.globl gMapLayout_ROUTE106
gMapLayout_ROUTE106: @ 0x083C9534
	.4byte 80  @ width
	.4byte 20  @ height
	.4byte 0x083C88AC  @ border
	.4byte 0x083C88B4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DEWFORD_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C954C, 0x968
	.globl gMapLayout_ROUTE107
gMapLayout_ROUTE107: @ 0x083C9EB4
	.4byte 60  @ width
	.4byte 20  @ height
	.4byte 0x083C954C  @ border
	.4byte 0x083C9554  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DEWFORD_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C9ECC, 0x968
	.globl gMapLayout_ROUTE108
gMapLayout_ROUTE108: @ 0x083CA834
	.4byte 60  @ width
	.4byte 20  @ height
	.4byte 0x083C9ECC  @ border
	.4byte 0x083C9ED4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3CA84C, 0x13B8
	.globl gMapLayout_ROUTE109
gMapLayout_ROUTE109: @ 0x083CBC04
	.4byte 40  @ width
	.4byte 63  @ height
	.4byte 0x083CA84C  @ border
	.4byte 0x083CA854  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3CBC1C, 0x1F48
	.globl gMapLayout_ROUTE110
gMapLayout_ROUTE110: @ 0x083CDB64
	.4byte 40  @ width
	.4byte 100  @ height
	.4byte 0x083CBC1C  @ border
	.4byte 0x083CBC24  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3CDB7C, 0x2BC8
	.globl gMapLayout_ROUTE111
gMapLayout_ROUTE111: @ 0x083D0744
	.4byte 40  @ width
	.4byte 140  @ height
	.4byte 0x083CDB7C  @ border
	.4byte 0x083CDB84  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3D075C, 0x12C8
	.globl gMapLayout_ROUTE112
gMapLayout_ROUTE112: @ 0x083D1A24
	.4byte 40  @ width
	.4byte 60  @ height
	.4byte 0x083D075C  @ border
	.4byte 0x083D0764  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3D1A3C, 0xFA8
	.globl gMapLayout_ROUTE113
gMapLayout_ROUTE113: @ 0x083D29E4
	.4byte 100  @ width
	.4byte 20  @ height
	.4byte 0x083D1A3C  @ border
	.4byte 0x083D1A44  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3D29FC, 0x1908
	.globl gMapLayout_ROUTE114
gMapLayout_ROUTE114: @ 0x083D4304
	.4byte 40  @ width
	.4byte 80  @ height
	.4byte 0x083D29FC  @ border
	.4byte 0x083D2A04  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3D431C, 0x1908
	.globl gMapLayout_ROUTE115
gMapLayout_ROUTE115: @ 0x083D5C24
	.4byte 40  @ width
	.4byte 80  @ height
	.4byte 0x083D431C  @ border
	.4byte 0x083D4324  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3D5C3C, 0xFA8
	.globl gMapLayout_ROUTE116
gMapLayout_ROUTE116: @ 0x083D6BE4
	.4byte 100  @ width
	.4byte 20  @ height
	.4byte 0x083D5C3C  @ border
	.4byte 0x083D5C44  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTBORO_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3D6BFC, 0x968
	.globl gMapLayout_ROUTE117
gMapLayout_ROUTE117: @ 0x083D7564
	.4byte 60  @ width
	.4byte 20  @ height
	.4byte 0x083D6BFC  @ border
	.4byte 0x083D6C04  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3D757C, 0xC88
	.globl gMapLayout_ROUTE118
gMapLayout_ROUTE118: @ 0x083D8204
	.4byte 80  @ width
	.4byte 20  @ height
	.4byte 0x083D757C  @ border
	.4byte 0x083D7584  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3D821C, 0x2BC8
	.globl gMapLayout_ROUTE119
gMapLayout_ROUTE119: @ 0x083DADE4
	.4byte 40  @ width
	.4byte 140  @ height
	.4byte 0x083D821C  @ border
	.4byte 0x083D8224  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FORTREE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3DADFC, 0x1F48
	.globl gMapLayout_ROUTE120
gMapLayout_ROUTE120: @ 0x083DCD44
	.4byte 40  @ width
	.4byte 100  @ height
	.4byte 0x083DADFC  @ border
	.4byte 0x083DAE04  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FORTREE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3DCD5C, 0xC88
	.globl gMapLayout_ROUTE121
gMapLayout_ROUTE121: @ 0x083DD9E4
	.4byte 80  @ width
	.4byte 20  @ height
	.4byte 0x083DCD5C  @ border
	.4byte 0x083DCD64  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3DD9FC, 0xC88
	.globl gMapLayout_ROUTE122
gMapLayout_ROUTE122: @ 0x083DE684
	.4byte 40  @ width
	.4byte 40  @ height
	.4byte 0x083DD9FC  @ border
	.4byte 0x083DDA04  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3DE69C, 0x15E8
	.globl gMapLayout_ROUTE123
gMapLayout_ROUTE123: @ 0x083DFC84
	.4byte 140  @ width
	.4byte 20  @ height
	.4byte 0x083DE69C  @ border
	.4byte 0x083DE6A4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3DFC9C, 0x3208
	.globl gMapLayout_ROUTE124
gMapLayout_ROUTE124: @ 0x083E2EA4
	.4byte 80  @ width
	.4byte 80  @ height
	.4byte 0x083DFC9C  @ border
	.4byte 0x083DFCA4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3E2EBC, 0x1908
	.globl gMapLayout_ROUTE125
gMapLayout_ROUTE125: @ 0x083E47C4
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte 0x083E2EBC  @ border
	.4byte 0x083E2EC4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3E47DC, 0x3208
	.globl gMapLayout_ROUTE126
gMapLayout_ROUTE126: @ 0x083E79E4
	.4byte 80  @ width
	.4byte 80  @ height
	.4byte 0x083E47DC  @ border
	.4byte 0x083E47E4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3E79FC, 0x3208
	.globl gMapLayout_ROUTE127
gMapLayout_ROUTE127: @ 0x083EAC04
	.4byte 80  @ width
	.4byte 80  @ height
	.4byte 0x083E79FC  @ border
	.4byte 0x083E7A04  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3EAC1C, 0x2588
	.globl gMapLayout_ROUTE128
gMapLayout_ROUTE128: @ 0x083ED1A4
	.4byte 120  @ width
	.4byte 40  @ height
	.4byte 0x083EAC1C  @ border
	.4byte 0x083EAC24  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3ED1BC, 0x1908
	.globl gMapLayout_ROUTE129
gMapLayout_ROUTE129: @ 0x083EEAC4
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte 0x083ED1BC  @ border
	.4byte 0x083ED1C4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3EEADC, 0x2BE8
	.globl gMapLayout_ROUTE131
gMapLayout_ROUTE131: @ 0x083F16C4
	.4byte 60  @ width
	.4byte 40  @ height
	.4byte 0x083F03FC  @ border
	.4byte 0x083F0404  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3F16DC, 0x1908
	.globl gMapLayout_ROUTE132
gMapLayout_ROUTE132: @ 0x083F2FE4
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte 0x083F16DC  @ border
	.4byte 0x083F16E4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3F2FFC, 0x1908
	.globl gMapLayout_ROUTE133
gMapLayout_ROUTE133: @ 0x083F4904
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte 0x083F2FFC  @ border
	.4byte 0x083F3004  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3F491C, 0x1908
	.globl gMapLayout_ROUTE134
gMapLayout_ROUTE134: @ 0x083F6224
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte 0x083F491C  @ border
	.4byte 0x083F4924  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3F623C, 0x3208
	.globl gMapLayout_UNDERWATER_ROUTE126
gMapLayout_UNDERWATER_ROUTE126: @ 0x083F9444
	.4byte 80  @ width
	.4byte 80  @ height
	.4byte 0x083F623C  @ border
	.4byte 0x083F6244  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3F945C, 0x3208
	.globl gMapLayout_UNDERWATER_ROUTE127
gMapLayout_UNDERWATER_ROUTE127: @ 0x083FC664
	.4byte 80  @ width
	.4byte 80  @ height
	.4byte 0x083F945C  @ border
	.4byte 0x083F9464  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FC67C, 0x2588
	.globl gMapLayout_UNDERWATER_ROUTE128
gMapLayout_UNDERWATER_ROUTE128: @ 0x083FEC04
	.4byte 120  @ width
	.4byte 40  @ height
	.4byte 0x083FC67C  @ border
	.4byte 0x083FC684  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FEC1C, 0xD0
	.globl gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F
gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F: @ 0x083FECEC
	.4byte 11  @ width
	.4byte 9  @ height
	.4byte 0x083FEC1C  @ border
	.4byte 0x083FEC24  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FED04, 0x98
	.globl gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F: @ 0x083FED9C
	.4byte 9  @ width
	.4byte 8  @ height
	.4byte 0x083FED04  @ border
	.4byte 0x083FED0C  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FEDB4, 0xD0
	.globl gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_1F
gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_1F: @ 0x083FEE84
	.4byte 11  @ width
	.4byte 9  @ height
	.4byte 0x083FEDB4  @ border
	.4byte 0x083FEDBC  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FEE9C, 0x98
	.globl gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_2F
gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_2F: @ 0x083FEF34
	.4byte 9  @ width
	.4byte 8  @ height
	.4byte 0x083FEE9C  @ border
	.4byte 0x083FEEA4  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FEF4C, 0x15C
	.globl gMapLayout_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB
gMapLayout_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB: @ 0x083FF0A8
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte 0x083FEF4C  @ border
	.4byte 0x083FEF54  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FF0C0, 0xBC
	.globl gMapLayout_OLDALE_TOWN_HOUSE1
gMapLayout_OLDALE_TOWN_HOUSE1: @ 0x083FF17C
	.4byte 10  @ width
	.4byte 9  @ height
	.4byte 0x083FF0C0  @ border
	.4byte 0x083FF0C8  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FF194, 0xB8
	.globl gMapLayout_OLDALE_TOWN_HOUSE2
gMapLayout_OLDALE_TOWN_HOUSE2: @ 0x083FF24C
	.4byte 11  @ width
	.4byte 8  @ height
	.4byte 0x083FF194  @ border
	.4byte 0x083FF19C  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FF264, 0x104
	.globl gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F
gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F: @ 0x083FF368
	.4byte 14  @ width
	.4byte 9  @ height
	.4byte 0x083FF264  @ border
	.4byte 0x083FF26C  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FF380, 0x120
	.globl gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F
gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F: @ 0x083FF4A0
	.4byte 14  @ width
	.4byte 10  @ height
	.4byte 0x083FF380  @ border
	.4byte 0x083FF388  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FF4B8, 0xB8
	.globl gMapLayout_OLDALE_TOWN_MART
gMapLayout_OLDALE_TOWN_MART: @ 0x083FF570
	.4byte 11  @ width
	.4byte 8  @ height
	.4byte 0x083FF4B8  @ border
	.4byte 0x083FF4C0  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FF588, 0xA8
	.globl gMapLayout_DEWFORD_TOWN_HOUSE1
gMapLayout_DEWFORD_TOWN_HOUSE1: @ 0x083FF630
	.4byte 10  @ width
	.4byte 8  @ height
	.4byte 0x083FF588  @ border
	.4byte 0x083FF590  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FF648, 0x3F8
	.globl gMapLayout_DEWFORD_TOWN_GYM
gMapLayout_DEWFORD_TOWN_GYM: @ 0x083FFA40
	.4byte 18  @ width
	.4byte 28  @ height
	.4byte 0x083FF648  @ border
	.4byte 0x083FF650  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_DEWFORD_TOWN_GYM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FFA58, 0x13C
	.globl gMapLayout_DEWFORD_TOWN_HALL
gMapLayout_DEWFORD_TOWN_HALL: @ 0x083FFB94
	.4byte 17  @ width
	.4byte 9  @ height
	.4byte 0x083FFA58  @ border
	.4byte 0x083FFA60  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FFBAC, 0xBC
	.globl gMapLayout_DEWFORD_TOWN_HOUSE2
gMapLayout_DEWFORD_TOWN_HOUSE2: @ 0x083FFC68
	.4byte 10  @ width
	.4byte 9  @ height
	.4byte 0x083FFBAC  @ border
	.4byte 0x083FFBB4  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FFC80, 0xB8
	.globl gMapLayout_LAVARIDGE_TOWN_HERB_SHOP
gMapLayout_LAVARIDGE_TOWN_HERB_SHOP: @ 0x083FFD38
	.4byte 11  @ width
	.4byte 8  @ height
	.4byte 0x083FFC80  @ border
	.4byte 0x083FFC88  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FFD50, 0x290
	.globl gMapLayout_LAVARIDGE_TOWN_GYM_1F
gMapLayout_LAVARIDGE_TOWN_GYM_1F: @ 0x083FFFE0
	.4byte 17  @ width
	.4byte 19  @ height
	.4byte 0x083FFD50  @ border
	.4byte 0x083FFD58  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_GYM_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FFFF8, 0x290
	.globl gMapLayout_LAVARIDGE_TOWN_GYM_B1F
gMapLayout_LAVARIDGE_TOWN_GYM_B1F: @ 0x08400288
	.4byte 17  @ width
	.4byte 19  @ height
	.4byte 0x083FFFF8  @ border
	.4byte 0x08400000  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_GYM_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4002A0, 0x104
	.globl gMapLayout_LAVARIDGE_TOWN_POKEMON_CENTER_1F
gMapLayout_LAVARIDGE_TOWN_POKEMON_CENTER_1F: @ 0x084003A4
	.4byte 14  @ width
	.4byte 9  @ height
	.4byte 0x084002A0  @ border
	.4byte 0x084002A8  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4003BC, 0x490
	.globl gMapLayout_LILYCOVE_CITY_HOUSE2
gMapLayout_LILYCOVE_CITY_HOUSE2: @ 0x0840084C
	.4byte 8  @ width
	.4byte 8  @ height
	.4byte 0x084007C4  @ border
	.4byte 0x084007CC  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x400864, 0x13C
	.globl gMapLayout_VERDANTURF_TOWN_WANDAS_HOUSE
gMapLayout_VERDANTURF_TOWN_WANDAS_HOUSE: @ 0x084009A0
	.4byte 17  @ width
	.4byte 8  @ height
	.4byte 0x08400888  @ border
	.4byte 0x08400890  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4009B8, 0xBC
	.globl gMapLayout_PACIFIDLOG_TOWN_HOUSE1
gMapLayout_PACIFIDLOG_TOWN_HOUSE1: @ 0x08400A74
	.4byte 10  @ width
	.4byte 9  @ height
	.4byte 0x084009B8  @ border
	.4byte 0x084009C0  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x400A8C, 0xBC
	.globl gMapLayout_PACIFIDLOG_TOWN_HOUSE2
gMapLayout_PACIFIDLOG_TOWN_HOUSE2: @ 0x08400B48
	.4byte 10  @ width
	.4byte 9  @ height
	.4byte 0x08400A8C  @ border
	.4byte 0x08400A94  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x400B60, 0x7E8
	.globl gMapLayout_PETALBURG_CITY_GYM
gMapLayout_PETALBURG_CITY_GYM: @ 0x08401348
	.4byte 9  @ width
	.4byte 112  @ height
	.4byte 0x08400B60  @ border
	.4byte 0x08400B68  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_GYM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x401360, 0xA8
	.globl gMapLayout_PETALBURG_CITY_HOUSE2
gMapLayout_PETALBURG_CITY_HOUSE2: @ 0x08401408
	.4byte 10  @ width
	.4byte 8  @ height
	.4byte 0x08401360  @ border
	.4byte 0x08401368  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x401420, 0x280
	.globl gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_1F
gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_1F: @ 0x084016A0
	.4byte 21  @ width
	.4byte 15  @ height
	.4byte 0x08401420  @ border
	.4byte 0x08401428  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4016B8, 0x208
	.globl gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_2F
gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_2F: @ 0x084018C0
	.4byte 17  @ width
	.4byte 15  @ height
	.4byte 0x084016B8  @ border
	.4byte 0x084016C0  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4018D8, 0x184
	.globl gMapLayout_SLATEPORT_CITY_POKEMON_FAN_CLUB
gMapLayout_SLATEPORT_CITY_POKEMON_FAN_CLUB: @ 0x08401A5C
	.4byte 14  @ width
	.4byte 11  @ height
	.4byte 0x08401920  @ border
	.4byte 0x08401928  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_POKEMON_FAN_CLUB_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x401A74, 0x170
	.globl gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_1F
gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_1F: @ 0x08401BE4
	.4byte 20  @ width
	.4byte 9  @ height
	.4byte 0x08401A74  @ border
	.4byte 0x08401A7C  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x401BFC, 0x170
	.globl gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_2F
gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_2F: @ 0x08401D6C
	.4byte 20  @ width
	.4byte 9  @ height
	.4byte 0x08401BFC  @ border
	.4byte 0x08401C04  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x401D84, 0x2D8
	.globl gMapLayout_SLATEPORT_CITY_HARBOR
gMapLayout_SLATEPORT_CITY_HARBOR: @ 0x0840205C
	.4byte 24  @ width
	.4byte 15  @ height
	.4byte 0x08401D84  @ border
	.4byte 0x08401D8C  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x402074, 0x1AC
	.globl gMapLayout_MAUVILLE_CITY_GYM
gMapLayout_MAUVILLE_CITY_GYM: @ 0x08402220
	.4byte 10  @ width
	.4byte 21  @ height
	.4byte 0x08402074  @ border
	.4byte 0x0840207C  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_GYM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x402238, 0xE0
	.globl gMapLayout_MAUVILLE_CITY_BIKE_SHOP
gMapLayout_MAUVILLE_CITY_BIKE_SHOP: @ 0x08402318
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte 0x08402238  @ border
	.4byte 0x08402240  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_BIKE_SHOP_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x402330, 0x1EC
	.globl gMapLayout_MAUVILLE_CITY_GAME_CORNER
gMapLayout_MAUVILLE_CITY_GAME_CORNER: @ 0x0840251C
	.4byte 22  @ width
	.4byte 11  @ height
	.4byte 0x08402330  @ border
	.4byte 0x08402338  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_GAME_CORNER_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x402534, 0x160
	.globl gMapLayout_RUSTBORO_CITY_DEVON_CORP_1F
gMapLayout_RUSTBORO_CITY_DEVON_CORP_1F: @ 0x08402694
	.4byte 19  @ width
	.4byte 9  @ height
	.4byte 0x08402534  @ border
	.4byte 0x0840253C  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4026AC, 0x160
	.globl gMapLayout_RUSTBORO_CITY_DEVON_CORP_2F
gMapLayout_RUSTBORO_CITY_DEVON_CORP_2F: @ 0x0840280C
	.4byte 19  @ width
	.4byte 9  @ height
	.4byte 0x084026AC  @ border
	.4byte 0x084026B4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x402824, 0x1C0
	.globl gMapLayout_RUSTBORO_CITY_GYM
gMapLayout_RUSTBORO_CITY_GYM: @ 0x084029E4
	.4byte 11  @ width
	.4byte 20  @ height
	.4byte 0x08402824  @ border
	.4byte 0x0840282C  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTBORO_CITY_GYM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4029FC, 0x110
	.globl gMapLayout_RUSTBORO_CITY_POKEMON_SCHOOL
gMapLayout_RUSTBORO_CITY_POKEMON_SCHOOL: @ 0x08402B0C
	.4byte 12  @ width
	.4byte 11  @ height
	.4byte 0x084029FC  @ border
	.4byte 0x08402A04  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTBORO_CITY_POKEMON_SCHOOL_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x402B24, 0xE0
	.globl gMapLayout_RUSTBORO_CITY_HOUSE2
gMapLayout_RUSTBORO_CITY_HOUSE2: @ 0x08402C04
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte 0x08402B24  @ border
	.4byte 0x08402B2C  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x402C1C, 0xD8
	.globl gMapLayout_RUSTBORO_CITY_HOUSE1
gMapLayout_RUSTBORO_CITY_HOUSE1: @ 0x08402CF4
	.4byte 13  @ width
	.4byte 8  @ height
	.4byte 0x08402C1C  @ border
	.4byte 0x08402C24  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x402D0C, 0xD0
	.globl gMapLayout_RUSTBORO_CITY_CUTTERS_HOUSE
gMapLayout_RUSTBORO_CITY_CUTTERS_HOUSE: @ 0x08402DDC
	.4byte 11  @ width
	.4byte 9  @ height
	.4byte 0x08402D0C  @ border
	.4byte 0x08402D14  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x402DF4, 0x68
	.globl gMapLayout_FORTREE_CITY_HOUSE1
gMapLayout_FORTREE_CITY_HOUSE1: @ 0x08402E5C
	.4byte 8  @ width
	.4byte 6  @ height
	.4byte 0x08402DF4  @ border
	.4byte 0x08402DFC  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x402E74, 0x3F0
	.globl gMapLayout_FORTREE_CITY_GYM
gMapLayout_FORTREE_CITY_GYM: @ 0x08403264
	.4byte 20  @ width
	.4byte 25  @ height
	.4byte 0x08402E74  @ border
	.4byte 0x08402E7C  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_FORTREE_CITY_GYM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40327C, 0x68
	.globl gMapLayout_FORTREE_CITY_HOUSE2
gMapLayout_FORTREE_CITY_HOUSE2: @ 0x084032E4
	.4byte 8  @ width
	.4byte 6  @ height
	.4byte 0x0840327C  @ border
	.4byte 0x08403284  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4032FC, 0xE0
	.globl gMapLayout_ROUTE104_MR_BRINEYS_HOUSE
gMapLayout_ROUTE104_MR_BRINEYS_HOUSE: @ 0x084033DC
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte 0x084032FC  @ border
	.4byte 0x08403304  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4033F4, 0x254
	.globl gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F
gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F: @ 0x08403648
	.4byte 21  @ width
	.4byte 14  @ height
	.4byte 0x084033F4  @ border
	.4byte 0x084033FC  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x403660, 0x244
	.globl gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F
gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F: @ 0x084038A4
	.4byte 22  @ width
	.4byte 13  @ height
	.4byte 0x08403660  @ border
	.4byte 0x08403668  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4038BC, 0x2F0
	.globl gMapLayout_LILYCOVE_CITY_CONTEST_LOBBY
gMapLayout_LILYCOVE_CITY_CONTEST_LOBBY: @ 0x08403BAC
	.4byte 31  @ width
	.4byte 12  @ height
	.4byte 0x084038BC  @ border
	.4byte 0x084038C4  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_CONTEST_LOBBY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x403BC4, 0xD30
	.globl gMapLayout_LILYCOVE_CITY_CONTEST_HALL
gMapLayout_LILYCOVE_CITY_CONTEST_HALL: @ 0x084048F4
	.4byte 51  @ width
	.4byte 33  @ height
	.4byte 0x08403BC4  @ border
	.4byte 0x08403BCC  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_CONTEST_LOBBY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40490C, 0x158
	.globl gMapLayout_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB
gMapLayout_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB: @ 0x08404A64
	.4byte 12  @ width
	.4byte 14  @ height
	.4byte 0x0840490C  @ border
	.4byte 0x08404914  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x404A7C, 0x758
	.globl gMapLayout_MOSSDEEP_CITY_GYM
gMapLayout_MOSSDEEP_CITY_GYM: @ 0x084051D4
	.4byte 26  @ width
	.4byte 36  @ height
	.4byte 0x08404A7C  @ border
	.4byte 0x08404A84  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_GYM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4051EC, 0x37C
	.globl gMapLayout_SOOTOPOLIS_CITY_GYM_1F
gMapLayout_SOOTOPOLIS_CITY_GYM_1F: @ 0x08405568
	.4byte 17  @ width
	.4byte 26  @ height
	.4byte 0x084051EC  @ border
	.4byte 0x084051F4  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SOOTOPOLIS_CITY_GYM_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x405580, 0x37C
	.globl gMapLayout_SOOTOPOLIS_CITY_GYM_B1F
gMapLayout_SOOTOPOLIS_CITY_GYM_B1F: @ 0x084058FC
	.4byte 17  @ width
	.4byte 26  @ height
	.4byte 0x08405580  @ border
	.4byte 0x08405588  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SOOTOPOLIS_CITY_GYM_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x405914, 0x174
	.globl gMapLayout_EVER_GRANDE_CITY_SIDNEYS_ROOM
gMapLayout_EVER_GRANDE_CITY_SIDNEYS_ROOM: @ 0x08405A88
	.4byte 13  @ width
	.4byte 14  @ height
	.4byte 0x08405914  @ border
	.4byte 0x0840591C  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x405AA0, 0x174
	.globl gMapLayout_EVER_GRANDE_CITY_PHOEBES_ROOM
gMapLayout_EVER_GRANDE_CITY_PHOEBES_ROOM: @ 0x08405C14
	.4byte 13  @ width
	.4byte 14  @ height
	.4byte 0x08405AA0  @ border
	.4byte 0x08405AA8  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x405C2C, 0x174
	.globl gMapLayout_EVER_GRANDE_CITY_GLACIAS_ROOM
gMapLayout_EVER_GRANDE_CITY_GLACIAS_ROOM: @ 0x08405DA0
	.4byte 13  @ width
	.4byte 14  @ height
	.4byte 0x08405C2C  @ border
	.4byte 0x08405C34  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x405DB8, 0x174
	.globl gMapLayout_EVER_GRANDE_CITY_DRAKES_ROOM
gMapLayout_EVER_GRANDE_CITY_DRAKES_ROOM: @ 0x08405F2C
	.4byte 13  @ width
	.4byte 14  @ height
	.4byte 0x08405DB8  @ border
	.4byte 0x08405DC0  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x405F44, 0x15C
	.globl gMapLayout_EVER_GRANDE_CITY_CHAMPIONS_ROOM
gMapLayout_EVER_GRANDE_CITY_CHAMPIONS_ROOM: @ 0x084060A0
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte 0x08405F44  @ border
	.4byte 0x08405F4C  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4060B8, 0x128
	.globl gMapLayout_EVER_GRANDE_CITY_HALL1
gMapLayout_EVER_GRANDE_CITY_HALL1: @ 0x084061E0
	.4byte 11  @ width
	.4byte 13  @ height
	.4byte 0x084060B8  @ border
	.4byte 0x084060C0  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4061F8, 0x118
	.globl gMapLayout_ROUTE104_PRETTY_PETAL_FLOWER_SHOP
gMapLayout_ROUTE104_PRETTY_PETAL_FLOWER_SHOP: @ 0x08406310
	.4byte 15  @ width
	.4byte 9  @ height
	.4byte 0x084061F8  @ border
	.4byte 0x08406200  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x406328, 0x140
	.globl gMapLayout_ROUTE112_CABLE_CAR_STATION
gMapLayout_ROUTE112_CABLE_CAR_STATION: @ 0x08406468
	.4byte 13  @ width
	.4byte 12  @ height
	.4byte 0x08406328  @ border
	.4byte 0x08406330  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x406480, 0xA8
	.globl gMapLayout_ROUTE114_FOSSIL_MANIACS_HOUSE
gMapLayout_ROUTE114_FOSSIL_MANIACS_HOUSE: @ 0x08406528
	.4byte 10  @ width
	.4byte 8  @ height
	.4byte 0x08406480  @ border
	.4byte 0x08406488  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x406540, 0x2AC
	.globl gMapLayout_ROUTE114_FOSSIL_MANIACS_TUNNEL
gMapLayout_ROUTE114_FOSSIL_MANIACS_TUNNEL: @ 0x084067EC
	.4byte 13  @ width
	.4byte 26  @ height
	.4byte 0x08406540  @ border
	.4byte 0x08406548  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x406804, 0xB8
	.globl gMapLayout_ROUTE114_LANETTES_HOUSE
gMapLayout_ROUTE114_LANETTES_HOUSE: @ 0x084068BC
	.4byte 11  @ width
	.4byte 8  @ height
	.4byte 0x08406804  @ border
	.4byte 0x0840680C  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4068D4, 0xBC
	.globl gMapLayout_ROUTE116_TUNNELERS_REST_HOUSE
gMapLayout_ROUTE116_TUNNELERS_REST_HOUSE: @ 0x08406990
	.4byte 10  @ width
	.4byte 9  @ height
	.4byte 0x084068D4  @ border
	.4byte 0x084068DC  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4069A8, 0xE0
	.globl gMapLayout_ROUTE117_POKEMON_DAY_CARE
gMapLayout_ROUTE117_POKEMON_DAY_CARE: @ 0x08406A88
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte 0x084069A8  @ border
	.4byte 0x084069B0  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_ROUTE117_POKEMON_DAY_CARE_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x406AA0, 0x200
	.globl gMapLayout_ROUTE121_SAFARI_ZONE_ENTRANCE
gMapLayout_ROUTE121_SAFARI_ZONE_ENTRANCE: @ 0x08406CA0
	.4byte 18  @ width
	.4byte 14  @ height
	.4byte 0x08406AA0  @ border
	.4byte 0x08406AA8  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x406CB8, 0x9E0
	.globl gMapLayout_METEOR_FALLS_1F_1R
gMapLayout_METEOR_FALLS_1F_1R: @ 0x08407698
	.4byte 30  @ width
	.4byte 42  @ height
	.4byte 0x08406CB8  @ border
	.4byte 0x08406CC0  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_METEOR_FALLS_1F_1R_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4076B0, 0x788
	.globl gMapLayout_METEOR_FALLS_1F_2R
gMapLayout_METEOR_FALLS_1F_2R: @ 0x08407E38
	.4byte 30  @ width
	.4byte 32  @ height
	.4byte 0x084076B0  @ border
	.4byte 0x084076B8  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_METEOR_FALLS_1F_1R_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x407E50, 0x8A4
	.globl gMapLayout_METEOR_FALLS_B1F_1R
gMapLayout_METEOR_FALLS_B1F_1R: @ 0x084086F4
	.4byte 29  @ width
	.4byte 38  @ height
	.4byte 0x08407E50  @ border
	.4byte 0x08407E58  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_METEOR_FALLS_1F_1R_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40870C, 0x194
	.globl gMapLayout_METEOR_FALLS_B1F_2R
gMapLayout_METEOR_FALLS_B1F_2R: @ 0x084088A0
	.4byte 11  @ width
	.4byte 18  @ height
	.4byte 0x0840870C  @ border
	.4byte 0x08408714  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_METEOR_FALLS_1F_1R_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4088B8, 0x6C8
	.globl gMapLayout_RUSTURF_TUNNEL
gMapLayout_RUSTURF_TUNNEL: @ 0x08408F80
	.4byte 36  @ width
	.4byte 24  @ height
	.4byte 0x084088B8  @ border
	.4byte 0x084088C0  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTURF_TUNNEL_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x408F98, 0x198
	.globl gMapLayout_UNDERWATER_SOOTOPOLIS_CITY
gMapLayout_UNDERWATER_SOOTOPOLIS_CITY: @ 0x08409130
	.4byte 20  @ width
	.4byte 10  @ height
	.4byte 0x08408F98  @ border
	.4byte 0x08408FA0  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x409148, 0x46C
	.globl gMapLayout_DESERT_RUINS
gMapLayout_DESERT_RUINS: @ 0x084095B4
	.4byte 17  @ width
	.4byte 33  @ height
	.4byte 0x08409148  @ border
	.4byte 0x08409150  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4095CC, 0x4F4
	.globl gMapLayout_GRANITE_CAVE_1F
gMapLayout_GRANITE_CAVE_1F: @ 0x08409AC0
	.4byte 42  @ width
	.4byte 15  @ height
	.4byte 0x084095CC  @ border
	.4byte 0x084095D4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x409AD8, 0x688
	.globl gMapLayout_GRANITE_CAVE_B1F
gMapLayout_GRANITE_CAVE_B1F: @ 0x0840A160
	.4byte 32  @ width
	.4byte 26  @ height
	.4byte 0x08409AD8  @ border
	.4byte 0x08409AE0  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40A178, 0x688
	.globl gMapLayout_GRANITE_CAVE_B2F
gMapLayout_GRANITE_CAVE_B2F: @ 0x0840A800
	.4byte 32  @ width
	.4byte 26  @ height
	.4byte 0x0840A178  @ border
	.4byte 0x0840A180  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40A818, 0x1088
	.globl gMapLayout_PETALBURG_WOODS
gMapLayout_PETALBURG_WOODS: @ 0x0840B8A0
	.4byte 48  @ width
	.4byte 44  @ height
	.4byte 0x0840A818  @ border
	.4byte 0x0840A820  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTBORO_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40B8B8, 0xEB8
	.globl gMapLayout_MT_CHIMNEY
gMapLayout_MT_CHIMNEY: @ 0x0840C770
	.4byte 40  @ width
	.4byte 47  @ height
	.4byte 0x0840B8B8  @ border
	.4byte 0x0840B8C0  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40C788, 0x34C
	.globl gMapLayout_MT_PYRE_1F
gMapLayout_MT_PYRE_1F: @ 0x0840CAD4
	.4byte 22  @ width
	.4byte 19  @ height
	.4byte 0x0840C788  @ border
	.4byte 0x0840C790  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40CAEC, 0x15C
	.globl gMapLayout_MT_PYRE_2F
gMapLayout_MT_PYRE_2F: @ 0x0840CC48
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte 0x0840CAEC  @ border
	.4byte 0x0840CAF4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40CC60, 0x15C
	.globl gMapLayout_MT_PYRE_3F
gMapLayout_MT_PYRE_3F: @ 0x0840CDBC
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte 0x0840CC60  @ border
	.4byte 0x0840CC68  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40CDD4, 0x15C
	.globl gMapLayout_MT_PYRE_4F
gMapLayout_MT_PYRE_4F: @ 0x0840CF30
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte 0x0840CDD4  @ border
	.4byte 0x0840CDDC  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40CF48, 0x15C
	.globl gMapLayout_MT_PYRE_5F
gMapLayout_MT_PYRE_5F: @ 0x0840D0A4
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte 0x0840CF48  @ border
	.4byte 0x0840CF50  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40D0BC, 0x15C
	.globl gMapLayout_MT_PYRE_6F
gMapLayout_MT_PYRE_6F: @ 0x0840D218
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte 0x0840D0BC  @ border
	.4byte 0x0840D0C4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40D230, 0x698
	.globl gMapLayout_AQUA_HIDEOUT_1F
gMapLayout_AQUA_HIDEOUT_1F: @ 0x0840D8C8
	.4byte 28  @ width
	.4byte 30  @ height
	.4byte 0x0840D230  @ border
	.4byte 0x0840D238  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40D8E0, 0x998
	.globl gMapLayout_AQUA_HIDEOUT_B1F
gMapLayout_AQUA_HIDEOUT_B1F: @ 0x0840E278
	.4byte 51  @ width
	.4byte 24  @ height
	.4byte 0x0840D8E0  @ border
	.4byte 0x0840D8E8  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40E290, 0x668
	.globl gMapLayout_AQUA_HIDEOUT_B2F
gMapLayout_AQUA_HIDEOUT_B2F: @ 0x0840E8F8
	.4byte 34  @ width
	.4byte 24  @ height
	.4byte 0x0840E290  @ border
	.4byte 0x0840E298  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40E910, 0x104
	.globl gMapLayout_UNDERWATER_SEAFLOOR_CAVERN
gMapLayout_UNDERWATER_SEAFLOOR_CAVERN: @ 0x0840EA14
	.4byte 14  @ width
	.4byte 9  @ height
	.4byte 0x0840E910  @ border
	.4byte 0x0840E918  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40EA2C, 0x328
	.globl gMapLayout_SEAFLOOR_CAVERN_ENTRANCE
gMapLayout_SEAFLOOR_CAVERN_ENTRANCE: @ 0x0840ED54
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte 0x0840EA2C  @ border
	.4byte 0x0840EA34  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40ED6C, 0x350
	.globl gMapLayout_SEAFLOOR_CAVERN_ROOM1
gMapLayout_SEAFLOOR_CAVERN_ROOM1: @ 0x0840F0BC
	.4byte 20  @ width
	.4byte 21  @ height
	.4byte 0x0840ED6C  @ border
	.4byte 0x0840ED74  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40F0D4, 0x1B8
	.globl gMapLayout_SEAFLOOR_CAVERN_ROOM2
gMapLayout_SEAFLOOR_CAVERN_ROOM2: @ 0x0840F28C
	.4byte 18  @ width
	.4byte 12  @ height
	.4byte 0x0840F0D4  @ border
	.4byte 0x0840F0DC  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40F2A4, 0x228
	.globl gMapLayout_SEAFLOOR_CAVERN_ROOM3
gMapLayout_SEAFLOOR_CAVERN_ROOM3: @ 0x0840F4CC
	.4byte 16  @ width
	.4byte 17  @ height
	.4byte 0x0840F2A4  @ border
	.4byte 0x0840F2AC  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40F4E4, 0x2B4
	.globl gMapLayout_SEAFLOOR_CAVERN_ROOM4
gMapLayout_SEAFLOOR_CAVERN_ROOM4: @ 0x0840F798
	.4byte 18  @ width
	.4byte 19  @ height
	.4byte 0x0840F4E4  @ border
	.4byte 0x0840F4EC  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40F7B0, 0x118B4
	.globl gMapLayout_FORTREE_CITY_DECORATION_SHOP
gMapLayout_FORTREE_CITY_DECORATION_SHOP: @ 0x08421064
	.4byte 8  @ width
	.4byte 6  @ height
	.4byte 0x08420FFC  @ border
	.4byte 0x08421004  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42107C, 0x1FC
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_1F
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_1F: @ 0x08421278
	.4byte 18  @ width
	.4byte 8  @ height
	.4byte 0x08421150  @ border
	.4byte 0x08421158  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x421290, 0x128
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_2F
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_2F: @ 0x084213B8
	.4byte 18  @ width
	.4byte 8  @ height
	.4byte 0x08421290  @ border
	.4byte 0x08421298  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4213D0, 0x128
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_3F
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_3F: @ 0x084214F8
	.4byte 18  @ width
	.4byte 8  @ height
	.4byte 0x084213D0  @ border
	.4byte 0x084213D8  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x421510, 0x128
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_4F
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_4F: @ 0x08421638
	.4byte 18  @ width
	.4byte 8  @ height
	.4byte 0x08421510  @ border
	.4byte 0x08421518  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x421650, 0x128
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_5F
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_5F: @ 0x08421778
	.4byte 18  @ width
	.4byte 8  @ height
	.4byte 0x08421650  @ border
	.4byte 0x08421658  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x421790, 0x1B8
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP: @ 0x08421948
	.4byte 18  @ width
	.4byte 12  @ height
	.4byte 0x08421790  @ border
	.4byte 0x08421798  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x421960, 0x1908
	.globl gMapLayout_ROUTE130
gMapLayout_ROUTE130: @ 0x08423268
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte 0x08421960  @ border
	.4byte 0x08421968  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x423280, 0x251C
	.globl gMapLayout_RUSTBORO_CITY_DEVON_CORP_3F
gMapLayout_RUSTBORO_CITY_DEVON_CORP_3F: @ 0x0842579C
	.4byte 19  @ width
	.4byte 9  @ height
	.4byte 0x0842563C  @ border
	.4byte 0x08425644  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4257B4, 0x1D0
	.globl gMapLayout_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F
gMapLayout_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F: @ 0x08425984
	.4byte 19  @ width
	.4byte 12  @ height
	.4byte 0x084257B4  @ border
	.4byte 0x084257BC  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42599C, 0x444
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR: @ 0x08425DE0
	.4byte 5  @ width
	.4byte 6  @ height
	.4byte 0x08425D9C  @ border
	.4byte 0x08425DA4  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x425DF8, 0x3208
	.globl gMapLayout_UNDERWATER_ROUTE124
gMapLayout_UNDERWATER_ROUTE124: @ 0x08429000
	.4byte 80  @ width
	.4byte 80  @ height
	.4byte 0x08425DF8  @ border
	.4byte 0x08425E00  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x429018, 0x148
	.globl gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_1F
gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_1F: @ 0x08429160
	.4byte 16  @ width
	.4byte 10  @ height
	.4byte 0x08429018  @ border
	.4byte 0x08429020  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x429178, 0x148
	.globl gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_2F
gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_2F: @ 0x084292C0
	.4byte 16  @ width
	.4byte 10  @ height
	.4byte 0x08429178  @ border
	.4byte 0x08429180  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4292D8, 0x3830
	.globl gMapLayout_GRANITE_CAVE_STEVENS_ROOM
gMapLayout_GRANITE_CAVE_STEVENS_ROOM: @ 0x0842CB08
	.4byte 15  @ width
	.4byte 14  @ height
	.4byte 0x0842C95C  @ border
	.4byte 0x0842C964  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42CB20, 0x191C
	.globl gMapLayout_JAGGED_PASS
gMapLayout_JAGGED_PASS: @ 0x0842E43C
	.4byte 30  @ width
	.4byte 46  @ height
	.4byte 0x0842D96C  @ border
	.4byte 0x0842D974  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42E454, 0xA6C
	.globl gMapLayout_FIERY_PATH
gMapLayout_FIERY_PATH: @ 0x0842EEC0
	.4byte 35  @ width
	.4byte 38  @ height
	.4byte 0x0842E454  @ border
	.4byte 0x0842E45C  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42EED8, 0x104
	.globl gMapLayout_RUSTBORO_CITY_FLAT2_1F
gMapLayout_RUSTBORO_CITY_FLAT2_1F: @ 0x0842EFDC
	.4byte 14  @ width
	.4byte 9  @ height
	.4byte 0x0842EED8  @ border
	.4byte 0x0842EEE0  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42EFF4, 0x104
	.globl gMapLayout_RUSTBORO_CITY_FLAT2_2F
gMapLayout_RUSTBORO_CITY_FLAT2_2F: @ 0x0842F0F8
	.4byte 14  @ width
	.4byte 9  @ height
	.4byte 0x0842EFF4  @ border
	.4byte 0x0842EFFC  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42F110, 0x104
	.globl gMapLayout_RUSTBORO_CITY_FLAT2_3F
gMapLayout_RUSTBORO_CITY_FLAT2_3F: @ 0x0842F214
	.4byte 14  @ width
	.4byte 9  @ height
	.4byte 0x0842F110  @ border
	.4byte 0x0842F118  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42F22C, 0x78
	.globl gMapLayout_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE
gMapLayout_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE: @ 0x0842F2A4
	.4byte 8  @ width
	.4byte 7  @ height
	.4byte 0x0842F22C  @ border
	.4byte 0x0842F234  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42F2BC, 0x208
	.globl gMapLayout_EVER_GRANDE_CITY_HALL_OF_FAME
gMapLayout_EVER_GRANDE_CITY_HALL_OF_FAME: @ 0x0842F4C4
	.4byte 15  @ width
	.4byte 17  @ height
	.4byte 0x0842F2BC  @ border
	.4byte 0x0842F2C4  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_HALL_OF_FAME_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42F4DC, 0xE0
	.globl gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_1F
gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_1F: @ 0x0842F5BC
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte 0x0842F4DC  @ border
	.4byte 0x0842F4E4  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42F5D4, 0xE0
	.globl gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_2F
gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_2F: @ 0x0842F6B4
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte 0x0842F5D4  @ border
	.4byte 0x0842F5DC  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42F6CC, 0x1000
	.globl gMapLayout_MT_PYRE_EXTERIOR
gMapLayout_MT_PYRE_EXTERIOR: @ 0x084306CC
	.4byte 38  @ width
	.4byte 51  @ height
	.4byte 0x0842F7A0  @ border
	.4byte 0x0842F7A8  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4306E4, 0xE7C
	.globl gMapLayout_MT_PYRE_SUMMIT
gMapLayout_MT_PYRE_SUMMIT: @ 0x08431560
	.4byte 50  @ width
	.4byte 37  @ height
	.4byte 0x084306E4  @ border
	.4byte 0x084306EC  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x431578, 0x4E0
	.globl gMapLayout_MOSSDEEP_CITY_GAME_CORNER_1F
gMapLayout_MOSSDEEP_CITY_GAME_CORNER_1F: @ 0x08431A58
	.4byte 12  @ width
	.4byte 10  @ height
	.4byte 0x08431960  @ border
	.4byte 0x08431968  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_GAME_CORNER_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x431A70, 0xE0
	.globl gMapLayout_MOSSDEEP_CITY_GAME_CORNER_B1F
gMapLayout_MOSSDEEP_CITY_GAME_CORNER_B1F: @ 0x08431B50
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte 0x08431A70  @ border
	.4byte 0x08431A78  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x431B68, 0x78
	.globl gMapLayout_SOOTOPOLIS_CITY_HOUSE1
gMapLayout_SOOTOPOLIS_CITY_HOUSE1: @ 0x08431BE0
	.4byte 8  @ width
	.4byte 7  @ height
	.4byte 0x08431B68  @ border
	.4byte 0x08431B70  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x431BF8, 0x78
	.globl gMapLayout_SOOTOPOLIS_CITY_HOUSE2
gMapLayout_SOOTOPOLIS_CITY_HOUSE2: @ 0x08431C70
	.4byte 8  @ width
	.4byte 7  @ height
	.4byte 0x08431BF8  @ border
	.4byte 0x08431C00  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x431C88, 0x78
	.globl gMapLayout_SOOTOPOLIS_CITY_HOUSE3
gMapLayout_SOOTOPOLIS_CITY_HOUSE3: @ 0x08431D00
	.4byte 8  @ width
	.4byte 7  @ height
	.4byte 0x08431C88  @ border
	.4byte 0x08431C90  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x431D18, 0xB9C
	.globl gMapLayout_RUSTBORO_CITY_FLAT1_1F
gMapLayout_RUSTBORO_CITY_FLAT1_1F: @ 0x084328B4
	.4byte 14  @ width
	.4byte 8  @ height
	.4byte 0x084327CC  @ border
	.4byte 0x084327D4  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4328CC, 0xE8
	.globl gMapLayout_RUSTBORO_CITY_FLAT1_2F
gMapLayout_RUSTBORO_CITY_FLAT1_2F: @ 0x084329B4
	.4byte 14  @ width
	.4byte 8  @ height
	.4byte 0x084328CC  @ border
	.4byte 0x084328D4  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4329CC, 0x2F4
	.globl gMapLayout_EVER_GRANDE_CITY_HALL4
gMapLayout_EVER_GRANDE_CITY_HALL4: @ 0x08432CC0
	.4byte 11  @ width
	.4byte 34  @ height
	.4byte 0x084329CC  @ border
	.4byte 0x084329D4  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x432CD8, 0x44CC
	.globl gMapLayout_MOSSDEEP_CITY_STEVENS_HOUSE
gMapLayout_MOSSDEEP_CITY_STEVENS_HOUSE: @ 0x084371A4
	.4byte 11  @ width
	.4byte 8  @ height
	.4byte 0x084370EC  @ border
	.4byte 0x084370F4  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4371BC, 0xD268
	.globl gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_LOBBY
gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_LOBBY: @ 0x08444424
	.4byte 13  @ width
	.4byte 10  @ height
	.4byte 0x08444318  @ border
	.4byte 0x08444320  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x44443C, 0x58
	.globl gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR
gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR: @ 0x08444494
	.4byte 5  @ width
	.4byte 8  @ height
	.4byte 0x0844443C  @ border
	.4byte 0x08444444  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4444AC, 0xBC
	.globl gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM
gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM: @ 0x08444568
	.4byte 10  @ width
	.4byte 9  @ height
	.4byte 0x084444AC  @ border
	.4byte 0x084444B4  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x444580, 0xF4
	.globl gMapLayout_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM
gMapLayout_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM: @ 0x08444674
	.4byte 13  @ width
	.4byte 9  @ height
	.4byte 0x08444580  @ border
	.4byte 0x08444588  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x44468C, 0xC86C
	.globl gMapLayout_UNDERWATER_ROUTE105
gMapLayout_UNDERWATER_ROUTE105: @ 0x08450EF8
	.4byte 40  @ width
	.4byte 80  @ height
	.4byte 0x0844F5F0  @ border
	.4byte 0x0844F5F8  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x450F10, 0x1908
	.globl gMapLayout_UNDERWATER_ROUTE125
gMapLayout_UNDERWATER_ROUTE125: @ 0x08452818
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte 0x08450F10  @ border
	.4byte 0x08450F18  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x452830, 0x1908
	.globl gMapLayout_UNDERWATER_ROUTE129
gMapLayout_UNDERWATER_ROUTE129: @ 0x08454138
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte 0x08452830  @ border
	.4byte 0x08452838  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x454150, 0x5EC4
	.globl gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F
gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F: @ 0x0845A014
	.4byte 11  @ width
	.4byte 8  @ height
	.4byte 0x08459F5C  @ border
	.4byte 0x08459F64  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x45A02C, 0xE0
	.globl gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F
gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F: @ 0x0845A10C
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte 0x0845A02C  @ border
	.4byte 0x0845A034  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x45A124, 0xD0

	.globl gUnknown_845A1F4
gUnknown_845A1F4: @ 0x845A1F4
	.incbin "baserom_jp.gba", 0x45a1f4, 0x6e4
	.globl gMapHeaders
gMapHeaders: @ 0x0845A8D8
	@ struct MapHeader { mapLayout, events, mapScripts, connections, music, mapLayoutId, regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType }
	@ MAP_PETALBURG_CITY (g0 m0)
	.4byte gMapLayout_PETALBURG_CITY  @ mapLayout
	.4byte gMapEvents_PETALBURG_CITY  @ events
	.4byte PetalburgCity_MapScripts  @ mapScripts
	.4byte gMapConnections_PETALBURG_CITY  @ connections
	.2byte 0x016A  @ music
	.2byte 0x0001  @ mapLayoutId
	.byte 0x07, 0x00, 0x02, 0x02, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY (g0 m1)
	.4byte gMapLayout_SLATEPORT_CITY  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY  @ events
	.4byte SlateportCity_MapScripts  @ mapScripts
	.4byte gMapConnections_SLATEPORT_CITY  @ connections
	.2byte 0x01B1  @ music
	.2byte 0x0002  @ mapLayoutId
	.byte 0x08, 0x00, 0x02, 0x02, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MAUVILLE_CITY (g0 m2)
	.4byte gMapLayout_MAUVILLE_CITY  @ mapLayout
	.4byte gMapEvents_MAUVILLE_CITY  @ events
	.4byte MauvilleCity_MapScripts  @ mapScripts
	.4byte gMapConnections_MAUVILLE_CITY  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0003  @ mapLayoutId
	.byte 0x09, 0x00, 0x02, 0x02, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY (g0 m3)
	.4byte gMapLayout_RUSTBORO_CITY  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY  @ events
	.4byte RustboroCity_MapScripts  @ mapScripts
	.4byte gMapConnections_RUSTBORO_CITY  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0004  @ mapLayoutId
	.byte 0x0A, 0x00, 0x02, 0x02, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FORTREE_CITY (g0 m4)
	.4byte gMapLayout_FORTREE_CITY  @ mapLayout
	.4byte gMapEvents_FORTREE_CITY  @ events
	.4byte FortreeCity_MapScripts  @ mapScripts
	.4byte gMapConnections_FORTREE_CITY  @ connections
	.2byte 0x017E  @ music
	.2byte 0x0005  @ mapLayoutId
	.byte 0x0B, 0x00, 0x02, 0x02, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY (g0 m5)
	.4byte gMapLayout_LILYCOVE_CITY  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY  @ events
	.4byte LilycoveCity_MapScripts  @ mapScripts
	.4byte gMapConnections_LILYCOVE_CITY  @ connections
	.2byte 0x0198  @ music
	.2byte 0x0006  @ mapLayoutId
	.byte 0x0C, 0x00, 0x02, 0x02, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY (g0 m6)
	.4byte gMapLayout_MOSSDEEP_CITY  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY  @ events
	.4byte MossdeepCity_MapScripts  @ mapScripts
	.4byte gMapConnections_MOSSDEEP_CITY  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0007  @ mapLayoutId
	.byte 0x0D, 0x00, 0x02, 0x02, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY (g0 m7)
	.4byte gMapLayout_SOOTOPOLIS_CITY  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY  @ events
	.4byte SootopolisCity_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01BD  @ music
	.2byte 0x0008  @ mapLayoutId
	.byte 0x0E, 0x00, 0x02, 0x02, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY (g0 m8)
	.4byte gMapLayout_EVER_GRANDE_CITY  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY  @ events
	.4byte EverGrandeCity_MapScripts  @ mapScripts
	.4byte gMapConnections_EVER_GRANDE_CITY  @ connections
	.2byte 0x01A6  @ music
	.2byte 0x0009  @ mapLayoutId
	.byte 0x0F, 0x00, 0x02, 0x02, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LITTLEROOT_TOWN (g0 m9)
	.4byte gMapLayout_LITTLEROOT_TOWN  @ mapLayout
	.4byte gMapEvents_LITTLEROOT_TOWN  @ events
	.4byte LittlerootTown_MapScripts  @ mapScripts
	.4byte gMapConnections_LITTLEROOT_TOWN  @ connections
	.2byte 0x0195  @ music
	.2byte 0x000A  @ mapLayoutId
	.byte 0x00, 0x00, 0x02, 0x01, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_OLDALE_TOWN (g0 m10)
	.4byte gMapLayout_OLDALE_TOWN  @ mapLayout
	.4byte gMapEvents_OLDALE_TOWN  @ events
	.4byte OldaleTown_MapScripts  @ mapScripts
	.4byte gMapConnections_OLDALE_TOWN  @ connections
	.2byte 0x016B  @ music
	.2byte 0x000B  @ mapLayoutId
	.byte 0x01, 0x00, 0x02, 0x01, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_DEWFORD_TOWN (g0 m11)
	.4byte gMapLayout_DEWFORD_TOWN  @ mapLayout
	.4byte gMapEvents_DEWFORD_TOWN  @ events
	.4byte DewfordTown_MapScripts  @ mapScripts
	.4byte gMapConnections_DEWFORD_TOWN  @ connections
	.2byte 0x01AB  @ music
	.2byte 0x000C  @ mapLayoutId
	.byte 0x02, 0x00, 0x02, 0x01, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LAVARIDGE_TOWN (g0 m12)
	.4byte gMapLayout_LAVARIDGE_TOWN  @ mapLayout
	.4byte gMapEvents_LAVARIDGE_TOWN  @ events
	.4byte LavaridgeTown_MapScripts  @ mapScripts
	.4byte gMapConnections_LAVARIDGE_TOWN  @ connections
	.2byte 0x016B  @ music
	.2byte 0x000D  @ mapLayoutId
	.byte 0x03, 0x00, 0x02, 0x01, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FALLARBOR_TOWN (g0 m13)
	.4byte gMapLayout_FALLARBOR_TOWN  @ mapLayout
	.4byte gMapEvents_FALLARBOR_TOWN  @ events
	.4byte FallarborTown_MapScripts  @ mapScripts
	.4byte gMapConnections_FALLARBOR_TOWN  @ connections
	.2byte 0x01B5  @ music
	.2byte 0x000E  @ mapLayoutId
	.byte 0x04, 0x00, 0x02, 0x01, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_VERDANTURF_TOWN (g0 m14)
	.4byte gMapLayout_VERDANTURF_TOWN  @ mapLayout
	.4byte gMapEvents_VERDANTURF_TOWN  @ events
	.4byte VerdanturfTown_MapScripts  @ mapScripts
	.4byte gMapConnections_VERDANTURF_TOWN  @ connections
	.2byte 0x018E  @ music
	.2byte 0x000F  @ mapLayoutId
	.byte 0x05, 0x00, 0x02, 0x01, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PACIFIDLOG_TOWN (g0 m15)
	.4byte gMapLayout_PACIFIDLOG_TOWN  @ mapLayout
	.4byte gMapEvents_PACIFIDLOG_TOWN  @ events
	.4byte PacifidlogTown_MapScripts  @ mapScripts
	.4byte gMapConnections_PACIFIDLOG_TOWN  @ connections
	.2byte 0x0198  @ music
	.2byte 0x0010  @ mapLayoutId
	.byte 0x06, 0x00, 0x02, 0x01, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE101 (g0 m16)
	.4byte gMapLayout_ROUTE101  @ mapLayout
	.4byte gMapEvents_ROUTE101  @ events
	.4byte Route101_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE101  @ connections
	.2byte 0x0167  @ music
	.2byte 0x0011  @ mapLayoutId
	.byte 0x10, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE102 (g0 m17)
	.4byte gMapLayout_ROUTE102  @ mapLayout
	.4byte gMapEvents_ROUTE102  @ events
	.4byte 0x081E6824  @ mapScripts
	.4byte gMapConnections_ROUTE102  @ connections
	.2byte 0x0167  @ music
	.2byte 0x0012  @ mapLayoutId
	.byte 0x11, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE103 (g0 m18)
	.4byte gMapLayout_ROUTE103  @ mapLayout
	.4byte gMapEvents_ROUTE103  @ events
	.4byte Route103_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE103  @ connections
	.2byte 0x0167  @ music
	.2byte 0x0013  @ mapLayoutId
	.byte 0x12, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE104 (g0 m19)
	.4byte gMapLayout_ROUTE104  @ mapLayout
	.4byte gMapEvents_ROUTE104  @ events
	.4byte Route104_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE104  @ connections
	.2byte 0x0191  @ music
	.2byte 0x0014  @ mapLayoutId
	.byte 0x13, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE105 (g0 m20)
	.4byte gMapLayout_ROUTE105  @ mapLayout
	.4byte gMapEvents_ROUTE105  @ events
	.4byte Route105_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE105  @ connections
	.2byte 0x0191  @ music
	.2byte 0x0015  @ mapLayoutId
	.byte 0x14, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE106 (g0 m21)
	.4byte gMapLayout_ROUTE106  @ mapLayout
	.4byte gMapEvents_ROUTE106  @ events
	.4byte 0x081E83CA  @ mapScripts
	.4byte gMapConnections_ROUTE106  @ connections
	.2byte 0x0191  @ music
	.2byte 0x0016  @ mapLayoutId
	.byte 0x15, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE107 (g0 m22)
	.4byte gMapLayout_ROUTE107  @ mapLayout
	.4byte gMapEvents_ROUTE107  @ events
	.4byte 0x081E84AB  @ mapScripts
	.4byte gMapConnections_ROUTE107  @ connections
	.2byte 0x0191  @ music
	.2byte 0x0017  @ mapLayoutId
	.byte 0x16, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE108 (g0 m23)
	.4byte gMapLayout_ROUTE108  @ mapLayout
	.4byte gMapEvents_ROUTE108  @ events
	.4byte 0x081E85A0  @ mapScripts
	.4byte gMapConnections_ROUTE108  @ connections
	.2byte 0x0191  @ music
	.2byte 0x0018  @ mapLayoutId
	.byte 0x17, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE109 (g0 m24)
	.4byte gMapLayout_ROUTE109  @ mapLayout
	.4byte gMapEvents_ROUTE109  @ events
	.4byte 0x081E8676  @ mapScripts
	.4byte gMapConnections_ROUTE109  @ connections
	.2byte 0x0191  @ music
	.2byte 0x0019  @ mapLayoutId
	.byte 0x18, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE110 (g0 m25)
	.4byte gMapLayout_ROUTE110  @ mapLayout
	.4byte gMapEvents_ROUTE110  @ events
	.4byte Route110_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE110  @ connections
	.2byte 0x0168  @ music
	.2byte 0x001A  @ mapLayoutId
	.byte 0x19, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE111 (g0 m26)
	.4byte gMapLayout_ROUTE111  @ mapLayout
	.4byte gMapEvents_ROUTE111  @ events
	.4byte Route111_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE111  @ connections
	.2byte 0x0168  @ music
	.2byte 0x001B  @ mapLayoutId
	.byte 0x1A, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE112 (g0 m27)
	.4byte gMapLayout_ROUTE112  @ mapLayout
	.4byte gMapEvents_ROUTE112  @ events
	.4byte Route112_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE112  @ connections
	.2byte 0x0168  @ music
	.2byte 0x001C  @ mapLayoutId
	.byte 0x1B, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE113 (g0 m28)
	.4byte gMapLayout_ROUTE113  @ mapLayout
	.4byte gMapEvents_ROUTE113  @ events
	.4byte Route113_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE113  @ connections
	.2byte 0x01A2  @ music
	.2byte 0x001D  @ mapLayoutId
	.byte 0x1C, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE114 (g0 m29)
	.4byte gMapLayout_ROUTE114  @ mapLayout
	.4byte gMapEvents_ROUTE114  @ events
	.4byte Route114_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE114  @ connections
	.2byte 0x0168  @ music
	.2byte 0x001E  @ mapLayoutId
	.byte 0x1D, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE115 (g0 m30)
	.4byte gMapLayout_ROUTE115  @ mapLayout
	.4byte gMapEvents_ROUTE115  @ events
	.4byte Route115_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE115  @ connections
	.2byte 0x0191  @ music
	.2byte 0x001F  @ mapLayoutId
	.byte 0x1E, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE116 (g0 m31)
	.4byte gMapLayout_ROUTE116  @ mapLayout
	.4byte gMapEvents_ROUTE116  @ events
	.4byte Route116_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE116  @ connections
	.2byte 0x0191  @ music
	.2byte 0x0020  @ mapLayoutId
	.byte 0x1F, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE117 (g0 m32)
	.4byte gMapLayout_ROUTE117  @ mapLayout
	.4byte gMapEvents_ROUTE117  @ events
	.4byte Route117_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE117  @ connections
	.2byte 0x0168  @ music
	.2byte 0x0021  @ mapLayoutId
	.byte 0x20, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE118 (g0 m33)
	.4byte gMapLayout_ROUTE118  @ mapLayout
	.4byte gMapEvents_ROUTE118  @ events
	.4byte Route118_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE118  @ connections
	.2byte 0x7FFF  @ music
	.2byte 0x0022  @ mapLayoutId
	.byte 0x21, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE119 (g0 m34)
	.4byte gMapLayout_ROUTE119  @ mapLayout
	.4byte gMapEvents_ROUTE119  @ events
	.4byte Route119_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE119  @ connections
	.2byte 0x0192  @ music
	.2byte 0x0023  @ mapLayoutId
	.byte 0x22, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE120 (g0 m35)
	.4byte gMapLayout_ROUTE120  @ mapLayout
	.4byte gMapEvents_ROUTE120  @ events
	.4byte Route120_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE120  @ connections
	.2byte 0x0169  @ music
	.2byte 0x0024  @ mapLayoutId
	.byte 0x23, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE121 (g0 m36)
	.4byte gMapLayout_ROUTE121  @ mapLayout
	.4byte gMapEvents_ROUTE121  @ events
	.4byte 0x081EE0D9  @ mapScripts
	.4byte gMapConnections_ROUTE121  @ connections
	.2byte 0x0169  @ music
	.2byte 0x0025  @ mapLayoutId
	.byte 0x24, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE122 (g0 m37)
	.4byte gMapLayout_ROUTE122  @ mapLayout
	.4byte gMapEvents_ROUTE122  @ events
	.4byte 0x081EE3D5  @ mapScripts
	.4byte gMapConnections_ROUTE122  @ connections
	.2byte 0x0176  @ music
	.2byte 0x0026  @ mapLayoutId
	.byte 0x25, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE123 (g0 m38)
	.4byte gMapLayout_ROUTE123  @ mapLayout
	.4byte gMapEvents_ROUTE123  @ events
	.4byte Route123_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE123  @ connections
	.2byte 0x0176  @ music
	.2byte 0x0027  @ mapLayoutId
	.byte 0x26, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE124 (g0 m39)
	.4byte gMapLayout_ROUTE124  @ mapLayout
	.4byte gMapEvents_ROUTE124  @ events
	.4byte Route124_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE124  @ connections
	.2byte 0x0169  @ music
	.2byte 0x0028  @ mapLayoutId
	.byte 0x27, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE125 (g0 m40)
	.4byte gMapLayout_ROUTE125  @ mapLayout
	.4byte gMapEvents_ROUTE125  @ events
	.4byte Route125_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE125  @ connections
	.2byte 0x0169  @ music
	.2byte 0x0029  @ mapLayoutId
	.byte 0x28, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE126 (g0 m41)
	.4byte gMapLayout_ROUTE126  @ mapLayout
	.4byte gMapEvents_ROUTE126  @ events
	.4byte Route126_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE126  @ connections
	.2byte 0x0169  @ music
	.2byte 0x002A  @ mapLayoutId
	.byte 0x29, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE127 (g0 m42)
	.4byte gMapLayout_ROUTE127  @ mapLayout
	.4byte gMapEvents_ROUTE127  @ events
	.4byte Route127_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE127  @ connections
	.2byte 0x0169  @ music
	.2byte 0x002B  @ mapLayoutId
	.byte 0x2A, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE128 (g0 m43)
	.4byte gMapLayout_ROUTE128  @ mapLayout
	.4byte gMapEvents_ROUTE128  @ events
	.4byte Route128_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE128  @ connections
	.2byte 0x0169  @ music
	.2byte 0x002C  @ mapLayoutId
	.byte 0x2B, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE129 (g0 m44)
	.4byte gMapLayout_ROUTE129  @ mapLayout
	.4byte gMapEvents_ROUTE129  @ events
	.4byte Route129_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE129  @ connections
	.2byte 0x0192  @ music
	.2byte 0x002D  @ mapLayoutId
	.byte 0x2C, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE130 (g0 m45)
	.4byte gMapLayout_ROUTE130  @ mapLayout
	.4byte gMapEvents_ROUTE130  @ events
	.4byte Route130_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE130  @ connections
	.2byte 0x0192  @ music
	.2byte 0x0107  @ mapLayoutId
	.byte 0x2D, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE131 (g0 m46)
	.4byte gMapLayout_ROUTE131  @ mapLayout
	.4byte gMapEvents_ROUTE131  @ events
	.4byte Route131_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE131  @ connections
	.2byte 0x0192  @ music
	.2byte 0x002F  @ mapLayoutId
	.byte 0x2E, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE132 (g0 m47)
	.4byte gMapLayout_ROUTE132  @ mapLayout
	.4byte gMapEvents_ROUTE132  @ events
	.4byte 0x081EF519  @ mapScripts
	.4byte gMapConnections_ROUTE132  @ connections
	.2byte 0x0192  @ music
	.2byte 0x0030  @ mapLayoutId
	.byte 0x2F, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE133 (g0 m48)
	.4byte gMapLayout_ROUTE133  @ mapLayout
	.4byte gMapEvents_ROUTE133  @ events
	.4byte 0x081EF5D2  @ mapScripts
	.4byte gMapConnections_ROUTE133  @ connections
	.2byte 0x0192  @ music
	.2byte 0x0031  @ mapLayoutId
	.byte 0x30, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE134 (g0 m49)
	.4byte gMapLayout_ROUTE134  @ mapLayout
	.4byte gMapEvents_ROUTE134  @ events
	.4byte Route134_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE134  @ connections
	.2byte 0x0192  @ music
	.2byte 0x0032  @ mapLayoutId
	.byte 0x31, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_UNDERWATER_ROUTE124 (g0 m50)
	.4byte gMapLayout_UNDERWATER_ROUTE124  @ mapLayout
	.4byte gMapEvents_UNDERWATER_ROUTE124  @ events
	.4byte 0x081EF752  @ mapScripts
	.4byte gMapConnections_UNDERWATER_ROUTE124  @ connections
	.2byte 0x019B  @ music
	.2byte 0x0112  @ mapLayoutId
	.byte 0x32, 0x00, 0x0E, 0x05, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_UNDERWATER_ROUTE126 (g0 m51)
	.4byte gMapLayout_UNDERWATER_ROUTE126  @ mapLayout
	.4byte gMapEvents_UNDERWATER_ROUTE126  @ events
	.4byte 0x081EF753  @ mapScripts
	.4byte gMapConnections_UNDERWATER_ROUTE126  @ connections
	.2byte 0x019B  @ music
	.2byte 0x0033  @ mapLayoutId
	.byte 0x33, 0x00, 0x0E, 0x05, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_UNDERWATER_ROUTE127 (g0 m52)
	.4byte gMapLayout_UNDERWATER_ROUTE127  @ mapLayout
	.4byte gMapEvents_UNDERWATER_ROUTE127  @ events
	.4byte Underwater_Route127_MapScripts  @ mapScripts
	.4byte gMapConnections_UNDERWATER_ROUTE127  @ connections
	.2byte 0x019B  @ music
	.2byte 0x0034  @ mapLayoutId
	.byte 0x34, 0x00, 0x0E, 0x05, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_UNDERWATER_ROUTE128 (g0 m53)
	.4byte gMapLayout_UNDERWATER_ROUTE128  @ mapLayout
	.4byte gMapEvents_UNDERWATER_ROUTE128  @ events
	.4byte 0x081EF760  @ mapScripts
	.4byte gMapConnections_UNDERWATER_ROUTE128  @ connections
	.2byte 0x019B  @ music
	.2byte 0x0035  @ mapLayoutId
	.byte 0x35, 0x00, 0x0E, 0x05, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_UNDERWATER_ROUTE129 (g0 m54)
	.4byte gMapLayout_UNDERWATER_ROUTE129  @ mapLayout
	.4byte gMapEvents_UNDERWATER_ROUTE129  @ events
	.4byte Underwater_Route129_MapScripts  @ mapScripts
	.4byte gMapConnections_UNDERWATER_ROUTE129  @ connections
	.2byte 0x019B  @ music
	.2byte 0x019C  @ mapLayoutId
	.byte 0xD0, 0x00, 0x0E, 0x05, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_UNDERWATER_ROUTE105 (g0 m55)
	.4byte gMapLayout_UNDERWATER_ROUTE105  @ mapLayout
	.4byte gMapEvents_UNDERWATER_ROUTE105  @ events
	.4byte Underwater_Route105_MapScripts  @ mapScripts
	.4byte gMapConnections_UNDERWATER_ROUTE105  @ connections
	.2byte 0x019B  @ music
	.2byte 0x019A  @ mapLayoutId
	.byte 0xCE, 0x00, 0x0E, 0x05, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_UNDERWATER_ROUTE125 (g0 m56)
	.4byte gMapLayout_UNDERWATER_ROUTE125  @ mapLayout
	.4byte gMapEvents_UNDERWATER_ROUTE125  @ events
	.4byte Underwater_Route125_MapScripts  @ mapScripts
	.4byte gMapConnections_UNDERWATER_ROUTE125  @ connections
	.2byte 0x019B  @ music
	.2byte 0x019B  @ mapLayoutId
	.byte 0xCF, 0x00, 0x0E, 0x05, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F (g1 m0)
	.4byte gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F  @ mapLayout
	.4byte gMapEvents_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F  @ events
	.4byte LittlerootTown_BrendansHouse_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0195  @ music
	.2byte 0x0036  @ mapLayoutId
	.byte 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F (g1 m1)
	.4byte gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F  @ mapLayout
	.4byte gMapEvents_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F  @ events
	.4byte LittlerootTown_BrendansHouse_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0195  @ music
	.2byte 0x0037  @ mapLayoutId
	.byte 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F (g1 m2)
	.4byte gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_1F  @ mapLayout
	.4byte gMapEvents_LITTLEROOT_TOWN_MAYS_HOUSE_1F  @ events
	.4byte LittlerootTown_MaysHouse_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0195  @ music
	.2byte 0x0038  @ mapLayoutId
	.byte 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F (g1 m3)
	.4byte gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_2F  @ mapLayout
	.4byte gMapEvents_LITTLEROOT_TOWN_MAYS_HOUSE_2F  @ events
	.4byte LittlerootTown_MaysHouse_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0195  @ music
	.2byte 0x0039  @ mapLayoutId
	.byte 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB (g1 m4)
	.4byte gMapLayout_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB  @ mapLayout
	.4byte gMapEvents_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB  @ events
	.4byte LittlerootTown_ProfessorBirchsLab_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x017F  @ music
	.2byte 0x003A  @ mapLayoutId
	.byte 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_OLDALE_TOWN_HOUSE1 (g2 m0)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_OLDALE_TOWN_HOUSE1  @ events
	.4byte 0x081F28D3  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016B  @ music
	.2byte 0x003B  @ mapLayoutId
	.byte 0x01, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_OLDALE_TOWN_HOUSE2 (g2 m1)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_OLDALE_TOWN_HOUSE2  @ events
	.4byte 0x081F2949  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016B  @ music
	.2byte 0x003C  @ mapLayoutId
	.byte 0x01, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_OLDALE_TOWN_POKEMON_CENTER_1F (g2 m2)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_OLDALE_TOWN_POKEMON_CENTER_1F  @ events
	.4byte OldaleTown_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x01, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_OLDALE_TOWN_POKEMON_CENTER_2F (g2 m3)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_OLDALE_TOWN_POKEMON_CENTER_2F  @ events
	.4byte OldaleTown_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x01, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_OLDALE_TOWN_MART (g2 m4)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte gMapEvents_OLDALE_TOWN_MART  @ events
	.4byte 0x081F2B0B  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x01, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_DEWFORD_TOWN_HOUSE1 (g3 m0)
	.4byte gMapLayout_DEWFORD_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_DEWFORD_TOWN_HOUSE1  @ events
	.4byte 0x081F2C10  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AB  @ music
	.2byte 0x0040  @ mapLayoutId
	.byte 0x02, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_DEWFORD_TOWN_POKEMON_CENTER_1F (g3 m1)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_DEWFORD_TOWN_POKEMON_CENTER_1F  @ events
	.4byte DewfordTown_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x02, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_DEWFORD_TOWN_POKEMON_CENTER_2F (g3 m2)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_DEWFORD_TOWN_POKEMON_CENTER_2F  @ events
	.4byte DewfordTown_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x02, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_DEWFORD_TOWN_GYM (g3 m3)
	.4byte gMapLayout_DEWFORD_TOWN_GYM  @ mapLayout
	.4byte gMapEvents_DEWFORD_TOWN_GYM  @ events
	.4byte DewfordTown_Gym_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016C  @ music
	.2byte 0x0041  @ mapLayoutId
	.byte 0x02, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_DEWFORD_TOWN_HALL (g3 m4)
	.4byte gMapLayout_DEWFORD_TOWN_HALL  @ mapLayout
	.4byte gMapEvents_DEWFORD_TOWN_HALL  @ events
	.4byte 0x081F3788  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AB  @ music
	.2byte 0x0042  @ mapLayoutId
	.byte 0x02, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_DEWFORD_TOWN_HOUSE2 (g3 m5)
	.4byte gMapLayout_DEWFORD_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_DEWFORD_TOWN_HOUSE2  @ events
	.4byte 0x081F4008  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AB  @ music
	.2byte 0x0043  @ mapLayoutId
	.byte 0x02, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LAVARIDGE_TOWN_HERB_SHOP (g4 m0)
	.4byte gMapLayout_LAVARIDGE_TOWN_HERB_SHOP  @ mapLayout
	.4byte gMapEvents_LAVARIDGE_TOWN_HERB_SHOP  @ events
	.4byte 0x081F4185  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016B  @ music
	.2byte 0x0044  @ mapLayoutId
	.byte 0x03, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LAVARIDGE_TOWN_GYM_1F (g4 m1)
	.4byte gMapLayout_LAVARIDGE_TOWN_GYM_1F  @ mapLayout
	.4byte gMapEvents_LAVARIDGE_TOWN_GYM_1F  @ events
	.4byte LavaridgeTown_Gym_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016C  @ music
	.2byte 0x0045  @ mapLayoutId
	.byte 0x03, 0x00, 0x06, 0x08, 0x00, 0x00, 0x00, 0x01  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LAVARIDGE_TOWN_GYM_B1F (g4 m2)
	.4byte gMapLayout_LAVARIDGE_TOWN_GYM_B1F  @ mapLayout
	.4byte gMapEvents_LAVARIDGE_TOWN_GYM_B1F  @ events
	.4byte LavaridgeTown_Gym_B1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016C  @ music
	.2byte 0x0046  @ mapLayoutId
	.byte 0x03, 0x00, 0x06, 0x08, 0x00, 0x00, 0x00, 0x01  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LAVARIDGE_TOWN_HOUSE (g4 m3)
	.4byte gMapLayout_DEWFORD_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_LAVARIDGE_TOWN_HOUSE  @ events
	.4byte 0x081F4E4D  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016B  @ music
	.2byte 0x0040  @ mapLayoutId
	.byte 0x03, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LAVARIDGE_TOWN_MART (g4 m4)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte gMapEvents_LAVARIDGE_TOWN_MART  @ events
	.4byte 0x081F4ECC  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x03, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LAVARIDGE_TOWN_POKEMON_CENTER_1F (g4 m5)
	.4byte gMapLayout_LAVARIDGE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_LAVARIDGE_TOWN_POKEMON_CENTER_1F  @ events
	.4byte LavaridgeTown_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x0047  @ mapLayoutId
	.byte 0x03, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LAVARIDGE_TOWN_POKEMON_CENTER_2F (g4 m6)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_LAVARIDGE_TOWN_POKEMON_CENTER_2F  @ events
	.4byte LavaridgeTown_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x03, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FALLARBOR_TOWN_MART (g5 m0)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte gMapEvents_FALLARBOR_TOWN_MART  @ events
	.4byte 0x081F5098  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FALLARBOR_TOWN_BATTLE_TENT_LOBBY (g5 m1)
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_LOBBY  @ mapLayout
	.4byte gMapEvents_FALLARBOR_TOWN_BATTLE_TENT_LOBBY  @ events
	.4byte FallarborTown_BattleTentLobby_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0180  @ music
	.2byte 0x0180  @ mapLayoutId
	.byte 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR (g5 m2)
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR  @ mapLayout
	.4byte gMapEvents_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR  @ events
	.4byte FallarborTown_BattleTentCorridor_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0180  @ music
	.2byte 0x0181  @ mapLayoutId
	.byte 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM (g5 m3)
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM  @ mapLayout
	.4byte gMapEvents_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM  @ events
	.4byte FallarborTown_BattleTentBattleRoom_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0180  @ music
	.2byte 0x0182  @ mapLayoutId
	.byte 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FALLARBOR_TOWN_POKEMON_CENTER_1F (g5 m4)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_FALLARBOR_TOWN_POKEMON_CENTER_1F  @ events
	.4byte FallarborTown_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FALLARBOR_TOWN_POKEMON_CENTER_2F (g5 m5)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_FALLARBOR_TOWN_POKEMON_CENTER_2F  @ events
	.4byte FallarborTown_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FALLARBOR_TOWN_COZMOS_HOUSE (g5 m6)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_FALLARBOR_TOWN_COZMOS_HOUSE  @ events
	.4byte 0x081F5E78  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B5  @ music
	.2byte 0x003B  @ mapLayoutId
	.byte 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FALLARBOR_TOWN_MOVE_RELEARNERS_HOUSE (g5 m7)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_FALLARBOR_TOWN_MOVE_RELEARNERS_HOUSE  @ events
	.4byte 0x081F6155  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B5  @ music
	.2byte 0x003C  @ mapLayoutId
	.byte 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_VERDANTURF_TOWN_BATTLE_TENT_LOBBY (g6 m0)
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_LOBBY  @ mapLayout
	.4byte gMapEvents_VERDANTURF_TOWN_BATTLE_TENT_LOBBY  @ events
	.4byte VerdanturfTown_BattleTentLobby_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0180  @ music
	.2byte 0x0180  @ mapLayoutId
	.byte 0x05, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_VERDANTURF_TOWN_BATTLE_TENT_CORRIDOR (g6 m1)
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR  @ mapLayout
	.4byte gMapEvents_VERDANTURF_TOWN_BATTLE_TENT_CORRIDOR  @ events
	.4byte VerdanturfTown_BattleTentCorridor_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0180  @ music
	.2byte 0x0181  @ mapLayoutId
	.byte 0x05, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM (g6 m2)
	.4byte gMapLayout_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM  @ mapLayout
	.4byte gMapEvents_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM  @ events
	.4byte VerdanturfTown_BattleTentBattleRoom_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0180  @ music
	.2byte 0x0183  @ mapLayoutId
	.byte 0x05, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_VERDANTURF_TOWN_MART (g6 m3)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte gMapEvents_VERDANTURF_TOWN_MART  @ events
	.4byte 0x081F6F27  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x05, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_VERDANTURF_TOWN_POKEMON_CENTER_1F (g6 m4)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_VERDANTURF_TOWN_POKEMON_CENTER_1F  @ events
	.4byte VerdanturfTown_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x05, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_VERDANTURF_TOWN_POKEMON_CENTER_2F (g6 m5)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_VERDANTURF_TOWN_POKEMON_CENTER_2F  @ events
	.4byte VerdanturfTown_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x05, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_VERDANTURF_TOWN_WANDAS_HOUSE (g6 m6)
	.4byte gMapLayout_VERDANTURF_TOWN_WANDAS_HOUSE  @ mapLayout
	.4byte gMapEvents_VERDANTURF_TOWN_WANDAS_HOUSE  @ events
	.4byte 0x081F7105  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018E  @ music
	.2byte 0x004C  @ mapLayoutId
	.byte 0x05, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_VERDANTURF_TOWN_FRIENDSHIP_RATERS_HOUSE (g6 m7)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_VERDANTURF_TOWN_FRIENDSHIP_RATERS_HOUSE  @ events
	.4byte 0x081F7556  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018E  @ music
	.2byte 0x003C  @ mapLayoutId
	.byte 0x05, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_VERDANTURF_TOWN_HOUSE (g6 m8)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_VERDANTURF_TOWN_HOUSE  @ events
	.4byte 0x081F777F  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018E  @ music
	.2byte 0x003B  @ mapLayoutId
	.byte 0x05, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_1F (g7 m0)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_PACIFIDLOG_TOWN_POKEMON_CENTER_1F  @ events
	.4byte PacifidlogTown_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x06, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_2F (g7 m1)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_PACIFIDLOG_TOWN_POKEMON_CENTER_2F  @ events
	.4byte PacifidlogTown_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x06, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PACIFIDLOG_TOWN_HOUSE1 (g7 m2)
	.4byte gMapLayout_PACIFIDLOG_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_PACIFIDLOG_TOWN_HOUSE1  @ events
	.4byte 0x081F793E  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x004D  @ mapLayoutId
	.byte 0x06, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PACIFIDLOG_TOWN_HOUSE2 (g7 m3)
	.4byte gMapLayout_PACIFIDLOG_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_PACIFIDLOG_TOWN_HOUSE2  @ events
	.4byte 0x081F79FF  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x004E  @ mapLayoutId
	.byte 0x06, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PACIFIDLOG_TOWN_HOUSE3 (g7 m4)
	.4byte gMapLayout_PACIFIDLOG_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_PACIFIDLOG_TOWN_HOUSE3  @ events
	.4byte 0x081F7D1A  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x004D  @ mapLayoutId
	.byte 0x06, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PACIFIDLOG_TOWN_HOUSE4 (g7 m5)
	.4byte gMapLayout_PACIFIDLOG_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_PACIFIDLOG_TOWN_HOUSE4  @ events
	.4byte 0x081F7F3D  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x004E  @ mapLayoutId
	.byte 0x06, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PACIFIDLOG_TOWN_HOUSE5 (g7 m6)
	.4byte gMapLayout_PACIFIDLOG_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_PACIFIDLOG_TOWN_HOUSE5  @ events
	.4byte 0x081F8055  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x004D  @ mapLayoutId
	.byte 0x06, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PETALBURG_CITY_WALLYS_HOUSE (g8 m0)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_PETALBURG_CITY_WALLYS_HOUSE  @ events
	.4byte PetalburgCity_WallysHouse_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016A  @ music
	.2byte 0x003C  @ mapLayoutId
	.byte 0x07, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PETALBURG_CITY_GYM (g8 m1)
	.4byte gMapLayout_PETALBURG_CITY_GYM  @ mapLayout
	.4byte gMapEvents_PETALBURG_CITY_GYM  @ events
	.4byte PetalburgCity_Gym_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016C  @ music
	.2byte 0x004F  @ mapLayoutId
	.byte 0x07, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PETALBURG_CITY_HOUSE1 (g8 m2)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_PETALBURG_CITY_HOUSE1  @ events
	.4byte 0x081FA63D  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016A  @ music
	.2byte 0x003B  @ mapLayoutId
	.byte 0x07, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PETALBURG_CITY_HOUSE2 (g8 m3)
	.4byte gMapLayout_PETALBURG_CITY_HOUSE2  @ mapLayout
	.4byte gMapEvents_PETALBURG_CITY_HOUSE2  @ events
	.4byte 0x081FA720  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016A  @ music
	.2byte 0x0050  @ mapLayoutId
	.byte 0x07, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PETALBURG_CITY_POKEMON_CENTER_1F (g8 m4)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_PETALBURG_CITY_POKEMON_CENTER_1F  @ events
	.4byte PetalburgCity_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x07, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PETALBURG_CITY_POKEMON_CENTER_2F (g8 m5)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_PETALBURG_CITY_POKEMON_CENTER_2F  @ events
	.4byte PetalburgCity_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x07, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PETALBURG_CITY_MART (g8 m6)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte gMapEvents_PETALBURG_CITY_MART  @ events
	.4byte 0x081FA9E9  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x07, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_STERNS_SHIPYARD_1F (g9 m0)
	.4byte gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_1F  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_STERNS_SHIPYARD_1F  @ events
	.4byte 0x081FAB28  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B1  @ music
	.2byte 0x0051  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_STERNS_SHIPYARD_2F (g9 m1)
	.4byte gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_2F  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_STERNS_SHIPYARD_2F  @ events
	.4byte 0x081FAFA2  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B1  @ music
	.2byte 0x0052  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_BATTLE_TENT_LOBBY (g9 m2)
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_LOBBY  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_BATTLE_TENT_LOBBY  @ events
	.4byte SlateportCity_BattleTentLobby_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0180  @ music
	.2byte 0x0180  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_BATTLE_TENT_CORRIDOR (g9 m3)
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_BATTLE_TENT_CORRIDOR  @ events
	.4byte SlateportCity_BattleTentCorridor_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0180  @ music
	.2byte 0x0181  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM (g9 m4)
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM  @ events
	.4byte SlateportCity_BattleTentBattleRoom_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0180  @ music
	.2byte 0x0182  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_NAME_RATERS_HOUSE (g9 m5)
	.4byte gMapLayout_PETALBURG_CITY_HOUSE2  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_NAME_RATERS_HOUSE  @ events
	.4byte 0x081FBD9D  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B1  @ music
	.2byte 0x0050  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_POKEMON_FAN_CLUB (g9 m6)
	.4byte gMapLayout_SLATEPORT_CITY_POKEMON_FAN_CLUB  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_POKEMON_FAN_CLUB  @ events
	.4byte 0x081FC027  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B1  @ music
	.2byte 0x0055  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_OCEANIC_MUSEUM_1F (g9 m7)
	.4byte gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_1F  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_OCEANIC_MUSEUM_1F  @ events
	.4byte 0x081FCA3E  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0177  @ music
	.2byte 0x0056  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_OCEANIC_MUSEUM_2F (g9 m8)
	.4byte gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_2F  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_OCEANIC_MUSEUM_2F  @ events
	.4byte 0x081FD309  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0177  @ music
	.2byte 0x0057  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_HARBOR (g9 m9)
	.4byte gMapLayout_SLATEPORT_CITY_HARBOR  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_HARBOR  @ events
	.4byte SlateportCity_Harbor_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B1  @ music
	.2byte 0x0058  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_HOUSE (g9 m10)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_HOUSE  @ events
	.4byte 0x081FE772  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B1  @ music
	.2byte 0x003C  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_POKEMON_CENTER_1F (g9 m11)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_POKEMON_CENTER_1F  @ events
	.4byte SlateportCity_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_POKEMON_CENTER_2F (g9 m12)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_POKEMON_CENTER_2F  @ events
	.4byte SlateportCity_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_MART (g9 m13)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_MART  @ events
	.4byte 0x081FE8F9  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MAUVILLE_CITY_GYM (g10 m0)
	.4byte gMapLayout_MAUVILLE_CITY_GYM  @ mapLayout
	.4byte gMapEvents_MAUVILLE_CITY_GYM  @ events
	.4byte MauvilleCity_Gym_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016C  @ music
	.2byte 0x0059  @ mapLayoutId
	.byte 0x09, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MAUVILLE_CITY_BIKE_SHOP (g10 m1)
	.4byte gMapLayout_MAUVILLE_CITY_BIKE_SHOP  @ mapLayout
	.4byte gMapEvents_MAUVILLE_CITY_BIKE_SHOP  @ events
	.4byte 0x081FF3EB  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x005A  @ mapLayoutId
	.byte 0x09, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MAUVILLE_CITY_HOUSE1 (g10 m2)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_MAUVILLE_CITY_HOUSE1  @ events
	.4byte 0x081FFD77  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x003C  @ mapLayoutId
	.byte 0x09, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MAUVILLE_CITY_GAME_CORNER (g10 m3)
	.4byte gMapLayout_MAUVILLE_CITY_GAME_CORNER  @ mapLayout
	.4byte gMapEvents_MAUVILLE_CITY_GAME_CORNER  @ events
	.4byte 0x081FFEE7  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AA  @ music
	.2byte 0x005B  @ mapLayoutId
	.byte 0x09, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MAUVILLE_CITY_HOUSE2 (g10 m4)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_MAUVILLE_CITY_HOUSE2  @ events
	.4byte 0x08200C5A  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x003B  @ mapLayoutId
	.byte 0x09, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MAUVILLE_CITY_POKEMON_CENTER_1F (g10 m5)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_MAUVILLE_CITY_POKEMON_CENTER_1F  @ events
	.4byte MauvilleCity_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x09, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MAUVILLE_CITY_POKEMON_CENTER_2F (g10 m6)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_MAUVILLE_CITY_POKEMON_CENTER_2F  @ events
	.4byte MauvilleCity_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x09, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MAUVILLE_CITY_MART (g10 m7)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte gMapEvents_MAUVILLE_CITY_MART  @ events
	.4byte 0x08200F4F  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x09, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_DEVON_CORP_1F (g11 m0)
	.4byte gMapLayout_RUSTBORO_CITY_DEVON_CORP_1F  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_DEVON_CORP_1F  @ events
	.4byte RustboroCity_DevonCorp_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x005C  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_DEVON_CORP_2F (g11 m1)
	.4byte gMapLayout_RUSTBORO_CITY_DEVON_CORP_2F  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_DEVON_CORP_2F  @ events
	.4byte RustboroCity_DevonCorp_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x005D  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_DEVON_CORP_3F (g11 m2)
	.4byte gMapLayout_RUSTBORO_CITY_DEVON_CORP_3F  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_DEVON_CORP_3F  @ events
	.4byte RustboroCity_DevonCorp_3F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x010D  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_GYM (g11 m3)
	.4byte gMapLayout_RUSTBORO_CITY_GYM  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_GYM  @ events
	.4byte 0x082022C5  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016C  @ music
	.2byte 0x005E  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_POKEMON_SCHOOL (g11 m4)
	.4byte gMapLayout_RUSTBORO_CITY_POKEMON_SCHOOL  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_POKEMON_SCHOOL  @ events
	.4byte 0x08202C1A  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B3  @ music
	.2byte 0x005F  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_POKEMON_CENTER_1F (g11 m5)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_POKEMON_CENTER_1F  @ events
	.4byte RustboroCity_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_POKEMON_CENTER_2F (g11 m6)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_POKEMON_CENTER_2F  @ events
	.4byte RustboroCity_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_MART (g11 m7)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_MART  @ events
	.4byte 0x082035E0  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_FLAT1_1F (g11 m8)
	.4byte gMapLayout_RUSTBORO_CITY_FLAT1_1F  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_FLAT1_1F  @ events
	.4byte 0x08203714  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0139  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_FLAT1_2F (g11 m9)
	.4byte gMapLayout_RUSTBORO_CITY_FLAT1_2F  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_FLAT1_2F  @ events
	.4byte 0x08203770  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x013A  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_HOUSE1 (g11 m10)
	.4byte gMapLayout_RUSTBORO_CITY_HOUSE1  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_HOUSE1  @ events
	.4byte 0x08203BC8  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0061  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_CUTTERS_HOUSE (g11 m11)
	.4byte gMapLayout_RUSTBORO_CITY_CUTTERS_HOUSE  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_CUTTERS_HOUSE  @ events
	.4byte 0x08203D7C  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0062  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_HOUSE2 (g11 m12)
	.4byte gMapLayout_RUSTBORO_CITY_HOUSE2  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_HOUSE2  @ events
	.4byte 0x08203F15  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0060  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_FLAT2_1F (g11 m13)
	.4byte gMapLayout_RUSTBORO_CITY_FLAT2_1F  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_FLAT2_1F  @ events
	.4byte 0x08203F99  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0126  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_FLAT2_2F (g11 m14)
	.4byte gMapLayout_RUSTBORO_CITY_FLAT2_2F  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_FLAT2_2F  @ events
	.4byte 0x08203FE8  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0127  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_FLAT2_3F (g11 m15)
	.4byte gMapLayout_RUSTBORO_CITY_FLAT2_3F  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_FLAT2_3F  @ events
	.4byte 0x082040B5  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0128  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_HOUSE3 (g11 m16)
	.4byte gMapLayout_RUSTBORO_CITY_HOUSE2  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_HOUSE3  @ events
	.4byte 0x08204117  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0060  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FORTREE_CITY_HOUSE1 (g12 m0)
	.4byte gMapLayout_FORTREE_CITY_HOUSE1  @ mapLayout
	.4byte gMapEvents_FORTREE_CITY_HOUSE1  @ events
	.4byte 0x082041CA  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x017E  @ music
	.2byte 0x0063  @ mapLayoutId
	.byte 0x0B, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FORTREE_CITY_GYM (g12 m1)
	.4byte gMapLayout_FORTREE_CITY_GYM  @ mapLayout
	.4byte gMapEvents_FORTREE_CITY_GYM  @ events
	.4byte FortreeCity_Gym_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016C  @ music
	.2byte 0x0064  @ mapLayoutId
	.byte 0x0B, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FORTREE_CITY_POKEMON_CENTER_1F (g12 m2)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_FORTREE_CITY_POKEMON_CENTER_1F  @ events
	.4byte FortreeCity_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x0B, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FORTREE_CITY_POKEMON_CENTER_2F (g12 m3)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_FORTREE_CITY_POKEMON_CENTER_2F  @ events
	.4byte FortreeCity_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x0B, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FORTREE_CITY_MART (g12 m4)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte gMapEvents_FORTREE_CITY_MART  @ events
	.4byte 0x08204DBD  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x0B, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FORTREE_CITY_HOUSE2 (g12 m5)
	.4byte gMapLayout_FORTREE_CITY_HOUSE2  @ mapLayout
	.4byte gMapEvents_FORTREE_CITY_HOUSE2  @ events
	.4byte 0x08204E9B  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x017E  @ music
	.2byte 0x0065  @ mapLayoutId
	.byte 0x0B, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FORTREE_CITY_HOUSE3 (g12 m6)
	.4byte gMapLayout_FORTREE_CITY_HOUSE1  @ mapLayout
	.4byte gMapEvents_FORTREE_CITY_HOUSE3  @ events
	.4byte 0x082050D0  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x017E  @ music
	.2byte 0x0063  @ mapLayoutId
	.byte 0x0B, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FORTREE_CITY_HOUSE4 (g12 m7)
	.4byte gMapLayout_FORTREE_CITY_HOUSE2  @ mapLayout
	.4byte gMapEvents_FORTREE_CITY_HOUSE4  @ events
	.4byte 0x082051A2  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x017E  @ music
	.2byte 0x0065  @ mapLayoutId
	.byte 0x0B, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FORTREE_CITY_HOUSE5 (g12 m8)
	.4byte gMapLayout_FORTREE_CITY_HOUSE1  @ mapLayout
	.4byte gMapEvents_FORTREE_CITY_HOUSE5  @ events
	.4byte 0x08205343  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x017E  @ music
	.2byte 0x0063  @ mapLayoutId
	.byte 0x0B, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FORTREE_CITY_DECORATION_SHOP (g12 m9)
	.4byte gMapLayout_FORTREE_CITY_DECORATION_SHOP  @ mapLayout
	.4byte gMapEvents_FORTREE_CITY_DECORATION_SHOP  @ events
	.4byte 0x082053F0  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x017E  @ music
	.2byte 0x00FF  @ mapLayoutId
	.byte 0x0B, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_COVE_LILY_MOTEL_1F (g13 m0)
	.4byte gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_1F  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_COVE_LILY_MOTEL_1F  @ events
	.4byte 0x082054FC  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x012B  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_COVE_LILY_MOTEL_2F (g13 m1)
	.4byte gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_2F  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_COVE_LILY_MOTEL_2F  @ events
	.4byte 0x08205887  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x012C  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F (g13 m2)
	.4byte gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F  @ events
	.4byte 0x08205BE2  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0175  @ music
	.2byte 0x0067  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F (g13 m3)
	.4byte gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F  @ events
	.4byte LilycoveCity_LilycoveMuseum_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0175  @ music
	.2byte 0x0068  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_CONTEST_LOBBY (g13 m4)
	.4byte gMapLayout_LILYCOVE_CITY_CONTEST_LOBBY  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_CONTEST_LOBBY  @ events
	.4byte LilycoveCity_ContestLobby_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01C4  @ music
	.2byte 0x0069  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_CONTEST_HALL (g13 m5)
	.4byte gMapLayout_LILYCOVE_CITY_CONTEST_HALL  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_CONTEST_HALL  @ events
	.4byte 0x082077B9  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01C4  @ music
	.2byte 0x006A  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_POKEMON_CENTER_1F (g13 m6)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_POKEMON_CENTER_1F  @ events
	.4byte LilycoveCity_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_POKEMON_CENTER_2F (g13 m7)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_POKEMON_CENTER_2F  @ events
	.4byte LilycoveCity_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_UNUSED_MART (g13 m8)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_UNUSED_MART  @ events
	.4byte 0x0820839D  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB (g13 m9)
	.4byte gMapLayout_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB  @ events
	.4byte LilycoveCity_PokemonTrainerFanClub_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x006B  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_HARBOR (g13 m10)
	.4byte gMapLayout_SLATEPORT_CITY_HARBOR  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_HARBOR  @ events
	.4byte LilycoveCity_Harbor_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x0058  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_MOVE_DELETERS_HOUSE (g13 m11)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_MOVE_DELETERS_HOUSE  @ events
	.4byte 0x08209D70  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x003C  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_HOUSE1 (g13 m12)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_HOUSE1  @ events
	.4byte 0x08209F66  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x003B  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_HOUSE2 (g13 m13)
	.4byte gMapLayout_LILYCOVE_CITY_HOUSE2  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_HOUSE2  @ events
	.4byte 0x08209FDC  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x004A  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_HOUSE3 (g13 m14)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_HOUSE3  @ events
	.4byte LilycoveCity_House3_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x003C  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_HOUSE4 (g13 m15)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_HOUSE4  @ events
	.4byte 0x0820A51A  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x003B  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_DEPARTMENT_STORE_1F (g13 m16)
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_1F  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_1F  @ events
	.4byte 0x0820A5AF  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x0101  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_DEPARTMENT_STORE_2F (g13 m17)
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_2F  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_2F  @ events
	.4byte 0x0820A920  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x0102  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_DEPARTMENT_STORE_3F (g13 m18)
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_3F  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_3F  @ events
	.4byte 0x0820AA19  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x0103  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_DEPARTMENT_STORE_4F (g13 m19)
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_4F  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_4F  @ events
	.4byte 0x0820AB4E  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x0104  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_DEPARTMENT_STORE_5F (g13 m20)
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_5F  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_5F  @ events
	.4byte LilycoveCity_DepartmentStore_5F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x0105  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP (g13 m21)
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP  @ events
	.4byte LilycoveCity_DepartmentStoreRooftop_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x0106  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR (g13 m22)
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR  @ events
	.4byte 0x0820B18C  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x0111  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_GYM (g14 m0)
	.4byte gMapLayout_MOSSDEEP_CITY_GYM  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_GYM  @ events
	.4byte MossdeepCity_Gym_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016C  @ music
	.2byte 0x006C  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_HOUSE1 (g14 m1)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_HOUSE1  @ events
	.4byte 0x0820C332  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x003C  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_HOUSE2 (g14 m2)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_HOUSE2  @ events
	.4byte 0x0820C3D2  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x003B  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_POKEMON_CENTER_1F (g14 m3)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_POKEMON_CENTER_1F  @ events
	.4byte MossdeepCity_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_POKEMON_CENTER_2F (g14 m4)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_POKEMON_CENTER_2F  @ events
	.4byte MossdeepCity_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_MART (g14 m5)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_MART  @ events
	.4byte 0x0820C5B2  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_HOUSE3 (g14 m6)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_HOUSE3  @ events
	.4byte 0x0820C6FA  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x003C  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_STEVENS_HOUSE (g14 m7)
	.4byte gMapLayout_MOSSDEEP_CITY_STEVENS_HOUSE  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_STEVENS_HOUSE  @ events
	.4byte MossdeepCity_StevensHouse_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0147  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_HOUSE4 (g14 m8)
	.4byte gMapLayout_PETALBURG_CITY_HOUSE2  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_HOUSE4  @ events
	.4byte 0x0820CC5B  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0050  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_SPACE_CENTER_1F (g14 m9)
	.4byte gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_1F  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_SPACE_CENTER_1F  @ events
	.4byte MossdeepCity_SpaceCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0113  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_SPACE_CENTER_2F (g14 m10)
	.4byte gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_2F  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_SPACE_CENTER_2F  @ events
	.4byte MossdeepCity_SpaceCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0114  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_GAME_CORNER_1F (g14 m11)
	.4byte gMapLayout_MOSSDEEP_CITY_GAME_CORNER_1F  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_GAME_CORNER_1F  @ events
	.4byte MossdeepCity_GameCorner_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0131  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_GAME_CORNER_B1F (g14 m12)
	.4byte gMapLayout_MOSSDEEP_CITY_GAME_CORNER_B1F  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_GAME_CORNER_B1F  @ events
	.4byte 0x0820E223  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0132  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_GYM_1F (g15 m0)
	.4byte gMapLayout_SOOTOPOLIS_CITY_GYM_1F  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_GYM_1F  @ events
	.4byte SootopolisCity_Gym_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016C  @ music
	.2byte 0x006D  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_GYM_B1F (g15 m1)
	.4byte gMapLayout_SOOTOPOLIS_CITY_GYM_B1F  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_GYM_B1F  @ events
	.4byte 0x0820EAC6  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016C  @ music
	.2byte 0x006E  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_1F (g15 m2)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_POKEMON_CENTER_1F  @ events
	.4byte SootopolisCity_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_2F (g15 m3)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_POKEMON_CENTER_2F  @ events
	.4byte SootopolisCity_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_MART (g15 m4)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_MART  @ events
	.4byte 0x0820F1B7  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_HOUSE1 (g15 m5)
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE1  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_HOUSE1  @ events
	.4byte 0x0820F300  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01BD  @ music
	.2byte 0x0133  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_HOUSE2 (g15 m6)
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE2  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_HOUSE2  @ events
	.4byte 0x0820F3C6  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01BD  @ music
	.2byte 0x0134  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_HOUSE3 (g15 m7)
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE3  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_HOUSE3  @ events
	.4byte 0x0820F479  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01BD  @ music
	.2byte 0x0135  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_HOUSE4 (g15 m8)
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE1  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_HOUSE4  @ events
	.4byte 0x0820F593  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01BD  @ music
	.2byte 0x0133  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_HOUSE5 (g15 m9)
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE2  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_HOUSE5  @ events
	.4byte 0x0820F657  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01BD  @ music
	.2byte 0x0134  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_HOUSE6 (g15 m10)
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE3  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_HOUSE6  @ events
	.4byte 0x0820F6D0  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01BD  @ music
	.2byte 0x0135  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_HOUSE7 (g15 m11)
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE1  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_HOUSE7  @ events
	.4byte 0x0820F7BA  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01BD  @ music
	.2byte 0x0133  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE (g15 m12)
	.4byte gMapLayout_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE  @ events
	.4byte 0x0820F861  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01BD  @ music
	.2byte 0x0129  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F (g15 m13)
	.4byte gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F  @ events
	.4byte SootopolisCity_MysteryEventsHouse_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01BD  @ music
	.2byte 0x01B7  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F (g15 m14)
	.4byte gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F  @ events
	.4byte SootopolisCity_MysteryEventsHouse_B1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01BD  @ music
	.2byte 0x01B8  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_SIDNEYS_ROOM (g16 m0)
	.4byte gMapLayout_EVER_GRANDE_CITY_SIDNEYS_ROOM  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_SIDNEYS_ROOM  @ events
	.4byte EverGrandeCity_SidneysRoom_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AD  @ music
	.2byte 0x006F  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x04  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_PHOEBES_ROOM (g16 m1)
	.4byte gMapLayout_EVER_GRANDE_CITY_PHOEBES_ROOM  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_PHOEBES_ROOM  @ events
	.4byte EverGrandeCity_PhoebesRoom_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AD  @ music
	.2byte 0x0070  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x05  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_GLACIAS_ROOM (g16 m2)
	.4byte gMapLayout_EVER_GRANDE_CITY_GLACIAS_ROOM  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_GLACIAS_ROOM  @ events
	.4byte EverGrandeCity_GlaciasRoom_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AD  @ music
	.2byte 0x0071  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x06  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_DRAKES_ROOM (g16 m3)
	.4byte gMapLayout_EVER_GRANDE_CITY_DRAKES_ROOM  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_DRAKES_ROOM  @ events
	.4byte EverGrandeCity_DrakesRoom_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AD  @ music
	.2byte 0x0072  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x07  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_CHAMPIONS_ROOM (g16 m4)
	.4byte gMapLayout_EVER_GRANDE_CITY_CHAMPIONS_ROOM  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_CHAMPIONS_ROOM  @ events
	.4byte EverGrandeCity_ChampionsRoom_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AD  @ music
	.2byte 0x0073  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_HALL1 (g16 m5)
	.4byte gMapLayout_EVER_GRANDE_CITY_HALL1  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_HALL1  @ events
	.4byte EverGrandeCity_Hall1_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AD  @ music
	.2byte 0x0074  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_HALL2 (g16 m6)
	.4byte gMapLayout_EVER_GRANDE_CITY_HALL1  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_HALL2  @ events
	.4byte EverGrandeCity_Hall2_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AD  @ music
	.2byte 0x0074  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_HALL3 (g16 m7)
	.4byte gMapLayout_EVER_GRANDE_CITY_HALL1  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_HALL3  @ events
	.4byte EverGrandeCity_Hall3_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AD  @ music
	.2byte 0x0074  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_HALL4 (g16 m8)
	.4byte gMapLayout_EVER_GRANDE_CITY_HALL4  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_HALL4  @ events
	.4byte EverGrandeCity_Hall4_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AD  @ music
	.2byte 0x013B  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_HALL5 (g16 m9)
	.4byte gMapLayout_EVER_GRANDE_CITY_HALL1  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_HALL5  @ events
	.4byte EverGrandeCity_Hall5_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AD  @ music
	.2byte 0x0074  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F (g16 m10)
	.4byte gMapLayout_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F  @ events
	.4byte EverGrandeCity_PokemonLeague_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x010E  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_HALL_OF_FAME (g16 m11)
	.4byte gMapLayout_EVER_GRANDE_CITY_HALL_OF_FAME  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_HALL_OF_FAME  @ events
	.4byte EverGrandeCity_HallOfFame_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01BF  @ music
	.2byte 0x012A  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_POKEMON_CENTER_1F (g16 m12)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_POKEMON_CENTER_1F  @ events
	.4byte EverGrandeCity_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_POKEMON_CENTER_2F (g16 m13)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_POKEMON_CENTER_2F  @ events
	.4byte EverGrandeCity_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_2F (g16 m14)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_POKEMON_LEAGUE_2F  @ events
	.4byte EverGrandeCity_PokemonLeague_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE104_MR_BRINEYS_HOUSE (g17 m0)
	.4byte gMapLayout_ROUTE104_MR_BRINEYS_HOUSE  @ mapLayout
	.4byte gMapEvents_ROUTE104_MR_BRINEYS_HOUSE  @ events
	.4byte Route104_MrBrineysHouse_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016A  @ music
	.2byte 0x0066  @ mapLayoutId
	.byte 0x13, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE104_PRETTY_PETAL_FLOWER_SHOP (g17 m1)
	.4byte gMapLayout_ROUTE104_PRETTY_PETAL_FLOWER_SHOP  @ mapLayout
	.4byte gMapEvents_ROUTE104_PRETTY_PETAL_FLOWER_SHOP  @ events
	.4byte Route104_PrettyPetalFlowerShop_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016A  @ music
	.2byte 0x0075  @ mapLayoutId
	.byte 0x13, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE111_WINSTRATE_FAMILYS_HOUSE (g18 m0)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_ROUTE111_WINSTRATE_FAMILYS_HOUSE  @ events
	.4byte 0x08211AF4  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x003C  @ mapLayoutId
	.byte 0x1A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE111_OLD_LADYS_REST_STOP (g18 m1)
	.4byte gMapLayout_DEWFORD_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_ROUTE111_OLD_LADYS_REST_STOP  @ events
	.4byte Route111_OldLadysRestStop_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0040  @ mapLayoutId
	.byte 0x1A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE112_CABLE_CAR_STATION (g19 m0)
	.4byte gMapLayout_ROUTE112_CABLE_CAR_STATION  @ mapLayout
	.4byte gMapEvents_ROUTE112_CABLE_CAR_STATION  @ events
	.4byte Route112_CableCarStation_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0168  @ music
	.2byte 0x0076  @ mapLayoutId
	.byte 0x1B, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MT_CHIMNEY_CABLE_CAR_STATION (g19 m1)
	.4byte gMapLayout_ROUTE112_CABLE_CAR_STATION  @ mapLayout
	.4byte gMapEvents_MT_CHIMNEY_CABLE_CAR_STATION  @ events
	.4byte MtChimney_CableCarStation_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0168  @ music
	.2byte 0x0076  @ mapLayoutId
	.byte 0x38, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE114_FOSSIL_MANIACS_HOUSE (g20 m0)
	.4byte gMapLayout_ROUTE114_FOSSIL_MANIACS_HOUSE  @ mapLayout
	.4byte gMapEvents_ROUTE114_FOSSIL_MANIACS_HOUSE  @ events
	.4byte Route114_FossilManiacsHouse_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B5  @ music
	.2byte 0x0077  @ mapLayoutId
	.byte 0x1D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE114_FOSSIL_MANIACS_TUNNEL (g20 m1)
	.4byte gMapLayout_ROUTE114_FOSSIL_MANIACS_TUNNEL  @ mapLayout
	.4byte gMapEvents_ROUTE114_FOSSIL_MANIACS_TUNNEL  @ events
	.4byte Route114_FossilManiacsTunnel_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B5  @ music
	.2byte 0x0078  @ mapLayoutId
	.byte 0x1D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE114_LANETTES_HOUSE (g20 m2)
	.4byte gMapLayout_ROUTE114_LANETTES_HOUSE  @ mapLayout
	.4byte gMapEvents_ROUTE114_LANETTES_HOUSE  @ events
	.4byte Route114_LanettesHouse_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B5  @ music
	.2byte 0x0079  @ mapLayoutId
	.byte 0x1D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE116_TUNNELERS_REST_HOUSE (g21 m0)
	.4byte gMapLayout_ROUTE116_TUNNELERS_REST_HOUSE  @ mapLayout
	.4byte gMapEvents_ROUTE116_TUNNELERS_REST_HOUSE  @ events
	.4byte Route116_TunnelersRestHouse_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x007A  @ mapLayoutId
	.byte 0x1F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE117_POKEMON_DAY_CARE (g22 m0)
	.4byte gMapLayout_ROUTE117_POKEMON_DAY_CARE  @ mapLayout
	.4byte gMapEvents_ROUTE117_POKEMON_DAY_CARE  @ events
	.4byte Route117_PokemonDayCare_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x007B  @ mapLayoutId
	.byte 0x20, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE121_SAFARI_ZONE_ENTRANCE (g23 m0)
	.4byte gMapLayout_ROUTE121_SAFARI_ZONE_ENTRANCE  @ mapLayout
	.4byte gMapEvents_ROUTE121_SAFARI_ZONE_ENTRANCE  @ events
	.4byte Route121_SafariZoneEntrance_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x017E  @ music
	.2byte 0x007C  @ mapLayoutId
	.byte 0x24, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_METEOR_FALLS_1F_1R (g24 m0)
	.4byte gMapLayout_METEOR_FALLS_1F_1R  @ mapLayout
	.4byte gMapEvents_METEOR_FALLS_1F_1R  @ events
	.4byte MeteorFalls_1F_1R_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0182  @ music
	.2byte 0x007D  @ mapLayoutId
	.byte 0x3F, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_METEOR_FALLS_1F_2R (g24 m1)
	.4byte gMapLayout_METEOR_FALLS_1F_2R  @ mapLayout
	.4byte gMapEvents_METEOR_FALLS_1F_2R  @ events
	.4byte 0x08213079  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0182  @ music
	.2byte 0x007E  @ mapLayoutId
	.byte 0x3F, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_METEOR_FALLS_B1F_1R (g24 m2)
	.4byte gMapLayout_METEOR_FALLS_B1F_1R  @ mapLayout
	.4byte gMapEvents_METEOR_FALLS_B1F_1R  @ events
	.4byte 0x082135EE  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0182  @ music
	.2byte 0x007F  @ mapLayoutId
	.byte 0x3F, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_METEOR_FALLS_B1F_2R (g24 m3)
	.4byte gMapLayout_METEOR_FALLS_B1F_2R  @ mapLayout
	.4byte gMapEvents_METEOR_FALLS_B1F_2R  @ events
	.4byte 0x082135EF  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0182  @ music
	.2byte 0x0080  @ mapLayoutId
	.byte 0x3F, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTURF_TUNNEL (g24 m4)
	.4byte gMapLayout_RUSTURF_TUNNEL  @ mapLayout
	.4byte gMapEvents_RUSTURF_TUNNEL  @ events
	.4byte RusturfTunnel_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016E  @ music
	.2byte 0x0081  @ mapLayoutId
	.byte 0x3C, 0x00, 0x06, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_UNDERWATER_SOOTOPOLIS_CITY (g24 m5)
	.4byte gMapLayout_UNDERWATER_SOOTOPOLIS_CITY  @ mapLayout
	.4byte gMapEvents_UNDERWATER_SOOTOPOLIS_CITY  @ events
	.4byte Underwater_SootopolisCity_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x019B  @ music
	.2byte 0x0082  @ mapLayoutId
	.byte 0x36, 0x00, 0x0E, 0x05, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_DESERT_RUINS (g24 m6)
	.4byte gMapLayout_DESERT_RUINS  @ mapLayout
	.4byte gMapEvents_DESERT_RUINS  @ events
	.4byte DesertRuins_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B6  @ music
	.2byte 0x0083  @ mapLayoutId
	.byte 0x52, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_GRANITE_CAVE_1F (g24 m7)
	.4byte gMapLayout_GRANITE_CAVE_1F  @ mapLayout
	.4byte gMapEvents_GRANITE_CAVE_1F  @ events
	.4byte 0x08213EE1  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016E  @ music
	.2byte 0x0084  @ mapLayoutId
	.byte 0x37, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_GRANITE_CAVE_B1F (g24 m8)
	.4byte gMapLayout_GRANITE_CAVE_B1F  @ mapLayout
	.4byte gMapEvents_GRANITE_CAVE_B1F  @ events
	.4byte GraniteCave_B1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016E  @ music
	.2byte 0x0085  @ mapLayoutId
	.byte 0x37, 0x01, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_GRANITE_CAVE_B2F (g24 m9)
	.4byte gMapLayout_GRANITE_CAVE_B2F  @ mapLayout
	.4byte gMapEvents_GRANITE_CAVE_B2F  @ events
	.4byte 0x08214026  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016E  @ music
	.2byte 0x0086  @ mapLayoutId
	.byte 0x37, 0x01, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_GRANITE_CAVE_STEVENS_ROOM (g24 m10)
	.4byte gMapLayout_GRANITE_CAVE_STEVENS_ROOM  @ mapLayout
	.4byte gMapEvents_GRANITE_CAVE_STEVENS_ROOM  @ events
	.4byte 0x08214027  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016E  @ music
	.2byte 0x0120  @ mapLayoutId
	.byte 0x37, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PETALBURG_WOODS (g24 m11)
	.4byte gMapLayout_PETALBURG_WOODS  @ mapLayout
	.4byte gMapEvents_PETALBURG_WOODS  @ events
	.4byte 0x08214278  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016E  @ music
	.2byte 0x0087  @ mapLayoutId
	.byte 0x3B, 0x00, 0x0B, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MT_CHIMNEY (g24 m12)
	.4byte gMapLayout_MT_CHIMNEY  @ mapLayout
	.4byte gMapEvents_MT_CHIMNEY  @ events
	.4byte MtChimney_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0196  @ music
	.2byte 0x0088  @ mapLayoutId
	.byte 0x38, 0x00, 0x07, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_JAGGED_PASS (g24 m13)
	.4byte gMapLayout_JAGGED_PASS  @ mapLayout
	.4byte gMapEvents_JAGGED_PASS  @ events
	.4byte JaggedPass_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016E  @ music
	.2byte 0x0124  @ mapLayoutId
	.byte 0x4C, 0x00, 0x00, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FIERY_PATH (g24 m14)
	.4byte gMapLayout_FIERY_PATH  @ mapLayout
	.4byte gMapEvents_FIERY_PATH  @ events
	.4byte FieryPath_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016E  @ music
	.2byte 0x0125  @ mapLayoutId
	.byte 0x4A, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MT_PYRE_1F (g24 m15)
	.4byte gMapLayout_MT_PYRE_1F  @ mapLayout
	.4byte gMapEvents_MT_PYRE_1F  @ events
	.4byte 0x08216119  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B0  @ music
	.2byte 0x0089  @ mapLayoutId
	.byte 0x41, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MT_PYRE_2F (g24 m16)
	.4byte gMapLayout_MT_PYRE_2F  @ mapLayout
	.4byte gMapEvents_MT_PYRE_2F  @ events
	.4byte MtPyre_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B0  @ music
	.2byte 0x008A  @ mapLayoutId
	.byte 0x41, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MT_PYRE_3F (g24 m17)
	.4byte gMapLayout_MT_PYRE_3F  @ mapLayout
	.4byte gMapEvents_MT_PYRE_3F  @ events
	.4byte 0x082165F1  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B0  @ music
	.2byte 0x008B  @ mapLayoutId
	.byte 0x41, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MT_PYRE_4F (g24 m18)
	.4byte gMapLayout_MT_PYRE_4F  @ mapLayout
	.4byte gMapEvents_MT_PYRE_4F  @ events
	.4byte 0x08216880  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B0  @ music
	.2byte 0x008C  @ mapLayoutId
	.byte 0x41, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MT_PYRE_5F (g24 m19)
	.4byte gMapLayout_MT_PYRE_5F  @ mapLayout
	.4byte gMapEvents_MT_PYRE_5F  @ events
	.4byte 0x082168FA  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B0  @ music
	.2byte 0x008D  @ mapLayoutId
	.byte 0x41, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MT_PYRE_6F (g24 m20)
	.4byte gMapLayout_MT_PYRE_6F  @ mapLayout
	.4byte gMapEvents_MT_PYRE_6F  @ events
	.4byte 0x08216986  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B0  @ music
	.2byte 0x008E  @ mapLayoutId
	.byte 0x41, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MT_PYRE_EXTERIOR (g24 m21)
	.4byte gMapLayout_MT_PYRE_EXTERIOR  @ mapLayout
	.4byte gMapEvents_MT_PYRE_EXTERIOR  @ events
	.4byte MtPyre_Exterior_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B2  @ music
	.2byte 0x012E  @ mapLayoutId
	.byte 0x41, 0x00, 0x00, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MT_PYRE_SUMMIT (g24 m22)
	.4byte gMapLayout_MT_PYRE_SUMMIT  @ mapLayout
	.4byte gMapEvents_MT_PYRE_SUMMIT  @ events
	.4byte MtPyre_Summit_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B2  @ music
	.2byte 0x012F  @ mapLayoutId
	.byte 0x41, 0x00, 0x06, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_AQUA_HIDEOUT_1F (g24 m23)
	.4byte gMapLayout_AQUA_HIDEOUT_1F  @ mapLayout
	.4byte gMapEvents_AQUA_HIDEOUT_1F  @ events
	.4byte 0x08217935  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AE  @ music
	.2byte 0x008F  @ mapLayoutId
	.byte 0xC5, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x03  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_AQUA_HIDEOUT_B1F (g24 m24)
	.4byte gMapLayout_AQUA_HIDEOUT_B1F  @ mapLayout
	.4byte gMapEvents_AQUA_HIDEOUT_B1F  @ events
	.4byte AquaHideout_B1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AE  @ music
	.2byte 0x0090  @ mapLayoutId
	.byte 0xC5, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x03  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_AQUA_HIDEOUT_B2F (g24 m25)
	.4byte gMapLayout_AQUA_HIDEOUT_B2F  @ mapLayout
	.4byte gMapEvents_AQUA_HIDEOUT_B2F  @ events
	.4byte AquaHideout_B2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AE  @ music
	.2byte 0x0091  @ mapLayoutId
	.byte 0xC5, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x03  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_UNDERWATER_SEAFLOOR_CAVERN (g24 m26)
	.4byte gMapLayout_UNDERWATER_SEAFLOOR_CAVERN  @ mapLayout
	.4byte gMapEvents_UNDERWATER_SEAFLOOR_CAVERN  @ events
	.4byte Underwater_SeafloorCavern_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x019B  @ music
	.2byte 0x0092  @ mapLayoutId
	.byte 0x45, 0x00, 0x0E, 0x05, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SEAFLOOR_CAVERN_ENTRANCE (g24 m27)
	.4byte gMapLayout_SEAFLOOR_CAVERN_ENTRANCE  @ mapLayout
	.4byte gMapEvents_SEAFLOOR_CAVERN_ENTRANCE  @ events
	.4byte SeafloorCavern_Entrance_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0196  @ music
	.2byte 0x0093  @ mapLayoutId
	.byte 0x44, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SEAFLOOR_CAVERN_ROOM1 (g24 m28)
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM1  @ mapLayout
	.4byte gMapEvents_SEAFLOOR_CAVERN_ROOM1  @ events
	.4byte 0x0821865E  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0196  @ music
	.2byte 0x0094  @ mapLayoutId
	.byte 0x44, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SEAFLOOR_CAVERN_ROOM2 (g24 m29)
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM2  @ mapLayout
	.4byte gMapEvents_SEAFLOOR_CAVERN_ROOM2  @ events
	.4byte 0x0821873D  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0196  @ music
	.2byte 0x0095  @ mapLayoutId
	.byte 0x44, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SEAFLOOR_CAVERN_ROOM3 (g24 m30)
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM3  @ mapLayout
	.4byte gMapEvents_SEAFLOOR_CAVERN_ROOM3  @ events
	.4byte 0x0821873E  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0196  @ music
	.2byte 0x0096  @ mapLayoutId
	.byte 0x44, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SEAFLOOR_CAVERN_ROOM4 (g24 m31)
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM4  @ mapLayout
	.4byte gMapEvents_SEAFLOOR_CAVERN_ROOM4  @ events
	.4byte 0x0821892E  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0196  @ music
	.2byte 0x0097  @ mapLayoutId
	.byte 0x44, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	.globl gUnknown_845C660
gUnknown_845C660: @ 0x0845C660
	.incbin "baserom_jp.gba", 0x45c660, 0x2338

	.globl gUnknown_845E998
gUnknown_845E998: @ 0x845E998
	.globl gUnknown_845E998
gUnknown_845E998: @ 0x0845E998
	.incbin "baserom_jp.gba", 0x45E998, 0x88
	.globl LITTLEROOT_TOWN_MapConnections
LITTLEROOT_TOWN_MapConnections: @ 0x0845EA20
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 16, 0x00, 0x00  @ mapGroup, mapNum (0x0010)
	.globl gMapConnections_LITTLEROOT_TOWN
gMapConnections_LITTLEROOT_TOWN: @ 0x0845EA2C
	.4byte 1  @ count
	.4byte LITTLEROOT_TOWN_MapConnections  @ connections
	.globl OLDALE_TOWN_MapConnections
OLDALE_TOWN_MapConnections: @ 0x0845EA34
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 18, 0x00, 0x00  @ mapGroup, mapNum (0x0012)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 16, 0x00, 0x00  @ mapGroup, mapNum (0x0010)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 17, 0x00, 0x00  @ mapGroup, mapNum (0x0011)
	.globl gMapConnections_OLDALE_TOWN
gMapConnections_OLDALE_TOWN: @ 0x0845EA58
	.4byte 3  @ count
	.4byte OLDALE_TOWN_MapConnections  @ connections
	.globl DEWFORD_TOWN_MapConnections
DEWFORD_TOWN_MapConnections: @ 0x0845EA60
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte -60  @ offset
	.byte 0, 21, 0x00, 0x00  @ mapGroup, mapNum (0x0015)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 22, 0x00, 0x00  @ mapGroup, mapNum (0x0016)
	.globl gMapConnections_DEWFORD_TOWN
gMapConnections_DEWFORD_TOWN: @ 0x0845EA78
	.4byte 2  @ count
	.4byte DEWFORD_TOWN_MapConnections  @ connections
	.globl LAVARIDGE_TOWN_MapConnections
LAVARIDGE_TOWN_MapConnections: @ 0x0845EA80
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte -40  @ offset
	.byte 0, 27, 0x00, 0x00  @ mapGroup, mapNum (0x001B)
	.globl gMapConnections_LAVARIDGE_TOWN
gMapConnections_LAVARIDGE_TOWN: @ 0x0845EA8C
	.4byte 1  @ count
	.4byte LAVARIDGE_TOWN_MapConnections  @ connections
	.globl FALLARBOR_TOWN_MapConnections
FALLARBOR_TOWN_MapConnections: @ 0x0845EA94
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 29, 0x00, 0x00  @ mapGroup, mapNum (0x001D)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 28, 0x00, 0x00  @ mapGroup, mapNum (0x001C)
	.globl gMapConnections_FALLARBOR_TOWN
gMapConnections_FALLARBOR_TOWN: @ 0x0845EAAC
	.4byte 2  @ count
	.4byte FALLARBOR_TOWN_MapConnections  @ connections
	.globl VERDANTURF_TOWN_MapConnections
VERDANTURF_TOWN_MapConnections: @ 0x0845EAB4
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte -80  @ offset
	.byte 0, 31, 0x00, 0x00  @ mapGroup, mapNum (0x001F)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 32, 0x00, 0x00  @ mapGroup, mapNum (0x0020)
	.globl gMapConnections_VERDANTURF_TOWN
gMapConnections_VERDANTURF_TOWN: @ 0x0845EACC
	.4byte 2  @ count
	.4byte VERDANTURF_TOWN_MapConnections  @ connections
	.globl PACIFIDLOG_TOWN_MapConnections
PACIFIDLOG_TOWN_MapConnections: @ 0x0845EAD4
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 47, 0x00, 0x00  @ mapGroup, mapNum (0x002F)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 46, 0x00, 0x00  @ mapGroup, mapNum (0x002E)
	.globl gMapConnections_PACIFIDLOG_TOWN
gMapConnections_PACIFIDLOG_TOWN: @ 0x0845EAEC
	.4byte 2  @ count
	.4byte PACIFIDLOG_TOWN_MapConnections  @ connections
	.globl PETALBURG_CITY_MapConnections
PETALBURG_CITY_MapConnections: @ 0x0845EAF4
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte -50  @ offset
	.byte 0, 19, 0x00, 0x00  @ mapGroup, mapNum (0x0013)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 10  @ offset
	.byte 0, 17, 0x00, 0x00  @ mapGroup, mapNum (0x0011)
	.globl gMapConnections_PETALBURG_CITY
gMapConnections_PETALBURG_CITY: @ 0x0845EB0C
	.4byte 2  @ count
	.4byte PETALBURG_CITY_MapConnections  @ connections
	.globl SLATEPORT_CITY_MapConnections
SLATEPORT_CITY_MapConnections: @ 0x0845EB14
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 25, 0x00, 0x00  @ mapGroup, mapNum (0x0019)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 24, 0x00, 0x00  @ mapGroup, mapNum (0x0018)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 49, 0x00, 0x00  @ mapGroup, mapNum (0x0031)
	.globl gMapConnections_SLATEPORT_CITY
gMapConnections_SLATEPORT_CITY: @ 0x0845EB38
	.4byte 3  @ count
	.4byte SLATEPORT_CITY_MapConnections  @ connections
	.globl MAUVILLE_CITY_MapConnections
MAUVILLE_CITY_MapConnections: @ 0x0845EB40
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 26, 0x00, 0x00  @ mapGroup, mapNum (0x001A)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 25, 0x00, 0x00  @ mapGroup, mapNum (0x0019)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 32, 0x00, 0x00  @ mapGroup, mapNum (0x0020)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 33, 0x00, 0x00  @ mapGroup, mapNum (0x0021)
	.globl gMapConnections_MAUVILLE_CITY
gMapConnections_MAUVILLE_CITY: @ 0x0845EB70
	.4byte 4  @ count
	.4byte MAUVILLE_CITY_MapConnections  @ connections
	.globl RUSTBORO_CITY_MapConnections
RUSTBORO_CITY_MapConnections: @ 0x0845EB78
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 30, 0x00, 0x00  @ mapGroup, mapNum (0x001E)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 19, 0x00, 0x00  @ mapGroup, mapNum (0x0013)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 31, 0x00, 0x00  @ mapGroup, mapNum (0x001F)
	.globl gMapConnections_RUSTBORO_CITY
gMapConnections_RUSTBORO_CITY: @ 0x0845EB9C
	.4byte 3  @ count
	.4byte RUSTBORO_CITY_MapConnections  @ connections
	.globl FORTREE_CITY_MapConnections
FORTREE_CITY_MapConnections: @ 0x0845EBA4
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 34, 0x00, 0x00  @ mapGroup, mapNum (0x0022)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 35, 0x00, 0x00  @ mapGroup, mapNum (0x0023)
	.globl gMapConnections_FORTREE_CITY
gMapConnections_FORTREE_CITY: @ 0x0845EBBC
	.4byte 2  @ count
	.4byte FORTREE_CITY_MapConnections  @ connections
	.globl LILYCOVE_CITY_MapConnections
LILYCOVE_CITY_MapConnections: @ 0x0845EBC4
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 10  @ offset
	.byte 0, 36, 0x00, 0x00  @ mapGroup, mapNum (0x0024)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte -10  @ offset
	.byte 0, 39, 0x00, 0x00  @ mapGroup, mapNum (0x0027)
	.globl gMapConnections_LILYCOVE_CITY
gMapConnections_LILYCOVE_CITY: @ 0x0845EBDC
	.4byte 2  @ count
	.4byte LILYCOVE_CITY_MapConnections  @ connections
	.globl MOSSDEEP_CITY_MapConnections
MOSSDEEP_CITY_MapConnections: @ 0x0845EBE4
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 40, 0x00, 0x00  @ mapGroup, mapNum (0x0028)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 42, 0x00, 0x00  @ mapGroup, mapNum (0x002A)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte -40  @ offset
	.byte 0, 39, 0x00, 0x00  @ mapGroup, mapNum (0x0027)
	.globl gMapConnections_MOSSDEEP_CITY
gMapConnections_MOSSDEEP_CITY: @ 0x0845EC08
	.4byte 3  @ count
	.4byte MOSSDEEP_CITY_MapConnections  @ connections
	.incbin "baserom_jp.gba", 0x45EC10, 0x8
	.globl EVER_GRANDE_CITY_MapConnections
EVER_GRANDE_CITY_MapConnections: @ 0x0845EC18
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 40  @ offset
	.byte 0, 43, 0x00, 0x00  @ mapGroup, mapNum (0x002B)
	.globl gMapConnections_EVER_GRANDE_CITY
gMapConnections_EVER_GRANDE_CITY: @ 0x0845EC24
	.4byte 1  @ count
	.4byte EVER_GRANDE_CITY_MapConnections  @ connections
	.globl ROUTE101_MapConnections
ROUTE101_MapConnections: @ 0x0845EC2C
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 10, 0x00, 0x00  @ mapGroup, mapNum (0x000A)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 9, 0x00, 0x00  @ mapGroup, mapNum (0x0009)
	.globl gMapConnections_ROUTE101
gMapConnections_ROUTE101: @ 0x0845EC44
	.4byte 2  @ count
	.4byte ROUTE101_MapConnections  @ connections
	.globl ROUTE102_MapConnections
ROUTE102_MapConnections: @ 0x0845EC4C
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte -10  @ offset
	.byte 0, 0, 0x00, 0x00  @ mapGroup, mapNum (0x0000)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 10, 0x00, 0x00  @ mapGroup, mapNum (0x000A)
	.globl gMapConnections_ROUTE102
gMapConnections_ROUTE102: @ 0x0845EC64
	.4byte 2  @ count
	.4byte ROUTE102_MapConnections  @ connections
	.globl ROUTE103_MapConnections
ROUTE103_MapConnections: @ 0x0845EC6C
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 10, 0x00, 0x00  @ mapGroup, mapNum (0x000A)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte -60  @ offset
	.byte 0, 25, 0x00, 0x00  @ mapGroup, mapNum (0x0019)
	.globl gMapConnections_ROUTE103
gMapConnections_ROUTE103: @ 0x0845EC84
	.4byte 2  @ count
	.4byte ROUTE103_MapConnections  @ connections
	.globl ROUTE104_MapConnections
ROUTE104_MapConnections: @ 0x0845EC8C
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 3, 0x00, 0x00  @ mapGroup, mapNum (0x0003)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 20, 0x00, 0x00  @ mapGroup, mapNum (0x0014)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 50  @ offset
	.byte 0, 0, 0x00, 0x00  @ mapGroup, mapNum (0x0000)
	.globl gMapConnections_ROUTE104
gMapConnections_ROUTE104: @ 0x0845ECB0
	.4byte 3  @ count
	.4byte ROUTE104_MapConnections  @ connections
	.globl ROUTE105_MapConnections
ROUTE105_MapConnections: @ 0x0845ECB8
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 19, 0x00, 0x00  @ mapGroup, mapNum (0x0013)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 21, 0x00, 0x00  @ mapGroup, mapNum (0x0015)
	.byte 0x05, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 55, 0x00, 0x00  @ mapGroup, mapNum (0x0037)
	.globl gMapConnections_ROUTE105
gMapConnections_ROUTE105: @ 0x0845ECDC
	.4byte 3  @ count
	.4byte ROUTE105_MapConnections  @ connections
	.globl ROUTE106_MapConnections
ROUTE106_MapConnections: @ 0x0845ECE4
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 20, 0x00, 0x00  @ mapGroup, mapNum (0x0014)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 60  @ offset
	.byte 0, 11, 0x00, 0x00  @ mapGroup, mapNum (0x000B)
	.globl gMapConnections_ROUTE106
gMapConnections_ROUTE106: @ 0x0845ECFC
	.4byte 2  @ count
	.4byte ROUTE106_MapConnections  @ connections
	.globl ROUTE107_MapConnections
ROUTE107_MapConnections: @ 0x0845ED04
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 11, 0x00, 0x00  @ mapGroup, mapNum (0x000B)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 23, 0x00, 0x00  @ mapGroup, mapNum (0x0017)
	.globl gMapConnections_ROUTE107
gMapConnections_ROUTE107: @ 0x0845ED1C
	.4byte 2  @ count
	.4byte ROUTE107_MapConnections  @ connections
	.globl ROUTE108_MapConnections
ROUTE108_MapConnections: @ 0x0845ED24
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 22, 0x00, 0x00  @ mapGroup, mapNum (0x0016)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte -40  @ offset
	.byte 0, 24, 0x00, 0x00  @ mapGroup, mapNum (0x0018)
	.globl gMapConnections_ROUTE108
gMapConnections_ROUTE108: @ 0x0845ED3C
	.4byte 2  @ count
	.4byte ROUTE108_MapConnections  @ connections
	.globl ROUTE109_MapConnections
ROUTE109_MapConnections: @ 0x0845ED44
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 1, 0x00, 0x00  @ mapGroup, mapNum (0x0001)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 40  @ offset
	.byte 0, 23, 0x00, 0x00  @ mapGroup, mapNum (0x0017)
	.globl gMapConnections_ROUTE109
gMapConnections_ROUTE109: @ 0x0845ED5C
	.4byte 2  @ count
	.4byte ROUTE109_MapConnections  @ connections
	.globl ROUTE110_MapConnections
ROUTE110_MapConnections: @ 0x0845ED64
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 2, 0x00, 0x00  @ mapGroup, mapNum (0x0002)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 1, 0x00, 0x00  @ mapGroup, mapNum (0x0001)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 60  @ offset
	.byte 0, 18, 0x00, 0x00  @ mapGroup, mapNum (0x0012)
	.globl gMapConnections_ROUTE110
gMapConnections_ROUTE110: @ 0x0845ED88
	.4byte 3  @ count
	.4byte ROUTE110_MapConnections  @ connections
	.globl ROUTE111_MapConnections
ROUTE111_MapConnections: @ 0x0845ED90
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 2, 0x00, 0x00  @ mapGroup, mapNum (0x0002)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 28, 0x00, 0x00  @ mapGroup, mapNum (0x001C)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 20  @ offset
	.byte 0, 27, 0x00, 0x00  @ mapGroup, mapNum (0x001B)
	.globl gMapConnections_ROUTE111
gMapConnections_ROUTE111: @ 0x0845EDB4
	.4byte 3  @ count
	.4byte ROUTE111_MapConnections  @ connections
	.globl ROUTE112_MapConnections
ROUTE112_MapConnections: @ 0x0845EDBC
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte -60  @ offset
	.byte 0, 28, 0x00, 0x00  @ mapGroup, mapNum (0x001C)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 40  @ offset
	.byte 0, 12, 0x00, 0x00  @ mapGroup, mapNum (0x000C)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte -20  @ offset
	.byte 0, 26, 0x00, 0x00  @ mapGroup, mapNum (0x001A)
	.globl gMapConnections_ROUTE112
gMapConnections_ROUTE112: @ 0x0845EDE0
	.4byte 3  @ count
	.4byte ROUTE112_MapConnections  @ connections
	.globl ROUTE113_MapConnections
ROUTE113_MapConnections: @ 0x0845EDE8
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 60  @ offset
	.byte 0, 27, 0x00, 0x00  @ mapGroup, mapNum (0x001B)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 13, 0x00, 0x00  @ mapGroup, mapNum (0x000D)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 26, 0x00, 0x00  @ mapGroup, mapNum (0x001A)
	.globl gMapConnections_ROUTE113
gMapConnections_ROUTE113: @ 0x0845EE0C
	.4byte 3  @ count
	.4byte ROUTE113_MapConnections  @ connections
	.globl ROUTE114_MapConnections
ROUTE114_MapConnections: @ 0x0845EE14
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 40  @ offset
	.byte 0, 30, 0x00, 0x00  @ mapGroup, mapNum (0x001E)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 13, 0x00, 0x00  @ mapGroup, mapNum (0x000D)
	.globl gMapConnections_ROUTE114
gMapConnections_ROUTE114: @ 0x0845EE2C
	.4byte 2  @ count
	.4byte ROUTE114_MapConnections  @ connections
	.globl ROUTE115_MapConnections
ROUTE115_MapConnections: @ 0x0845EE34
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 3, 0x00, 0x00  @ mapGroup, mapNum (0x0003)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte -40  @ offset
	.byte 0, 29, 0x00, 0x00  @ mapGroup, mapNum (0x001D)
	.globl gMapConnections_ROUTE115
gMapConnections_ROUTE115: @ 0x0845EE4C
	.4byte 2  @ count
	.4byte ROUTE115_MapConnections  @ connections
	.globl ROUTE116_MapConnections
ROUTE116_MapConnections: @ 0x0845EE54
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 80  @ offset
	.byte 0, 14, 0x00, 0x00  @ mapGroup, mapNum (0x000E)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 3, 0x00, 0x00  @ mapGroup, mapNum (0x0003)
	.globl gMapConnections_ROUTE116
gMapConnections_ROUTE116: @ 0x0845EE6C
	.4byte 2  @ count
	.4byte ROUTE116_MapConnections  @ connections
	.globl ROUTE117_MapConnections
ROUTE117_MapConnections: @ 0x0845EE74
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 14, 0x00, 0x00  @ mapGroup, mapNum (0x000E)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 2, 0x00, 0x00  @ mapGroup, mapNum (0x0002)
	.globl gMapConnections_ROUTE117
gMapConnections_ROUTE117: @ 0x0845EE8C
	.4byte 2  @ count
	.4byte ROUTE117_MapConnections  @ connections
	.globl ROUTE118_MapConnections
ROUTE118_MapConnections: @ 0x0845EE94
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 40  @ offset
	.byte 0, 34, 0x00, 0x00  @ mapGroup, mapNum (0x0022)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 2, 0x00, 0x00  @ mapGroup, mapNum (0x0002)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 38, 0x00, 0x00  @ mapGroup, mapNum (0x0026)
	.globl gMapConnections_ROUTE118
gMapConnections_ROUTE118: @ 0x0845EEB8
	.4byte 3  @ count
	.4byte ROUTE118_MapConnections  @ connections
	.globl ROUTE119_MapConnections
ROUTE119_MapConnections: @ 0x0845EEC0
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte -40  @ offset
	.byte 0, 33, 0x00, 0x00  @ mapGroup, mapNum (0x0021)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 4, 0x00, 0x00  @ mapGroup, mapNum (0x0004)
	.globl gMapConnections_ROUTE119
gMapConnections_ROUTE119: @ 0x0845EED8
	.4byte 2  @ count
	.4byte ROUTE119_MapConnections  @ connections
	.globl ROUTE120_MapConnections
ROUTE120_MapConnections: @ 0x0845EEE0
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 4, 0x00, 0x00  @ mapGroup, mapNum (0x0004)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 80  @ offset
	.byte 0, 36, 0x00, 0x00  @ mapGroup, mapNum (0x0024)
	.globl gMapConnections_ROUTE120
gMapConnections_ROUTE120: @ 0x0845EEF8
	.4byte 2  @ count
	.4byte ROUTE120_MapConnections  @ connections
	.globl ROUTE121_MapConnections
ROUTE121_MapConnections: @ 0x0845EF00
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 20  @ offset
	.byte 0, 37, 0x00, 0x00  @ mapGroup, mapNum (0x0025)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte -80  @ offset
	.byte 0, 35, 0x00, 0x00  @ mapGroup, mapNum (0x0023)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte -10  @ offset
	.byte 0, 5, 0x00, 0x00  @ mapGroup, mapNum (0x0005)
	.globl gMapConnections_ROUTE121
gMapConnections_ROUTE121: @ 0x0845EF24
	.4byte 3  @ count
	.4byte ROUTE121_MapConnections  @ connections
	.globl ROUTE122_MapConnections
ROUTE122_MapConnections: @ 0x0845EF2C
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte -20  @ offset
	.byte 0, 36, 0x00, 0x00  @ mapGroup, mapNum (0x0024)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte -100  @ offset
	.byte 0, 38, 0x00, 0x00  @ mapGroup, mapNum (0x0026)
	.globl gMapConnections_ROUTE122
gMapConnections_ROUTE122: @ 0x0845EF44
	.4byte 2  @ count
	.4byte ROUTE122_MapConnections  @ connections
	.globl ROUTE123_MapConnections
ROUTE123_MapConnections: @ 0x0845EF4C
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 100  @ offset
	.byte 0, 37, 0x00, 0x00  @ mapGroup, mapNum (0x0025)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 33, 0x00, 0x00  @ mapGroup, mapNum (0x0021)
	.globl gMapConnections_ROUTE123
gMapConnections_ROUTE123: @ 0x0845EF64
	.4byte 2  @ count
	.4byte ROUTE123_MapConnections  @ connections
	.globl ROUTE124_MapConnections
ROUTE124_MapConnections: @ 0x0845EF6C
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 41, 0x00, 0x00  @ mapGroup, mapNum (0x0029)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 10  @ offset
	.byte 0, 5, 0x00, 0x00  @ mapGroup, mapNum (0x0005)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 40, 0x00, 0x00  @ mapGroup, mapNum (0x0028)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 40  @ offset
	.byte 0, 6, 0x00, 0x00  @ mapGroup, mapNum (0x0006)
	.byte 0x05, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 50, 0x00, 0x00  @ mapGroup, mapNum (0x0032)
	.globl gMapConnections_ROUTE124
gMapConnections_ROUTE124: @ 0x0845EFA8
	.4byte 5  @ count
	.4byte ROUTE124_MapConnections  @ connections
	.globl ROUTE125_MapConnections
ROUTE125_MapConnections: @ 0x0845EFB0
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 6, 0x00, 0x00  @ mapGroup, mapNum (0x0006)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 39, 0x00, 0x00  @ mapGroup, mapNum (0x0027)
	.byte 0x05, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 56, 0x00, 0x00  @ mapGroup, mapNum (0x0038)
	.globl gMapConnections_ROUTE125
gMapConnections_ROUTE125: @ 0x0845EFD4
	.4byte 3  @ count
	.4byte ROUTE125_MapConnections  @ connections
	.globl ROUTE126_MapConnections
ROUTE126_MapConnections: @ 0x0845EFDC
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 39, 0x00, 0x00  @ mapGroup, mapNum (0x0027)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 42, 0x00, 0x00  @ mapGroup, mapNum (0x002A)
	.byte 0x05, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 51, 0x00, 0x00  @ mapGroup, mapNum (0x0033)
	.globl gMapConnections_ROUTE126
gMapConnections_ROUTE126: @ 0x0845F000
	.4byte 3  @ count
	.4byte ROUTE126_MapConnections  @ connections
	.globl ROUTE127_MapConnections
ROUTE127_MapConnections: @ 0x0845F008
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 6, 0x00, 0x00  @ mapGroup, mapNum (0x0006)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 43, 0x00, 0x00  @ mapGroup, mapNum (0x002B)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 41, 0x00, 0x00  @ mapGroup, mapNum (0x0029)
	.byte 0x05, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 52, 0x00, 0x00  @ mapGroup, mapNum (0x0034)
	.globl gMapConnections_ROUTE127
gMapConnections_ROUTE127: @ 0x0845F038
	.4byte 4  @ count
	.4byte ROUTE127_MapConnections  @ connections
	.globl ROUTE128_MapConnections
ROUTE128_MapConnections: @ 0x0845F040
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 42, 0x00, 0x00  @ mapGroup, mapNum (0x002A)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 44, 0x00, 0x00  @ mapGroup, mapNum (0x002C)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte -40  @ offset
	.byte 0, 8, 0x00, 0x00  @ mapGroup, mapNum (0x0008)
	.byte 0x05, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 53, 0x00, 0x00  @ mapGroup, mapNum (0x0035)
	.globl gMapConnections_ROUTE128
gMapConnections_ROUTE128: @ 0x0845F070
	.4byte 4  @ count
	.4byte ROUTE128_MapConnections  @ connections
	.globl ROUTE129_MapConnections
ROUTE129_MapConnections: @ 0x0845F078
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 43, 0x00, 0x00  @ mapGroup, mapNum (0x002B)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 45, 0x00, 0x00  @ mapGroup, mapNum (0x002D)
	.byte 0x05, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 54, 0x00, 0x00  @ mapGroup, mapNum (0x0036)
	.globl gMapConnections_ROUTE129
gMapConnections_ROUTE129: @ 0x0845F09C
	.4byte 3  @ count
	.4byte ROUTE129_MapConnections  @ connections
	.globl ROUTE130_MapConnections
ROUTE130_MapConnections: @ 0x0845F0A4
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 46, 0x00, 0x00  @ mapGroup, mapNum (0x002E)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 44, 0x00, 0x00  @ mapGroup, mapNum (0x002C)
	.globl gMapConnections_ROUTE130
gMapConnections_ROUTE130: @ 0x0845F0BC
	.4byte 2  @ count
	.4byte ROUTE130_MapConnections  @ connections
	.globl ROUTE131_MapConnections
ROUTE131_MapConnections: @ 0x0845F0C4
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 15, 0x00, 0x00  @ mapGroup, mapNum (0x000F)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 45, 0x00, 0x00  @ mapGroup, mapNum (0x002D)
	.globl gMapConnections_ROUTE131
gMapConnections_ROUTE131: @ 0x0845F0DC
	.4byte 2  @ count
	.4byte ROUTE131_MapConnections  @ connections
	.globl ROUTE132_MapConnections
ROUTE132_MapConnections: @ 0x0845F0E4
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 48, 0x00, 0x00  @ mapGroup, mapNum (0x0030)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 15, 0x00, 0x00  @ mapGroup, mapNum (0x000F)
	.globl gMapConnections_ROUTE132
gMapConnections_ROUTE132: @ 0x0845F0FC
	.4byte 2  @ count
	.4byte ROUTE132_MapConnections  @ connections
	.globl ROUTE133_MapConnections
ROUTE133_MapConnections: @ 0x0845F104
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 49, 0x00, 0x00  @ mapGroup, mapNum (0x0031)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 47, 0x00, 0x00  @ mapGroup, mapNum (0x002F)
	.globl gMapConnections_ROUTE133
gMapConnections_ROUTE133: @ 0x0845F11C
	.4byte 2  @ count
	.4byte ROUTE133_MapConnections  @ connections
	.globl ROUTE134_MapConnections
ROUTE134_MapConnections: @ 0x0845F124
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 1, 0x00, 0x00  @ mapGroup, mapNum (0x0001)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 48, 0x00, 0x00  @ mapGroup, mapNum (0x0030)
	.globl gMapConnections_ROUTE134
gMapConnections_ROUTE134: @ 0x0845F13C
	.4byte 2  @ count
	.4byte ROUTE134_MapConnections  @ connections
	.globl UNDERWATER_ROUTE105_MapConnections
UNDERWATER_ROUTE105_MapConnections: @ 0x0845F144
	.byte 0x06, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 20, 0x00, 0x00  @ mapGroup, mapNum (0x0014)
	.globl gMapConnections_UNDERWATER_ROUTE105
gMapConnections_UNDERWATER_ROUTE105: @ 0x0845F150
	.4byte 1  @ count
	.4byte UNDERWATER_ROUTE105_MapConnections  @ connections
	.globl UNDERWATER_ROUTE124_MapConnections
UNDERWATER_ROUTE124_MapConnections: @ 0x0845F158
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 51, 0x00, 0x00  @ mapGroup, mapNum (0x0033)
	.byte 0x06, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 39, 0x00, 0x00  @ mapGroup, mapNum (0x0027)
	.globl gMapConnections_UNDERWATER_ROUTE124
gMapConnections_UNDERWATER_ROUTE124: @ 0x0845F170
	.4byte 2  @ count
	.4byte UNDERWATER_ROUTE124_MapConnections  @ connections
	.globl UNDERWATER_ROUTE125_MapConnections
UNDERWATER_ROUTE125_MapConnections: @ 0x0845F178
	.byte 0x06, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 40, 0x00, 0x00  @ mapGroup, mapNum (0x0028)
	.globl gMapConnections_UNDERWATER_ROUTE125
gMapConnections_UNDERWATER_ROUTE125: @ 0x0845F184
	.4byte 1  @ count
	.4byte UNDERWATER_ROUTE125_MapConnections  @ connections
	.globl UNDERWATER_ROUTE126_MapConnections
UNDERWATER_ROUTE126_MapConnections: @ 0x0845F18C
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 50, 0x00, 0x00  @ mapGroup, mapNum (0x0032)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 52, 0x00, 0x00  @ mapGroup, mapNum (0x0034)
	.byte 0x06, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 41, 0x00, 0x00  @ mapGroup, mapNum (0x0029)
	.globl gMapConnections_UNDERWATER_ROUTE126
gMapConnections_UNDERWATER_ROUTE126: @ 0x0845F1B0
	.4byte 3  @ count
	.4byte UNDERWATER_ROUTE126_MapConnections  @ connections
	.globl UNDERWATER_ROUTE127_MapConnections
UNDERWATER_ROUTE127_MapConnections: @ 0x0845F1B8
	.byte 0x06, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 42, 0x00, 0x00  @ mapGroup, mapNum (0x002A)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 51, 0x00, 0x00  @ mapGroup, mapNum (0x0033)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 53, 0x00, 0x00  @ mapGroup, mapNum (0x0035)
	.globl gMapConnections_UNDERWATER_ROUTE127
gMapConnections_UNDERWATER_ROUTE127: @ 0x0845F1DC
	.4byte 3  @ count
	.4byte UNDERWATER_ROUTE127_MapConnections  @ connections
	.globl UNDERWATER_ROUTE128_MapConnections
UNDERWATER_ROUTE128_MapConnections: @ 0x0845F1E4
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 52, 0x00, 0x00  @ mapGroup, mapNum (0x0034)
	.byte 0x06, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 43, 0x00, 0x00  @ mapGroup, mapNum (0x002B)
	.globl gMapConnections_UNDERWATER_ROUTE128
gMapConnections_UNDERWATER_ROUTE128: @ 0x0845F1FC
	.4byte 2  @ count
	.4byte UNDERWATER_ROUTE128_MapConnections  @ connections
	.globl UNDERWATER_ROUTE129_MapConnections
UNDERWATER_ROUTE129_MapConnections: @ 0x0845F204
	.byte 0x06, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 44, 0x00, 0x00  @ mapGroup, mapNum (0x002C)
	.globl gMapConnections_UNDERWATER_ROUTE129
gMapConnections_UNDERWATER_ROUTE129: @ 0x0845F210
	.4byte 1  @ count
	.4byte UNDERWATER_ROUTE129_MapConnections  @ connections
	.incbin "baserom_jp.gba", 0x45F218, 0x100

	.globl sDummyConnectionFlags
sDummyConnectionFlags: @ 0x845F318
	.incbin "baserom_jp.gba", 0x45f318, 0x4

	.globl sTileBitAttributes
sTileBitAttributes: @ 0x845F31C
	.incbin "baserom_jp.gba", 0x45f31c, 0x10090

	.globl sDoorOpenAnimFrames
sDoorOpenAnimFrames: @ 0x846F3AC
	.incbin "baserom_jp.gba", 0x46f3ac, 0x14

	.globl sDoorCloseAnimFrames
sDoorCloseAnimFrames: @ 0x846F3C0
	.incbin "baserom_jp.gba", 0x46f3c0, 0x14

	.globl sBigDoorOpenAnimFrames
sBigDoorOpenAnimFrames: @ 0x846F3D4
	.incbin "baserom_jp.gba", 0x46f3d4, 0x1c0

	.globl sDoorAnimGraphicsTable
sDoorAnimGraphicsTable: @ 0x846F594
	.incbin "baserom_jp.gba", 0x46f594, 0x288

	.globl sForcedMovementTestFuncs
sForcedMovementTestFuncs: @ 0x846F81C
	.incbin "baserom_jp.gba", 0x46f81c, 0x48

	.globl sForcedMovementFuncs
sForcedMovementFuncs: @ 0x846F864
	.incbin "baserom_jp.gba", 0x46f864, 0x4c

	.globl sPlayerNotOnBikeFuncs
sPlayerNotOnBikeFuncs: @ 0x846F8B0
	.incbin "baserom_jp.gba", 0x46f8b0, 0xc

	.globl sAcroBikeTrickMetatiles
sAcroBikeTrickMetatiles: @ 0x846F8BC
	.incbin "baserom_jp.gba", 0x46f8bc, 0x14

	.globl sAcroBikeTrickCollisionTypes
sAcroBikeTrickCollisionTypes: @ 0x846F8D0
	.byte 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x00, 0x00, 0x00

	.globl sPlayerAvatarTransitionFuncs
sPlayerAvatarTransitionFuncs: @ 0x846F8D8
	.incbin "baserom_jp.gba", 0x46f8d8, 0x20

	.globl sArrowWarpMetatileBehaviorChecks
sArrowWarpMetatileBehaviorChecks: @ 0x846F8F8
	.incbin "baserom_jp.gba", 0x46f8f8, 0x10

	.globl gUnknown_846F908
gUnknown_846F908: @ 0x846F908
	.incbin "baserom_jp.gba", 0x46f908, 0x10

	.globl gUnknown_846F918
gUnknown_846F918: @ 0x846F918
	.incbin "baserom_jp.gba", 0x46f918, 0x10

	.globl gUnknown_846F928
gUnknown_846F928: @ 0x846F928
	.incbin "baserom_jp.gba", 0x46f928, 0x2

	.globl gUnknown_846F92A
gUnknown_846F92A: @ 0x846F92A
	.incbin "baserom_jp.gba", 0x46f92a, 0x2

	.globl gUnknown_846F92C
gUnknown_846F92C: @ 0x846F92C
	.incbin "baserom_jp.gba", 0x46f92c, 0x14

	.globl gUnknown_846F940
gUnknown_846F940: @ 0x846F940
	.incbin "baserom_jp.gba", 0x46f940, 0x10

	.globl gUnknown_846F950
gUnknown_846F950: @ 0x846F950
	.incbin "baserom_jp.gba", 0x46f950, 0xc

	.globl gUnknown_846F95C
gUnknown_846F95C: @ 0x846F95C
	.incbin "baserom_jp.gba", 0x46f95c, 0x4

	.globl gUnknown_846F960
gUnknown_846F960: @ 0x846F960
	.incbin "baserom_jp.gba", 0x46f960, 0x10

	.globl gUnknown_846F970
gUnknown_846F970: @ 0x846F970
	.incbin "baserom_jp.gba", 0x46f970, 0x4

	.globl gUnknown_846F974
gUnknown_846F974: @ 0x846F974
	.incbin "baserom_jp.gba", 0x46f974, 0x8

	.globl gUnknown_846F97C
gUnknown_846F97C: @ 0x846F97C
	.incbin "baserom_jp.gba", 0x46f97c, 0x40

	.globl gUnknown_846F9BC
gUnknown_846F9BC: @ 0x846F9BC
	.incbin "baserom_jp.gba", 0x46f9bc, 0x6

	.globl gUnknown_846F9C2
gUnknown_846F9C2: @ 0x846F9C2
	.incbin "baserom_jp.gba", 0x46f9c2, 0x6

	.globl gUnknown_846F9C8
gUnknown_846F9C8: @ 0x846F9C8
	.string "·$"

	.globl gUnknown_846F9CA
gUnknown_846F9CA: @ 0x846F9CA
	.string "ひいてる　ひいてる！！$"
	.globl gUnknown_846F9D6
gUnknown_846F9D6: @ 0x846F9D6
	.incbin "baserom_jp.gba", 0x46f9d6, 0x6

	.globl gUnknown_846F9DC
gUnknown_846F9DC: @ 0x846F9DC
	.incbin "baserom_jp.gba", 0x46f9dc, 0xc

	.globl gUnknown_846F9E8
gUnknown_846F9E8: @ 0x846F9E8
	.string "ポケモンを　つりあげた！{PAUSE_UNTIL_PRESS}$"
	.globl gUnknown_846F9F7
gUnknown_846F9F7: @ 0x846F9F7
	.string "つれないなあ···{PAUSE_UNTIL_PRESS}$"
	.globl gUnknown_846FA03
gUnknown_846FA03: @ 0x846FA03
	.string "にげられて　しまった···{PAUSE_UNTIL_PRESS}$"
	.globl gUnknown_846FA13
gUnknown_846FA13: @ 0x846FA13
	.incbin "baserom_jp.gba", 0x46fa13, 0x5

	.globl gReflectionEffectPaletteMap
gReflectionEffectPaletteMap: @ 0x846FA18
	.incbin "baserom_jp.gba", 0x46fa18, 0x10

	.globl gUnknown_846FA28
gUnknown_846FA28: @ 0x846FA28
	.incbin "baserom_jp.gba", 0x46fa28, 0x18

	.globl gUnknown_846FA40
gUnknown_846FA40: @ 0x846FA40
	.incbin "baserom_jp.gba", 0x46fa40, 0x120c

	.globl gUnknown_8470C4C
gUnknown_8470C4C: @ 0x8470C4C
	.incbin "baserom_jp.gba", 0x470c4c, 0x1220

	.globl gUnknown_8471E6C
gUnknown_8471E6C: @ 0x8471E6C
	.incbin "baserom_jp.gba", 0x471e6c, 0xa860

	.globl gUnknown_847C6CC
gUnknown_847C6CC: @ 0x847C6CC
	.incbin "baserom_jp.gba", 0x47c6cc, 0x1240

	.globl gUnknown_847D90C
gUnknown_847D90C: @ 0x847D90C
	.incbin "baserom_jp.gba", 0x47d90c, 0x5ff80

	.globl gUnknown_84DD88C
gUnknown_84DD88C: @ 0x84DD88C
	.incbin "baserom_jp.gba", 0x4dd88c, 0x144

	.globl gUnknown_84DD9D0
gUnknown_84DD9D0: @ 0x84DD9D0
	.incbin "baserom_jp.gba", 0x4dd9d0, 0x51

	.globl gUnknown_84DDA21
gUnknown_84DDA21: @ 0x84DDA21
	.incbin "baserom_jp.gba", 0x4dda21, 0x53

	.globl gUnknown_84DDA74
gUnknown_84DDA74: @ 0x84DDA74
	.incbin "baserom_jp.gba", 0x4dda74, 0x3bc

	.globl gUnknown_84DDE30
gUnknown_84DDE30: @ 0x84DDE30
	.incbin "baserom_jp.gba", 0x4dde30, 0x1c

	.globl gFieldEffectObjectTemplatePointers
gFieldEffectObjectTemplatePointers: @ 0x84DDE4C
	.incbin "baserom_jp.gba", 0x4dde4c, 0x3ab4

	.globl gUnknown_84E1900
gUnknown_84E1900: @ 0x84E1900
	.incbin "baserom_jp.gba", 0x4e1900, 0x271c

	.globl gUnknown_84E401C
gUnknown_84E401C: @ 0x84E401C
	.incbin "baserom_jp.gba", 0x4e401c, 0x138

	.globl gUnknown_84E4154
gUnknown_84E4154: @ 0x84E4154
	.incbin "baserom_jp.gba", 0x4e4154, 0x78

	.globl gUnknown_84E41CC
gUnknown_84E41CC: @ 0x84E41CC
	.incbin "baserom_jp.gba", 0x4e41cc, 0xc0

	.globl gUnknown_84E428C
gUnknown_84E428C: @ 0x84E428C
	.incbin "baserom_jp.gba", 0x4e428c, 0x978

	.globl gUnknown_84E4C04
gUnknown_84E4C04: @ 0x84E4C04
	.incbin "baserom_jp.gba", 0x4e4c04, 0xac

	.globl gUnknown_84E4CB0
gUnknown_84E4CB0: @ 0x84E4CB0
	.incbin "baserom_jp.gba", 0x4e4cb0, 0xac

	.globl gUnknown_84E4D5C
gUnknown_84E4D5C: @ 0x84E4D5C
	.incbin "baserom_jp.gba", 0x4e4d5c, 0xc0

	.globl gSpritePalette_GeneralFieldEffect1
gSpritePalette_GeneralFieldEffect1: @ 0x84E4E1C
	.incbin "baserom_jp.gba", 0x4e4e1c, 0xd14

	.globl gUnknown_84E5B30
gUnknown_84E5B30: @ 0x84E5B30
	.incbin "baserom_jp.gba", 0x4e5b30, 0x10

	.globl gUnknown_84E5B40
gUnknown_84E5B40: @ 0x84E5B40
	.incbin "baserom_jp.gba", 0x4e5b40, 0x8

	.globl gUnknown_84E5B48
gUnknown_84E5B48: @ 0x84E5B48
	.incbin "baserom_jp.gba", 0x4e5b48, 0x1c

	.globl gUnknown_84E5B64
gUnknown_84E5B64: @ 0x84E5B64
	.incbin "baserom_jp.gba", 0x4e5b64, 0x4

	.globl gUnknown_84E5B68
gUnknown_84E5B68: @ 0x84E5B68
	.incbin "baserom_jp.gba", 0x4e5b68, 0x2c

	.globl gUnknown_84E5B94
gUnknown_84E5B94: @ 0x84E5B94
	.incbin "baserom_jp.gba", 0x4e5b94, 0x14

	.globl gUnknown_84E5BA8
gUnknown_84E5BA8: @ 0x84E5BA8
	.incbin "baserom_jp.gba", 0x4e5ba8, 0x1c

	.globl gUnknown_84E5BC4
gUnknown_84E5BC4: @ 0x84E5BC4
	.incbin "baserom_jp.gba", 0x4e5bc4, 0x4

	.globl gUnknown_84E5BC8
gUnknown_84E5BC8: @ 0x84E5BC8
	.incbin "baserom_jp.gba", 0x4e5bc8, 0x1c

	.globl gUnknown_84E5BE4
gUnknown_84E5BE4: @ 0x84E5BE4
	.incbin "baserom_jp.gba", 0x4e5be4, 0x4

	.globl gUnknown_84E5BE8
gUnknown_84E5BE8: @ 0x84E5BE8
	.incbin "baserom_jp.gba", 0x4e5be8, 0xc

	.globl gUnknown_84E5BF4
gUnknown_84E5BF4: @ 0x84E5BF4
	.incbin "baserom_jp.gba", 0x4e5bf4, 0x14

	.globl gUnknown_84E5C08
gUnknown_84E5C08: @ 0x84E5C08
	.incbin "baserom_jp.gba", 0x4e5c08, 0x14

	.globl gUnknown_84E5C1C
gUnknown_84E5C1C: @ 0x84E5C1C
	.incbin "baserom_jp.gba", 0x4e5c1c, 0x14

	.globl gUnknown_84E5C30
gUnknown_84E5C30: @ 0x84E5C30
	.incbin "baserom_jp.gba", 0x4e5c30, 0x14

	.globl gUnknown_84E5C44
gUnknown_84E5C44: @ 0x84E5C44
	.incbin "baserom_jp.gba", 0x4e5c44, 0x4

	.globl gUnknown_84E5C48
gUnknown_84E5C48: @ 0x84E5C48
	.incbin "baserom_jp.gba", 0x4e5c48, 0x14

	.globl gUnknown_84E5C5C
gUnknown_84E5C5C: @ 0x84E5C5C
	.incbin "baserom_jp.gba", 0x4e5c5c, 0x4

	.globl gUnknown_84E5C60
gUnknown_84E5C60: @ 0x84E5C60
	.incbin "baserom_jp.gba", 0x4e5c60, 0x14

	.globl gUnknown_84E5C74
gUnknown_84E5C74: @ 0x84E5C74
	.incbin "baserom_jp.gba", 0x4e5c74, 0x4

	.globl gUnknown_84E5C78
gUnknown_84E5C78: @ 0x84E5C78
	.incbin "baserom_jp.gba", 0x4e5c78, 0x14

	.globl gUnknown_84E5C8C
gUnknown_84E5C8C: @ 0x84E5C8C
	.incbin "baserom_jp.gba", 0x4e5c8c, 0x4

	.globl gUnknown_84E5C90
gUnknown_84E5C90: @ 0x84E5C90
	.incbin "baserom_jp.gba", 0x4e5c90, 0x14

	.globl gUnknown_84E5CA4
gUnknown_84E5CA4: @ 0x84E5CA4
	.incbin "baserom_jp.gba", 0x4e5ca4, 0x4

	.globl gUnknown_84E5CA8
gUnknown_84E5CA8: @ 0x84E5CA8
	.incbin "baserom_jp.gba", 0x4e5ca8, 0x14

	.globl gUnknown_84E5CBC
gUnknown_84E5CBC: @ 0x84E5CBC
	.incbin "baserom_jp.gba", 0x4e5cbc, 0x4

	.globl gUnknown_84E5CC0
gUnknown_84E5CC0: @ 0x84E5CC0
	.incbin "baserom_jp.gba", 0x4e5cc0, 0x14

	.globl gUnknown_84E5CD4
gUnknown_84E5CD4: @ 0x84E5CD4
	.incbin "baserom_jp.gba", 0x4e5cd4, 0x4

	.globl gUnknown_84E5CD8
gUnknown_84E5CD8: @ 0x84E5CD8
	.incbin "baserom_jp.gba", 0x4e5cd8, 0x14

	.globl gUnknown_84E5CEC
gUnknown_84E5CEC: @ 0x84E5CEC
	.incbin "baserom_jp.gba", 0x4e5cec, 0x4

	.globl gUnknown_84E5CF0
gUnknown_84E5CF0: @ 0x84E5CF0
	.incbin "baserom_jp.gba", 0x4e5cf0, 0x10

	.globl gUnknown_84E5D00
gUnknown_84E5D00: @ 0x84E5D00
	.incbin "baserom_jp.gba", 0x4e5d00, 0x8

	.globl gUnknown_84E5D08
gUnknown_84E5D08: @ 0x84E5D08
	.incbin "baserom_jp.gba", 0x4e5d08, 0x10

	.globl gUnknown_84E5D18
gUnknown_84E5D18: @ 0x84E5D18
	.incbin "baserom_jp.gba", 0x4e5d18, 0x8

	.globl gUnknown_84E5D20
gUnknown_84E5D20: @ 0x84E5D20
	.incbin "baserom_jp.gba", 0x4e5d20, 0x10

	.globl gUnknown_84E5D30
gUnknown_84E5D30: @ 0x84E5D30
	.incbin "baserom_jp.gba", 0x4e5d30, 0xc

	.globl gUnknown_84E5D3C
gUnknown_84E5D3C: @ 0x84E5D3C
	.incbin "baserom_jp.gba", 0x4e5d3c, 0x4

	.globl gUnknown_84E5D40
gUnknown_84E5D40: @ 0x84E5D40
	.incbin "baserom_jp.gba", 0x4e5d40, 0xc

	.globl gUnknown_84E5D4C
gUnknown_84E5D4C: @ 0x84E5D4C
	.incbin "baserom_jp.gba", 0x4e5d4c, 0x4

	.globl gUnknown_84E5D50
gUnknown_84E5D50: @ 0x84E5D50
	.incbin "baserom_jp.gba", 0x4e5d50, 0xc

	.globl gUnknown_84E5D5C
gUnknown_84E5D5C: @ 0x84E5D5C
	.incbin "baserom_jp.gba", 0x4e5d5c, 0x4

	.globl gUnknown_84E5D60
gUnknown_84E5D60: @ 0x84E5D60
	.incbin "baserom_jp.gba", 0x4e5d60, 0xc

	.globl gUnknown_84E5D6C
gUnknown_84E5D6C: @ 0x84E5D6C
	.incbin "baserom_jp.gba", 0x4e5d6c, 0x4

	.globl gUnknown_84E5D70
gUnknown_84E5D70: @ 0x84E5D70
	.incbin "baserom_jp.gba", 0x4e5d70, 0xc

	.globl gUnknown_84E5D7C
gUnknown_84E5D7C: @ 0x84E5D7C
	.incbin "baserom_jp.gba", 0x4e5d7c, 0x4

	.globl gUnknown_84E5D80
gUnknown_84E5D80: @ 0x84E5D80
	.incbin "baserom_jp.gba", 0x4e5d80, 0xc

	.globl gUnknown_84E5D8C
gUnknown_84E5D8C: @ 0x84E5D8C
	.incbin "baserom_jp.gba", 0x4e5d8c, 0x4

	.globl gUnknown_84E5D90
gUnknown_84E5D90: @ 0x84E5D90
	.incbin "baserom_jp.gba", 0x4e5d90, 0xc

	.globl gUnknown_84E5D9C
gUnknown_84E5D9C: @ 0x84E5D9C
	.incbin "baserom_jp.gba", 0x4e5d9c, 0xc

	.globl gUnknown_84E5DA8
gUnknown_84E5DA8: @ 0x84E5DA8
	.incbin "baserom_jp.gba", 0x4e5da8, 0x4

	.globl gUnknown_84E5DAC
gUnknown_84E5DAC: @ 0x84E5DAC
	.incbin "baserom_jp.gba", 0x4e5dac, 0xc

	.globl gUnknown_84E5DB8
gUnknown_84E5DB8: @ 0x84E5DB8
	.incbin "baserom_jp.gba", 0x4e5db8, 0x4

	.globl gUnknown_84E5DBC
gUnknown_84E5DBC: @ 0x84E5DBC
	.incbin "baserom_jp.gba", 0x4e5dbc, 0xc

	.globl gUnknown_84E5DC8
gUnknown_84E5DC8: @ 0x84E5DC8
	.incbin "baserom_jp.gba", 0x4e5dc8, 0x4

	.globl gUnknown_84E5DCC
gUnknown_84E5DCC: @ 0x84E5DCC
	.incbin "baserom_jp.gba", 0x4e5dcc, 0xc

	.globl gUnknown_84E5DD8
gUnknown_84E5DD8: @ 0x84E5DD8
	.incbin "baserom_jp.gba", 0x4e5dd8, 0x4

	.globl gUnknown_84E5DDC
gUnknown_84E5DDC: @ 0x84E5DDC
	.incbin "baserom_jp.gba", 0x4e5ddc, 0xc

	.globl gUnknown_84E5DE8
gUnknown_84E5DE8: @ 0x84E5DE8
	.incbin "baserom_jp.gba", 0x4e5de8, 0x4

	.globl gUnknown_84E5DEC
gUnknown_84E5DEC: @ 0x84E5DEC
	.incbin "baserom_jp.gba", 0x4e5dec, 0xc

	.globl gUnknown_84E5DF8
gUnknown_84E5DF8: @ 0x84E5DF8
	.incbin "baserom_jp.gba", 0x4e5df8, 0x4

	.globl gUnknown_84E5DFC
gUnknown_84E5DFC: @ 0x84E5DFC
	.incbin "baserom_jp.gba", 0x4e5dfc, 0xc

	.globl gUnknown_84E5E08
gUnknown_84E5E08: @ 0x84E5E08
	.incbin "baserom_jp.gba", 0x4e5e08, 0x4

	.globl gUnknown_84E5E0C
gUnknown_84E5E0C: @ 0x84E5E0C
	.incbin "baserom_jp.gba", 0x4e5e0c, 0xc

	.globl gUnknown_84E5E18
gUnknown_84E5E18: @ 0x84E5E18
	.incbin "baserom_jp.gba", 0x4e5e18, 0x4

	.globl gUnknown_84E5E1C
gUnknown_84E5E1C: @ 0x84E5E1C
	.incbin "baserom_jp.gba", 0x4e5e1c, 0xc

	.globl gUnknown_84E5E28
gUnknown_84E5E28: @ 0x84E5E28
	.incbin "baserom_jp.gba", 0x4e5e28, 0x4

	.globl gUnknown_84E5E2C
gUnknown_84E5E2C: @ 0x84E5E2C
	.incbin "baserom_jp.gba", 0x4e5e2c, 0xc

	.globl gUnknown_84E5E38
gUnknown_84E5E38: @ 0x84E5E38
	.incbin "baserom_jp.gba", 0x4e5e38, 0x4

	.globl gUnknown_84E5E3C
gUnknown_84E5E3C: @ 0x84E5E3C
	.incbin "baserom_jp.gba", 0x4e5e3c, 0xc

	.globl gUnknown_84E5E48
gUnknown_84E5E48: @ 0x84E5E48
	.incbin "baserom_jp.gba", 0x4e5e48, 0x4

	.globl gUnknown_84E5E4C
gUnknown_84E5E4C: @ 0x84E5E4C
	.incbin "baserom_jp.gba", 0x4e5e4c, 0xc

	.globl gUnknown_84E5E58
gUnknown_84E5E58: @ 0x84E5E58
	.incbin "baserom_jp.gba", 0x4e5e58, 0x4

	.globl gUnknown_84E5E5C
gUnknown_84E5E5C: @ 0x84E5E5C
	.incbin "baserom_jp.gba", 0x4e5e5c, 0xc

	.globl gUnknown_84E5E68
gUnknown_84E5E68: @ 0x84E5E68
	.incbin "baserom_jp.gba", 0x4e5e68, 0x4

	.globl gUnknown_84E5E6C
gUnknown_84E5E6C: @ 0x84E5E6C
	.incbin "baserom_jp.gba", 0x4e5e6c, 0xc

	.globl gUnknown_84E5E78
gUnknown_84E5E78: @ 0x84E5E78
	.incbin "baserom_jp.gba", 0x4e5e78, 0x4

	.globl gUnknown_84E5E7C
gUnknown_84E5E7C: @ 0x84E5E7C
	.incbin "baserom_jp.gba", 0x4e5e7c, 0xc

	.globl gUnknown_84E5E88
gUnknown_84E5E88: @ 0x84E5E88
	.incbin "baserom_jp.gba", 0x4e5e88, 0x4

	.globl gUnknown_84E5E8C
gUnknown_84E5E8C: @ 0x84E5E8C
	.incbin "baserom_jp.gba", 0x4e5e8c, 0xc

	.globl gUnknown_84E5E98
gUnknown_84E5E98: @ 0x84E5E98
	.incbin "baserom_jp.gba", 0x4e5e98, 0x4

	.globl gUnknown_84E5E9C
gUnknown_84E5E9C: @ 0x84E5E9C
	.incbin "baserom_jp.gba", 0x4e5e9c, 0xc

	.globl gUnknown_84E5EA8
gUnknown_84E5EA8: @ 0x84E5EA8
	.incbin "baserom_jp.gba", 0x4e5ea8, 0x4

	.globl gUnknown_84E5EAC
gUnknown_84E5EAC: @ 0x84E5EAC
	.incbin "baserom_jp.gba", 0x4e5eac, 0xc

	.globl gUnknown_84E5EB8
gUnknown_84E5EB8: @ 0x84E5EB8
	.incbin "baserom_jp.gba", 0x4e5eb8, 0x2c

	.globl gUnknown_84E5EE4
gUnknown_84E5EE4: @ 0x84E5EE4
	.incbin "baserom_jp.gba", 0x4e5ee4, 0xc

	.globl gUnknown_84E5EF0
gUnknown_84E5EF0: @ 0x84E5EF0
	.incbin "baserom_jp.gba", 0x4e5ef0, 0x4

	.globl gUnknown_84E5EF4
gUnknown_84E5EF4: @ 0x84E5EF4
	.incbin "baserom_jp.gba", 0x4e5ef4, 0x8

	.globl gUnknown_84E5EFC
gUnknown_84E5EFC: @ 0x84E5EFC
	.incbin "baserom_jp.gba", 0x4e5efc, 0x8

	.globl gUnknown_84E5F04
gUnknown_84E5F04: @ 0x84E5F04
	.incbin "baserom_jp.gba", 0x4e5f04, 0x8

	.globl gUnknown_84E5F0C
gUnknown_84E5F0C: @ 0x84E5F0C
	.incbin "baserom_jp.gba", 0x4e5f0c, 0x8

	.globl gUnknown_84E5F14
gUnknown_84E5F14: @ 0x84E5F14
	.incbin "baserom_jp.gba", 0x4e5f14, 0xc

	.globl gUnknown_84E5F20
gUnknown_84E5F20: @ 0x84E5F20
	.incbin "baserom_jp.gba", 0x4e5f20, 0x9

	.globl gUnknown_84E5F29
gUnknown_84E5F29: @ 0x84E5F29
	.incbin "baserom_jp.gba", 0x4e5f29, 0x9

	.globl gUnknown_84E5F32
gUnknown_84E5F32: @ 0x84E5F32
	.incbin "baserom_jp.gba", 0x4e5f32, 0x9

	.globl gUnknown_84E5F3B
gUnknown_84E5F3B: @ 0x84E5F3B
	.incbin "baserom_jp.gba", 0x4e5f3b, 0x9

	.globl gUnknown_84E5F44
gUnknown_84E5F44: @ 0x84E5F44
	.incbin "baserom_jp.gba", 0x4e5f44, 0x9

	.globl gUnknown_84E5F4D
gUnknown_84E5F4D: @ 0x84E5F4D
	.incbin "baserom_jp.gba", 0x4e5f4d, 0x9

	.globl gUnknown_84E5F56
gUnknown_84E5F56: @ 0x84E5F56
	.incbin "baserom_jp.gba", 0x4e5f56, 0x9

	.globl gUnknown_84E5F5F
gUnknown_84E5F5F: @ 0x84E5F5F
	.incbin "baserom_jp.gba", 0x4e5f5f, 0x9

	.globl gUnknown_84E5F68
gUnknown_84E5F68: @ 0x84E5F68
	.incbin "baserom_jp.gba", 0x4e5f68, 0x9

	.globl gUnknown_84E5F71
gUnknown_84E5F71: @ 0x84E5F71
	.incbin "baserom_jp.gba", 0x4e5f71, 0x9

	.globl gUnknown_84E5F7A
gUnknown_84E5F7A: @ 0x84E5F7A
	.incbin "baserom_jp.gba", 0x4e5f7a, 0x9

	.globl gUnknown_84E5F83
gUnknown_84E5F83: @ 0x84E5F83
	.incbin "baserom_jp.gba", 0x4e5f83, 0x9

	.globl gUnknown_84E5F8C
gUnknown_84E5F8C: @ 0x84E5F8C
	.incbin "baserom_jp.gba", 0x4e5f8c, 0x9

	.globl gUnknown_84E5F95
gUnknown_84E5F95: @ 0x84E5F95
	.incbin "baserom_jp.gba", 0x4e5f95, 0x9

	.globl gUnknown_84E5F9E
gUnknown_84E5F9E: @ 0x84E5F9E
	.incbin "baserom_jp.gba", 0x4e5f9e, 0x9

	.globl gUnknown_84E5FA7
gUnknown_84E5FA7: @ 0x84E5FA7
	.incbin "baserom_jp.gba", 0x4e5fa7, 0x9

	.globl gUnknown_84E5FB0
gUnknown_84E5FB0: @ 0x84E5FB0
	.incbin "baserom_jp.gba", 0x4e5fb0, 0x10

	.globl gUnknown_84E5FC0
gUnknown_84E5FC0: @ 0x84E5FC0
	.incbin "baserom_jp.gba", 0x4e5fc0, 0x10

	.globl gUnknown_84E5FD0
gUnknown_84E5FD0: @ 0x84E5FD0
	.incbin "baserom_jp.gba", 0x4E5FD0, 0x24
	.globl gUnknown_84E5FF4
gUnknown_84E5FF4: @ 0x84E5FF4
	.incbin "baserom_jp.gba", 0x4e5ff4, 0x5

	.globl gUnknown_84E5FF9
gUnknown_84E5FF9: @ 0x84E5FF9
	.incbin "baserom_jp.gba", 0x4e5ff9, 0x5

	.globl gUnknown_84E5FFE
gUnknown_84E5FFE: @ 0x84E5FFE
	.incbin "baserom_jp.gba", 0x4e5ffe, 0x5

	.globl gUnknown_84E6003
gUnknown_84E6003: @ 0x84E6003
	.incbin "baserom_jp.gba", 0x4e6003, 0x5

	.globl gUnknown_84E6008
gUnknown_84E6008: @ 0x84E6008
	.incbin "baserom_jp.gba", 0x4e6008, 0x5

	.globl gUnknown_84E600D
gUnknown_84E600D: @ 0x84E600D
	.incbin "baserom_jp.gba", 0x4e600d, 0x5

	.globl gUnknown_84E6012
gUnknown_84E6012: @ 0x84E6012
	.incbin "baserom_jp.gba", 0x4e6012, 0x5

	.globl gUnknown_84E6017
gUnknown_84E6017: @ 0x84E6017
	.incbin "baserom_jp.gba", 0x4e6017, 0x5

	.globl gUnknown_84E601C
gUnknown_84E601C: @ 0x84E601C
	.incbin "baserom_jp.gba", 0x4e601c, 0x5

	.globl gUnknown_84E6021
gUnknown_84E6021: @ 0x84E6021
	.incbin "baserom_jp.gba", 0x4e6021, 0x5

	.globl gUnknown_84E6026
gUnknown_84E6026: @ 0x84E6026
	.incbin "baserom_jp.gba", 0x4e6026, 0x5

	.globl gUnknown_84E602B
gUnknown_84E602B: @ 0x84E602B
	.incbin "baserom_jp.gba", 0x4e602b, 0x5

	.globl gUnknown_84E6030
gUnknown_84E6030: @ 0x84E6030
	.incbin "baserom_jp.gba", 0x4e6030, 0x5

	.globl gUnknown_84E6035
gUnknown_84E6035: @ 0x84E6035
	.incbin "baserom_jp.gba", 0x4e6035, 0x5

	.globl gUnknown_84E603A
gUnknown_84E603A: @ 0x84E603A
	.incbin "baserom_jp.gba", 0x4e603a, 0x5

	.globl gUnknown_84E603F
gUnknown_84E603F: @ 0x84E603F
	.incbin "baserom_jp.gba", 0x4e603f, 0x5

	.globl gUnknown_84E6044
gUnknown_84E6044: @ 0x84E6044
	.incbin "baserom_jp.gba", 0x4e6044, 0x5

	.globl gUnknown_84E6049
gUnknown_84E6049: @ 0x84E6049
	.incbin "baserom_jp.gba", 0x4e6049, 0x5

	.globl gUnknown_84E604E
gUnknown_84E604E: @ 0x84E604E
	.incbin "baserom_jp.gba", 0x4e604e, 0x5

	.globl gUnknown_84E6053
gUnknown_84E6053: @ 0x84E6053
	.incbin "baserom_jp.gba", 0x4e6053, 0x5

	.globl gUnknown_84E6058
gUnknown_84E6058: @ 0x84E6058
	.incbin "baserom_jp.gba", 0x4e6058, 0x5

	.globl gUnknown_84E605D
gUnknown_84E605D: @ 0x84E605D
	.incbin "baserom_jp.gba", 0x4e605d, 0x5

	.globl gUnknown_84E6062
gUnknown_84E6062: @ 0x84E6062
	.incbin "baserom_jp.gba", 0x4e6062, 0x5

	.globl gUnknown_84E6067
gUnknown_84E6067: @ 0x84E6067
	.incbin "baserom_jp.gba", 0x4e6067, 0x5

	.globl gUnknown_84E606C
gUnknown_84E606C: @ 0x84E606C
	.incbin "baserom_jp.gba", 0x4e606c, 0x5

	.globl gUnknown_84E6071
gUnknown_84E6071: @ 0x84E6071
	.incbin "baserom_jp.gba", 0x4e6071, 0x5

	.globl gUnknown_84E6076
gUnknown_84E6076: @ 0x84E6076
	.incbin "baserom_jp.gba", 0x4e6076, 0x5

	.globl gUnknown_84E607B
gUnknown_84E607B: @ 0x84E607B
	.incbin "baserom_jp.gba", 0x4e607b, 0x8

	.globl gUnknown_84E6083
gUnknown_84E6083: @ 0x84E6083
	.incbin "baserom_jp.gba", 0x4e6083, 0x10

	.globl gUnknown_84E6093
gUnknown_84E6093: @ 0x84E6093
	.incbin "baserom_jp.gba", 0x4e6093, 0x11

	.globl gUnknown_84E60A4
gUnknown_84E60A4: @ 0x84E60A4
	.incbin "baserom_jp.gba", 0x4e60a4, 0x298

	.globl gUnknown_84E633C
gUnknown_84E633C: @ 0x84E633C
	.incbin "baserom_jp.gba", 0x4e633c, 0xd4

	.globl gUnknown_84E6410
gUnknown_84E6410: @ 0x84E6410
	.incbin "baserom_jp.gba", 0x4e6410, 0x6

	.globl gUnknown_84E6416
gUnknown_84E6416: @ 0x84E6416
	.incbin "baserom_jp.gba", 0x4e6416, 0x61a

	.globl gUnknown_84E6A30
gUnknown_84E6A30: @ 0x84E6A30
	.incbin "baserom_jp.gba", 0x4e6a30, 0x8

	.globl gUnknown_84E6A38
gUnknown_84E6A38: @ 0x84E6A38
	.incbin "baserom_jp.gba", 0x4e6a38, 0x18

	.globl gUnknown_84E6A50
gUnknown_84E6A50: @ 0x84E6A50
	.incbin "baserom_jp.gba", 0x4e6a50, 0x18

	.globl gUnknown_84E6A68
gUnknown_84E6A68: @ 0x84E6A68
	.incbin "baserom_jp.gba", 0x4e6a68, 0x10

	.globl gUnknown_84E6A78
gUnknown_84E6A78: @ 0x84E6A78
	.incbin "baserom_jp.gba", 0x4e6a78, 0x10

	.globl gUnknown_84E6A88
gUnknown_84E6A88: @ 0x84E6A88
	.incbin "baserom_jp.gba", 0x4e6a88, 0x10

	.globl gUnknown_84E6A98
gUnknown_84E6A98: @ 0x84E6A98
	.incbin "baserom_jp.gba", 0x4e6a98, 0x10

	.globl gUnknown_84E6AA8
gUnknown_84E6AA8: @ 0x84E6AA8
	.incbin "baserom_jp.gba", 0x4e6aa8, 0xc

	.globl gUnknown_84E6AB4
gUnknown_84E6AB4: @ 0x84E6AB4
	.incbin "baserom_jp.gba", 0x4e6ab4, 0x4

	.globl gUnknown_84E6AB8
gUnknown_84E6AB8: @ 0x84E6AB8
	.incbin "baserom_jp.gba", 0x4e6ab8, 0x10

	.globl gUnknown_84E6AC8
gUnknown_84E6AC8: @ 0x84E6AC8
	.incbin "baserom_jp.gba", 0x4e6ac8, 0xe0

	.globl gUnknown_84E6BA8
gUnknown_84E6BA8: @ 0x84E6BA8
	.incbin "baserom_jp.gba", 0x4e6ba8, 0x14

	.globl gUnknown_84E6BBC
gUnknown_84E6BBC: @ 0x84E6BBC
	.incbin "baserom_jp.gba", 0x4e6bbc, 0xa

	.globl sFigure8XOffsets
sFigure8XOffsets: @ 0x84E6BC6
	.byte 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01
	.byte 0x02, 0x02, 0x01, 0x02, 0x02, 0x01, 0x02, 0x02, 0x01, 0x02, 0x01, 0x01
	.byte 0x02, 0x01, 0x01, 0x02, 0x01, 0x01, 0x02, 0x01, 0x01, 0x02, 0x01, 0x01
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
	.byte 0x00, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.globl sFigure8YOffsets
sFigure8YOffsets: @ 0x84E6C0E
	.byte 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01
	.byte 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01
	.byte 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0xFF
	.byte 0x00, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE
	.byte 0xFC, 0xFA, 0xF8, 0xF6, 0xF5, 0xF4, 0xF4, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8
	.byte 0xFA, 0xFC, 0x00, 0x00, 0x00, 0xFE, 0xFD, 0xFC, 0xFB, 0xFA, 0xFA, 0xFA
	.byte 0xFB, 0xFB, 0xFC, 0xFD, 0xFE, 0x00, 0x00, 0x00, 0xFE, 0xFC, 0xFA, 0xF8
	.byte 0xF7, 0xF6, 0xF6, 0xF6, 0xF7, 0xF8, 0xFA, 0xFB, 0xFD, 0xFE, 0x00, 0x00
	.byte 0x00, 0x00

	.globl gUnknown_84E6C88
gUnknown_84E6C88: @ 0x84E6C88
	.incbin "baserom_jp.gba", 0x4e6c88, 0xc

	.globl gUnknown_84E6C94
gUnknown_84E6C94: @ 0x84E6C94
	.incbin "baserom_jp.gba", 0x4e6c94, 0x6

	.globl gUnknown_84E6C9A
gUnknown_84E6C9A: @ 0x84E6C9A
	.incbin "baserom_jp.gba", 0x4e6c9a, 0x4

	.globl gUnknown_84E6C9E
gUnknown_84E6C9E: @ 0x84E6C9E
	.incbin "baserom_jp.gba", 0x4e6c9e, 0x6

	.globl gUnknown_84E6CA4
gUnknown_84E6CA4: @ 0x84E6CA4
	.incbin "baserom_jp.gba", 0x4e6ca4, 0x4

	.globl gUnknown_84E6CA8
gUnknown_84E6CA8: @ 0x84E6CA8
	.incbin "baserom_jp.gba", 0x4e6ca8, 0xc

	.globl gUnknown_84E6CB4
gUnknown_84E6CB4: @ 0x84E6CB4
	.incbin "baserom_jp.gba", 0x4e6cb4, 0x2c

	.globl gTextWindowFrame1_Gfx
gTextWindowFrame1_Gfx: @ 0x84E6CE0
	.incbin "baserom_jp.gba", 0x4e6ce0, 0x1680

	.globl gTextWindowFrame1_Pal
gTextWindowFrame1_Pal: @ 0x84E8360
	.incbin "baserom_jp.gba", 0x4e8360, 0x280

	.globl gMessageBox_Gfx
gMessageBox_Gfx: @ 0x84E85E0
	.incbin "baserom_jp.gba", 0x4e85e0, 0x1c0

	.globl sTextWindowPalettes
sTextWindowPalettes: @ 0x84E87A0
	.incbin "baserom_jp.gba", 0x4e87a0, 0xa0

	.globl gUnknown_84E8840
gUnknown_84E8840: @ 0x84E8840
	.incbin "baserom_jp.gba", 0x4e8840, 0x20

	.globl sWindowFrames
sWindowFrames: @ 0x84E8860
	.incbin "baserom_jp.gba", 0x4e8860, 0xa0

	.globl gNullScriptPtr
gNullScriptPtr: @ 0x84E8900
	.incbin "baserom_jp.gba", 0x4e8900, 0x4

	.globl sScriptConditionTable
sScriptConditionTable: @ 0x84E8904
	.byte 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00
	.byte 0x00, 0x01, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00

	.globl sScriptStringVars
sScriptStringVars: @ 0x84E8918
	.incbin "baserom_jp.gba", 0x4e8918, 0xc

	.globl sCoordEventWeatherFuncs
sCoordEventWeatherFuncs: @ 0x84E8924
	.incbin "baserom_jp.gba", 0x4e8924, 0x68

	.globl sPerStepCallbacks
sPerStepCallbacks: @ 0x84E898C
	.incbin "baserom_jp.gba", 0x4e898c, 0x20

	.globl sHalfSubmergedBridgeMetatileOffsets
sHalfSubmergedBridgeMetatileOffsets: @ 0x84E89AC
	.incbin "baserom_jp.gba", 0x4e89ac, 0x20

	.globl sFullySubmergedBridgeMetatileOffsets
sFullySubmergedBridgeMetatileOffsets: @ 0x84E89CC
	.incbin "baserom_jp.gba", 0x4e89cc, 0x20

	.globl sFloatingBridgeMetatileOffsets
sFloatingBridgeMetatileOffsets: @ 0x84E89EC
	.incbin "baserom_jp.gba", 0x4e89ec, 0x20

	.globl sSootopolisGymIceRowVars
sSootopolisGymIceRowVars: @ 0x84E8A0C
	.hword 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x4001, 0x4002, 0x4003, 0x4004, 0x0000, 0x0000
	.hword 0x4005, 0x4006, 0x4007, 0x0000, 0x0000, 0x4008, 0x4009, 0x400A, 0x0000, 0x0000, 0x0000, 0x0000
	.hword 0x0000, 0x0000

	.globl sMuddySlopeMetatiles
sMuddySlopeMetatiles: @ 0x84E8A40
	.hword 0x00E8, 0x00EB, 0x00EA, 0x00E9

	.globl gResetRtcBgTemplates
gResetRtcBgTemplates: @ 0x84E8A48
	.incbin "baserom_jp.gba", 0x4e8a48, 0x4

	.globl gResetRtcWindowTemplates
gResetRtcWindowTemplates: @ 0x84E8A4C
	.incbin "baserom_jp.gba", 0x4e8a4c, 0x18

	.globl gResetRtcInputTimeWindow
gResetRtcInputTimeWindow: @ 0x84E8A64
	.incbin "baserom_jp.gba", 0x4e8a64, 0x8

	.globl gUnknown_84E8A6C
gUnknown_84E8A6C: @ 0x84E8A6C
	.string "にち$"

	.globl gUnknown_84E8A6F
gUnknown_84E8A6F: @ 0x84E8A6F
	.string ":$"

	.globl gUnknown_84E8A71
gUnknown_84E8A71: @ 0x84E8A71
	.byte 0x09, 0x50, 0x13, 0x02, 0xFF, 0x00, 0x00, 0x03, 0x00, 0x01, 0x00, 0x0F
	.byte 0x27, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x17
	.byte 0x00, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x3B
	.byte 0x00, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x3B
	.byte 0x00, 0x03, 0x05, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x04, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x22, 0x22, 0x02, 0x12
	.byte 0x11, 0x11, 0x02, 0x12, 0x11, 0x11, 0x02, 0x12, 0x11, 0x11, 0x02, 0x20
	.byte 0x11, 0x21, 0x00, 0x00, 0x12, 0x02, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x20, 0x22, 0x02, 0x00, 0x20, 0x11, 0x21, 0x00, 0x20
	.byte 0x11, 0x11, 0x02, 0x20, 0x11, 0x11, 0x21, 0x20, 0x11, 0x11, 0x02, 0x20
	.byte 0x11, 0x21, 0x00, 0x20, 0x22, 0x02, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x29
	.byte 0x25, 0x00, 0x00, 0xBC, 0x8A, 0x4E, 0x08, 0x20, 0x00, 0x00, 0x00, 0xDC
	.byte 0x8A, 0x4E, 0x08, 0x20, 0x00, 0x00, 0x00

	.globl gResetRtcArrowPalette
gResetRtcArrowPalette: @ 0x84E8B14
	.incbin "baserom_jp.gba", 0x4e8b14, 0x2c

	.globl gResetRtcArrowSpriteTemplate
gResetRtcArrowSpriteTemplate: @ 0x84E8B40
	.incbin "baserom_jp.gba", 0x4e8b40, 0x18

	.globl gUnknown_84E8B58
gUnknown_84E8B58: @ 0x84E8B58
	.incbin "baserom_jp.gba", 0x4e8b58, 0x4

	.globl gUnknown_84E8B5C
gUnknown_84E8B5C: @ 0x84E8B5C
	.incbin "baserom_jp.gba", 0x4e8b5c, 0x28

	.globl gUnknown_84E8B84
gUnknown_84E8B84: @ 0x84E8B84
	.string "サファリボール\n"
	.string "のこり　{B_COPY_VAR_1}コ$"
	.globl gUnknown_84E8B94
gUnknown_84E8B94: @ 0x84E8B94
	.incbin "baserom_jp.gba", 0x4e8b94, 0x8

	.globl gUnknown_84E8B9C
gUnknown_84E8B9C: @ 0x84E8B9C
	.incbin "baserom_jp.gba", 0x4e8b9c, 0x60

	.globl gUnknown_84E8BFC
gUnknown_84E8BFC: @ 0x84E8BFC
	.incbin "baserom_jp.gba", 0x4e8bfc, 0x20

	.globl gUnknown_84E8C1C
gUnknown_84E8C1C: @ 0x84E8C1C
	.incbin "baserom_jp.gba", 0x4e8c1c, 0x8

	.globl gUnknown_84E8C24
gUnknown_84E8C24: @ 0x84E8C24
	.incbin "baserom_jp.gba", 0x4e8c24, 0x8

	.globl gUnknown_84E8C2C
gUnknown_84E8C2C: @ 0x84E8C2C
	.incbin "baserom_jp.gba", 0x4e8c2c, 0x68

	.globl gUnknown_84E8C94
gUnknown_84E8C94: @ 0x84E8C94
	.incbin "baserom_jp.gba", 0x4e8c94, 0x4

	.globl gUnknown_84E8C98
gUnknown_84E8C98: @ 0x84E8C98
	.incbin "baserom_jp.gba", 0x4e8c98, 0x10

	.globl gUnknown_84E8CA8
gUnknown_84E8CA8: @ 0x84E8CA8
	.incbin "baserom_jp.gba", 0x4e8ca8, 0x8

	.globl gUnknown_84E8CB0
gUnknown_84E8CB0: @ 0x84E8CB0
	.string "しゅじんこう$"
	.globl gUnknown_84E8CB7
gUnknown_84E8CB7: @ 0x84E8CB7
	.string "もっているバッジ$"
	.globl gUnknown_84E8CC0
gUnknown_84E8CC0: @ 0x84E8CC0
	.string "ポケモンずかん$"
	.globl gUnknown_84E8CC8
gUnknown_84E8CC8: @ 0x84E8CC8
	.incbin "baserom_jp.gba", 0x4e8cc8, 0x1a8

	.globl gUnknown_84E8E70
gUnknown_84E8E70: @ 0x84E8E70
	.incbin "baserom_jp.gba", 0x4e8e70, 0xb60

	.globl gUnknown_84E99D0
gUnknown_84E99D0: @ 0x84E99D0
	.incbin "baserom_jp.gba", 0x4e99d0, 0x908

	.globl gUnknown_84EA2D8
gUnknown_84EA2D8: @ 0x84EA2D8
	.incbin "baserom_jp.gba", 0x4ea2d8, 0x9a8

	.globl gUnknown_84EAC80
gUnknown_84EAC80: @ 0x84EAC80
	.incbin "baserom_jp.gba", 0x4eac80, 0x8e0

	.globl gUnknown_84EB560
gUnknown_84EB560: @ 0x84EB560
	.incbin "baserom_jp.gba", 0x4eb560, 0x320

	.globl gUnknown_84EB880
gUnknown_84EB880: @ 0x84EB880
	.incbin "baserom_jp.gba", 0x4eb880, 0x510

	.globl gUnknown_84EBD90
gUnknown_84EBD90: @ 0x84EBD90
	.incbin "baserom_jp.gba", 0x4ebd90, 0x210

	.globl gUnknown_84EBFA0
gUnknown_84EBFA0: @ 0x84EBFA0
	.incbin "baserom_jp.gba", 0x4ebfa0, 0xb50

	.globl gUnknown_84ECAF0
gUnknown_84ECAF0: @ 0x84ECAF0
	.incbin "baserom_jp.gba", 0x4ecaf0, 0x210

	.globl gUnknown_84ECD00
gUnknown_84ECD00: @ 0x84ECD00
	.incbin "baserom_jp.gba", 0x4ecd00, 0x810

	.globl gUnknown_84ED510
gUnknown_84ED510: @ 0x84ED510
	.incbin "baserom_jp.gba", 0x4ed510, 0x540

	.globl gUnknown_84EDA50
gUnknown_84EDA50: @ 0x84EDA50
	.incbin "baserom_jp.gba", 0x4eda50, 0x20

	.globl gUnknown_84EDA70
gUnknown_84EDA70: @ 0x84EDA70
	.incbin "baserom_jp.gba", 0x4eda70, 0x20

	.globl gUnknown_84EDA90
gUnknown_84EDA90: @ 0x84EDA90
	.incbin "baserom_jp.gba", 0x4eda90, 0x30

	.globl gUnknown_84EDAC0
gUnknown_84EDAC0: @ 0x84EDAC0
	.incbin "baserom_jp.gba", 0x4edac0, 0x30

	.globl gUnknown_84EDAF0
gUnknown_84EDAF0: @ 0x84EDAF0
	.incbin "baserom_jp.gba", 0x4edaf0, 0x10

	.globl gUnknown_84EDB00
gUnknown_84EDB00: @ 0x84EDB00
	.incbin "baserom_jp.gba", 0x4edb00, 0x410

	.globl gUnknown_84EDF10
gUnknown_84EDF10: @ 0x84EDF10
	.incbin "baserom_jp.gba", 0x4edf10, 0x20

	.globl gUnknown_84EDF30
gUnknown_84EDF30: @ 0x84EDF30
	.incbin "baserom_jp.gba", 0x4edf30, 0x140

	.globl gUnknown_84EE070
gUnknown_84EE070: @ 0x84EE070
	.incbin "baserom_jp.gba", 0x4ee070, 0x428

	.globl gUnknown_84EE498
gUnknown_84EE498: @ 0x84EE498
	.incbin "baserom_jp.gba", 0x4ee498, 0x430

	.globl gUnknown_84EE8C8
gUnknown_84EE8C8: @ 0x84EE8C8
	.incbin "baserom_jp.gba", 0x4ee8c8, 0x20

	.globl gUnknown_84EE8E8
gUnknown_84EE8E8: @ 0x84EE8E8
	.incbin "baserom_jp.gba", 0x4ee8e8, 0x320

	.globl gUnknown_84EEC08
gUnknown_84EEC08: @ 0x84EEC08
	.incbin "baserom_jp.gba", 0x4eec08, 0x310

	.globl gUnknown_84EEF18
gUnknown_84EEF18: @ 0x84EEF18
	.incbin "baserom_jp.gba", 0x4eef18, 0x310

	.globl gUnknown_84EF228
gUnknown_84EF228: @ 0x84EF228
	.incbin "baserom_jp.gba", 0x4ef228, 0x210

	.globl gUnknown_84EF438
gUnknown_84EF438: @ 0x84EF438
	.incbin "baserom_jp.gba", 0x4ef438, 0x110

	.globl gUnknown_84EF548
gUnknown_84EF548: @ 0x84EF548
	.incbin "baserom_jp.gba", 0x4ef548, 0xc08

	.globl gUnknown_84F0150
gUnknown_84F0150: @ 0x84F0150
	.incbin "baserom_jp.gba", 0x4f0150, 0xc

	.globl gUnknown_84F015C
gUnknown_84F015C: @ 0x84F015C
	.incbin "baserom_jp.gba", 0x4f015c, 0x1ac

	.globl gUnknown_84F0308
gUnknown_84F0308: @ 0x84F0308
	.incbin "baserom_jp.gba", 0x4f0308, 0x10

	.globl gUnknown_84F0318
gUnknown_84F0318: @ 0x84F0318
	.incbin "baserom_jp.gba", 0x4f0318, 0x428

	.globl gUnknown_84F0740
gUnknown_84F0740: @ 0x84F0740
	.incbin "baserom_jp.gba", 0x4f0740, 0x268

	.globl gUnknown_84F09A8
gUnknown_84F09A8: @ 0x84F09A8
	.incbin "baserom_jp.gba", 0x4f09a8, 0x8028

	.globl gUnknown_84F89D0
gUnknown_84F89D0: @ 0x84F89D0
	.incbin "baserom_jp.gba", 0x4f89d0, 0x45a0

	.globl gUnknown_84FCF70
gUnknown_84FCF70: @ 0x84FCF70
	.incbin "baserom_jp.gba", 0x4fcf70, 0xc

	.globl gUnknown_84FCF7C
gUnknown_84FCF7C: @ 0x84FCF7C
	.incbin "baserom_jp.gba", 0x4fcf7c, 0xc

	.globl gUnknown_84FCF88
gUnknown_84FCF88: @ 0x84FCF88
	.incbin "baserom_jp.gba", 0x4fcf88, 0x10

	.globl gUnknown_84FCF98
gUnknown_84FCF98: @ 0x84FCF98
	.incbin "baserom_jp.gba", 0x4fcf98, 0x10

	.globl gUnknown_84FCFA8
gUnknown_84FCFA8: @ 0x84FCFA8
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x05, 0x05, 0x05, 0x05, 0x0B, 0x0B
	.byte 0x0B, 0x0B, 0x0B, 0x10, 0x10, 0x10, 0x10, 0x10, 0x15, 0x15, 0x15, 0x15
	.byte 0x15, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1F, 0x1F

	.globl sFanfares
sFanfares: @ 0x84FCFC8
	.incbin "baserom_jp.gba", 0x4fcfc8, 0x48

	.globl gUnknown_84FD010
	.globl gUnknown_84FD010
gUnknown_84FD010: @ 0x4FD010
	.incbin "baserom_jp.gba", 0x4fd010, 0x30

	.globl gUnknown_84FD040
gUnknown_84FD040: @ 0x4FD040
	.incbin "baserom_jp.gba", 0x4fd040, 0x210


	.globl gBattleAnimPicTable
gBattleAnimPicTable: @ 0x84FD250
	.incbin "baserom_jp.gba", 0x4fd250, 0x1d0

	.globl gUnknown_84FD420
gUnknown_84FD420: @ 0x84FD420
	.incbin "baserom_jp.gba", 0x4fd420, 0x270

	.globl gUnknown_84FD690
gUnknown_84FD690: @ 0x84FD690
	.incbin "baserom_jp.gba", 0x4fd690, 0x308

	.globl gUnknown_84FD998
gUnknown_84FD998: @ 0x84FD998
	.incbin "baserom_jp.gba", 0x4fd998, 0x120

	.globl gUnknown_84FDAB8
	.globl gUnknown_84FDAB8
gUnknown_84FDAB8: @ 0x4FDAB8
	.incbin "baserom_jp.gba", 0x4fdab8, 0xa0

	.globl gBattleAnimPaletteTable
gBattleAnimPaletteTable: @ 0x4FDB58
	.incbin "baserom_jp.gba", 0x4fdb58, 0x1d0


	.globl gUnknown_84FDD28
gUnknown_84FDD28: @ 0x84FDD28
	.incbin "baserom_jp.gba", 0x4fdd28, 0x270

	.globl gUnknown_84FDF98
gUnknown_84FDF98: @ 0x84FDF98
	.incbin "baserom_jp.gba", 0x4fdf98, 0x308

	.globl gUnknown_84FE2A0
gUnknown_84FE2A0: @ 0x84FE2A0
	.incbin "baserom_jp.gba", 0x4fe2a0, 0x120

	.globl gUnknown_84FE3C0
gUnknown_84FE3C0: @ 0x84FE3C0
	.incbin "baserom_jp.gba", 0x4fe3c0, 0xa0

	.globl gUnknown_84FE460
gUnknown_84FE460: @ 0x84FE460
	.incbin "baserom_jp.gba", 0x4fe460, 0x144

	.globl gUnknown_84FE5A4
gUnknown_84FE5A4: @ 0x84FE5A4
	.incbin "baserom_jp.gba", 0x4fe5a4, 0xc0

	.globl sBattlerCoords
sBattlerCoords: @ 0x84FE664
	.incbin "baserom_jp.gba", 0x4fe664, 0x20

	.globl gCastformFrontSpriteCoords
gCastformFrontSpriteCoords: @ 0x84FE684
	.byte 68 @ entry 0 size
	.byte 17 @ entry 0 y_offset
	.hword 0
	.byte 102 @ entry 1 size
	.byte 9 @ entry 1 y_offset
	.hword 0
	.byte 70 @ entry 2 size
	.byte 9 @ entry 2 y_offset
	.hword 0
	.byte 134 @ entry 3 size
	.byte 8 @ entry 3 y_offset
	.hword 0

	.globl sCastformElevations
sCastformElevations: @ 0x84FE694
	.byte 0x0D, 0x0E, 0x0D, 0x0D

	.globl sCastformBackSpriteYCoords
sCastformBackSpriteYCoords: @ 0x84FE698
	.byte 0x00, 0x00, 0x00, 0x00

	.globl sSpriteTemplates_MoveEffectMons
sSpriteTemplates_MoveEffectMons: @ 0x84FE69C
	.incbin "baserom_jp.gba", 0x4fe69c, 0x30

	.globl sSpriteSheets_MoveEffectMons
sSpriteSheets_MoveEffectMons: @ 0x84FE6CC
	.incbin "baserom_jp.gba", 0x4FE6CC, 0x10
	.globl PETALBURG_CITY_EventObjects
PETALBURG_CITY_EventObjects: @ 0x084FE6DC
	object_event 1, 26, 0, 16, 18, 3, 2, 1, 1, 0, 0, PetalburgCity_EventScript_001DB919, 0x02D8
	object_event 2, 135, 0, 15, 10, 3, 7, 0, 0, 0, 0, 0x00000000, 0x02D6
	object_event 3, 7, 0, 8, 22, 3, 8, 0, 0, 0, 0, PetalburgCity_EventScript_001DB902, 0x0000
	object_event 4, 48, 0, 20, 10, 3, 3, 0, 1, 0, 0, PetalburgCity_EventScript_001DB9A4, 0x0000
	object_event 5, 25, 0, 15, 10, 3, 7, 0, 0, 0, 0, 0x00000000, 0x033E
	object_event 6, 59, 0, 19, 2, 3, 1, 0, 0, 0, 0, 0x08256E0B, 0x040F
	object_event 7, 59, 0, 3, 28, 3, 1, 0, 0, 0, 0, 0x08256E18, 0x0410
	object_event 8, 9, 0, 12, 15, 3, 1, 0, 0, 0, 0, PetalburgCity_EventScript_001DBD4A, 0x0000
	object_event 9, 219, 0, 13, 12, 3, 1, 1, 1, 0, 0, 0x00000000, 0x03E3
	.globl PETALBURG_CITY_EventWarps
PETALBURG_CITY_EventWarps: @ 0x084FE7B4
	warp_def 10, 19, 0, 0, MAP_PETALBURG_CITY_HOUSE1
	warp_def 7, 5, 0, 0, MAP_PETALBURG_CITY_WALLYS_HOUSE
	warp_def 15, 8, 0, 0, MAP_PETALBURG_CITY_GYM
	warp_def 20, 16, 0, 0, MAP_PETALBURG_CITY_POKEMON_CENTER_1F
	warp_def 20, 24, 0, 0, MAP_PETALBURG_CITY_HOUSE2
	warp_def 25, 12, 0, 0, MAP_PETALBURG_CITY_MART
	.globl PETALBURG_CITY_EventCoordEvents
PETALBURG_CITY_EventCoordEvents: @ 0x084FE7E4
	coord_event 8, 10, 3, 16471, 0, PetalburgCity_EventScript_001DB9B6
	coord_event 8, 11, 3, 16471, 0, PetalburgCity_EventScript_001DB9C2
	coord_event 8, 12, 3, 16471, 0, PetalburgCity_EventScript_001DB9CE
	coord_event 8, 13, 3, 16471, 0, PetalburgCity_EventScript_001DB9DA
	coord_event 4, 10, 3, 16585, 0, PetalburgCity_EventScript_001DBBAD
	coord_event 4, 11, 3, 16585, 0, PetalburgCity_EventScript_001DBBC3
	coord_event 4, 12, 3, 16585, 0, PetalburgCity_EventScript_001DBBD9
	coord_event 4, 13, 3, 16585, 0, PetalburgCity_EventScript_001DBBEF
	.globl PETALBURG_CITY_EventBgEvents
PETALBURG_CITY_EventBgEvents: @ 0x084FE864
	bg_event 17, 10, 0, 0, PetalburgCity_EventScript_001DB992, 0, 0
	bg_event 26, 12, 0, 1, 0x08242EF6, 0, 0
	bg_event 21, 16, 0, 1, 0x08242EFF, 0, 0
	bg_event 17, 16, 0, 0, PetalburgCity_EventScript_001DB99B, 0, 0
	bg_event 22, 16, 0, 1, 0x08242EFF, 0, 0
	bg_event 27, 12, 0, 1, 0x08242EF6, 0, 0
	bg_event 8, 9, 0, 0, PetalburgCity_EventScript_001DB9AD, 0, 0
	bg_event 11, 29, 3, 7, 0x0044, 0x5F, 0x00
	.globl gMapEvents_PETALBURG_CITY
gMapEvents_PETALBURG_CITY: @ 0x084FE8C4
	map_events PETALBURG_CITY_EventObjects, PETALBURG_CITY_EventWarps, PETALBURG_CITY_EventCoordEvents, PETALBURG_CITY_EventBgEvents
	.globl SLATEPORT_CITY_EventObjects
SLATEPORT_CITY_EventObjects: @ 0x084FE8D8
	object_event 1, 17, 0, 21, 11, 3, 2, 1, 1, 0, 0, SlateportCity_EventScript_001DC24D, 0x0000
	object_event 2, 19, 0, 34, 29, 3, 5, 1, 0, 0, 0, SlateportCity_EventScript_001DC26A, 0x0000
	object_event 3, 15, 0, 5, 13, 3, 2, 1, 2, 0, 0, SlateportCity_EventScript_001DC22C, 0x0000
	object_event 4, 26, 0, 26, 29, 3, 1, 0, 0, 0, 0, SlateportCity_EventScript_001DC28B, 0x0000
	object_event 5, 118, 0, 31, 27, 3, 7, 0, 0, 0, 0, SlateportCity_EventScript_001DC37D, 0x0372
	object_event 6, 27, 0, 5, 43, 3, 8, 0, 0, 0, 0, SlateportCity_EventScript_001DC1B6, 0x0000
	object_event 7, 30, 0, 20, 37, 3, 1, 1, 1, 0, 0, SlateportCity_EventScript_001DC1D7, 0x0000
	object_event 8, 8, 0, 8, 42, 3, 2, 1, 1, 0, 0, SlateportCity_EventScript_001DC1F8, 0x0000
	object_event 9, 110, 0, 29, 13, 3, 9, 0, 0, 0, 0, SlateportCity_EventScript_001DC6C7, 0x0343
	object_event 10, 68, 0, 28, 14, 3, 7, 0, 0, 0, 0, SlateportCity_EventScript_001DC6D0, 0x0343
	object_event 11, 46, 0, 28, 13, 3, 10, 0, 0, 0, 0, SlateportCity_EventScript_001DC56C, 0x0348
	object_event 12, 49, 0, 37, 41, 3, 10, 0, 0, 0, 0, SlateportCity_EventScript_001DC359, 0x0000
	object_event 13, 49, 0, 28, 46, 3, 5, 1, 0, 0, 0, SlateportCity_EventScript_001DC362, 0x0000
	object_event 14, 18, 0, 9, 50, 3, 3, 0, 1, 0, 0, SlateportCity_EventScript_001DC36B, 0x0000
	object_event 15, 33, 0, 16, 46, 3, 2, 1, 1, 0, 0, SlateportCity_EventScript_001DC374, 0x0000
	object_event 16, 39, 0, 8, 24, 3, 3, 0, 1, 0, 0, SlateportCity_EventScript_001DC32F, 0x0000
	object_event 17, 34, 0, 15, 31, 3, 1, 0, 0, 0, 0, SlateportCity_EventScript_001DC350, 0x0000
	object_event 18, 117, 0, 30, 27, 3, 10, 0, 0, 0, 0, SlateportCity_EventScript_001DC394, 0x0372
	object_event 19, 117, 0, 29, 27, 3, 10, 0, 0, 0, 0, SlateportCity_EventScript_001DC3AB, 0x0372
	object_event 20, 83, 0, 6, 38, 3, 10, 0, 0, 0, 0, SlateportCity_EventScript_001DC50C, 0x0000
	object_event 21, 83, 0, 5, 51, 3, 8, 0, 0, 0, 0, SlateportCity_EventScript_001DC4DE, 0x0000
	object_event 22, 66, 0, 34, 51, 3, 8, 0, 0, 0, 0, SlateportCity_EventScript_001DC6D9, 0x0000
	object_event 23, 34, 0, 4, 47, 3, 8, 0, 0, 0, 0, SlateportCity_EventScript_001DC158, 0x0000
	object_event 24, 83, 0, 11, 47, 3, 8, 1, 1, 0, 0, SlateportCity_EventScript_001DC54C, 0x03B4
	object_event 25, 25, 0, 5, 47, 3, 8, 1, 1, 0, 0, SlateportCity_EventScript_001DC12F, 0x0000
	object_event 26, 117, 0, 22, 27, 3, 10, 1, 1, 0, 0, SlateportCity_EventScript_001DC3C2, 0x0372
	object_event 27, 117, 0, 23, 27, 3, 7, 1, 1, 0, 0, SlateportCity_EventScript_001DC3D9, 0x0372
	object_event 28, 117, 0, 24, 27, 3, 10, 1, 1, 0, 0, SlateportCity_EventScript_001DC3F0, 0x0372
	object_event 29, 117, 0, 21, 26, 3, 10, 1, 1, 0, 0, SlateportCity_EventScript_001DC407, 0x0372
	object_event 30, 117, 0, 20, 26, 3, 10, 1, 1, 0, 0, SlateportCity_EventScript_001DC41E, 0x0372
	object_event 31, 117, 0, 26, 27, 3, 7, 1, 1, 0, 0, SlateportCity_EventScript_001DC435, 0x0372
	object_event 32, 117, 0, 28, 27, 3, 7, 1, 1, 0, 0, SlateportCity_EventScript_001DC4BE, 0x0372
	object_event 33, 117, 0, 25, 27, 3, 7, 1, 1, 0, 0, SlateportCity_EventScript_001DC4C7, 0x0372
	object_event 34, 18, 0, 11, 37, 3, 9, 1, 2, 0, 0, SlateportCity_EventScript_001DC6E2, 0x0000
	object_event 35, 219, 0, 10, 12, 0, 8, 1, 2, 0, 0, 0x00000000, 0x02ED
	.globl SLATEPORT_CITY_EventWarps
SLATEPORT_CITY_EventWarps: @ 0x084FEC20
	warp_def 19, 19, 0, 0, MAP_SLATEPORT_CITY_POKEMON_CENTER_1F
	warp_def 13, 26, 0, 0, MAP_SLATEPORT_CITY_MART
	warp_def 26, 38, 0, 0, MAP_SLATEPORT_CITY_STERNS_SHIPYARD_1F
	warp_def 10, 12, 0, 0, MAP_SLATEPORT_CITY_BATTLE_TENT_LOBBY
	warp_def 4, 26, 0, 0, MAP_SLATEPORT_CITY_POKEMON_FAN_CLUB
	warp_def 30, 26, 0, 0, MAP_SLATEPORT_CITY_OCEANIC_MUSEUM_1F
	warp_def 5, 19, 0, 0, MAP_SLATEPORT_CITY_NAME_RATERS_HOUSE
	warp_def 31, 26, 0, 1, MAP_SLATEPORT_CITY_OCEANIC_MUSEUM_1F
	warp_def 28, 12, 0, 0, MAP_SLATEPORT_CITY_HARBOR
	warp_def 40, 7, 0, 2, MAP_SLATEPORT_CITY_HARBOR
	warp_def 21, 44, 0, 0, MAP_SLATEPORT_CITY_HOUSE
	.globl SLATEPORT_CITY_EventCoordEvents
SLATEPORT_CITY_EventCoordEvents: @ 0x084FEC78
	coord_event 10, 13, 3, 16594, 2, SlateportCity_EventScript_001DC950
	.globl SLATEPORT_CITY_EventBgEvents
SLATEPORT_CITY_EventBgEvents: @ 0x084FEC88
	bg_event 8, 19, 0, 0, SlateportCity_EventScript_001DC326, 0, 0
	bg_event 20, 19, 0, 1, 0x08242EFF, 0, 0
	bg_event 21, 19, 0, 1, 0x08242EFF, 0, 0
	bg_event 14, 26, 0, 1, 0x08242EF6, 0, 0
	bg_event 24, 12, 0, 0, SlateportCity_EventScript_001DC308, 0, 0
	bg_event 15, 26, 0, 1, 0x08242EF6, 0, 0
	bg_event 14, 51, 0, 0, SlateportCity_EventScript_001DC2FF, 0, 0
	bg_event 26, 26, 0, 0, SlateportCity_EventScript_001DC2ED, 0, 0
	bg_event 16, 22, 0, 0, SlateportCity_EventScript_001DC2F6, 0, 0
	bg_event 8, 26, 0, 0, SlateportCity_EventScript_001DC2E4, 0, 0
	bg_event 7, 13, 0, 0, SlateportCity_EventScript_001DC2AA, 0, 0
	bg_event 23, 38, 0, 0, SlateportCity_EventScript_001DC2B3, 0, 0
	bg_event 10, 36, 0, 1, SlateportCity_EventScript_001DC9B7, 0, 0
	.globl gMapEvents_SLATEPORT_CITY
gMapEvents_SLATEPORT_CITY: @ 0x084FED24
	map_events SLATEPORT_CITY_EventObjects, SLATEPORT_CITY_EventWarps, SLATEPORT_CITY_EventCoordEvents, SLATEPORT_CITY_EventBgEvents
	.globl MAUVILLE_CITY_EventObjects
MAUVILLE_CITY_EventObjects: @ 0x084FED38
	object_event 1, 13, 0, 29, 16, 3, 5, 1, 1, 0, 0, MauvilleCity_EventScript_001DD9EC, 0x0000
	object_event 2, 15, 0, 24, 10, 3, 5, 1, 0, 0, 0, MauvilleCity_EventScript_001DDA07, 0x0000
	object_event 3, 39, 0, 14, 11, 3, 10, 0, 0, 0, 0, MauvilleCity_EventScript_001DD9F5, 0x0000
	object_event 4, 26, 0, 18, 6, 3, 1, 0, 0, 0, 0, MauvilleCity_EventScript_001DD9FE, 0x0000
	object_event 5, 38, 0, 17, 14, 3, 8, 0, 0, 0, 0, MauvilleCity_EventScript_001DDA34, 0x0000
	object_event 6, 135, 0, 8, 6, 3, 7, 0, 0, 0, 0, MauvilleCity_EventScript_001DDA8B, 0x0324
	object_event 7, 25, 0, 9, 6, 3, 9, 0, 0, 0, 0, MauvilleCity_EventScript_001DDA56, 0x0325
	object_event 8, 127, 0, 29, 9, 3, 1, 0, 0, 0, 0, MauvilleCity_EventScript_001DDD73, 0x0390
	object_event 9, 59, 0, 28, 19, 3, 1, 1, 1, 0, 0, 0x08256E25, 0x045C
	object_event 10, 17, 0, 13, 7, 3, 9, 0, 0, 0, 0, 0x0827689A, 0x0000
	object_event 11, 219, 0, 12, 14, 3, 7, 0, 0, 0, 0, 0x00000000, 0x02FD
	.globl MAUVILLE_CITY_EventWarps
MAUVILLE_CITY_EventWarps: @ 0x084FEE40
	warp_def 8, 5, 0, 0, MAP_MAUVILLE_CITY_GYM
	warp_def 22, 5, 0, 0, MAP_MAUVILLE_CITY_POKEMON_CENTER_1F
	warp_def 35, 5, 0, 0, MAP_MAUVILLE_CITY_BIKE_SHOP
	warp_def 23, 14, 0, 0, MAP_MAUVILLE_CITY_MART
	warp_def 32, 14, 0, 0, MAP_MAUVILLE_CITY_HOUSE1
	warp_def 8, 13, 0, 0, MAP_MAUVILLE_CITY_GAME_CORNER
	warp_def 19, 14, 0, 0, MAP_MAUVILLE_CITY_HOUSE2
	.globl MAUVILLE_CITY_EventBgEvents
MAUVILLE_CITY_EventBgEvents: @ 0x084FEE78
	bg_event 23, 5, 0, 1, 0x08242EFF, 0, 0
	bg_event 11, 6, 3, 0, MauvilleCity_EventScript_001DDA19, 0, 0
	bg_event 24, 14, 0, 1, 0x08242EF6, 0, 0
	bg_event 25, 14, 0, 1, 0x08242EF6, 0, 0
	bg_event 24, 5, 0, 1, 0x08242EFF, 0, 0
	bg_event 19, 7, 0, 0, MauvilleCity_EventScript_001DDA10, 0, 0
	bg_event 33, 6, 0, 0, MauvilleCity_EventScript_001DDA22, 0, 0
	bg_event 11, 15, 0, 0, MauvilleCity_EventScript_001DDA2B, 0, 0
	.globl gMapEvents_MAUVILLE_CITY
gMapEvents_MAUVILLE_CITY: @ 0x084FEED8
	map_events MAUVILLE_CITY_EventObjects, MAUVILLE_CITY_EventWarps, 0, MAUVILLE_CITY_EventBgEvents
	.globl RUSTBORO_CITY_EventObjects
RUSTBORO_CITY_EventObjects: @ 0x084FEEEC
	object_event 1, 34, 0, 22, 34, 3, 3, 0, 1, 0, 0, RustboroCity_EventScript_001DE8C3, 0x0000
	object_event 2, 17, 0, 19, 13, 3, 1, 1, 1, 0, 0, RustboroCity_EventScript_001DE898, 0x0000
	object_event 3, 5, 0, 25, 37, 3, 7, 0, 0, 0, 0, RustboroCity_EventScript_001DE913, 0x0000
	object_event 4, 6, 0, 21, 46, 3, 3, 0, 1, 0, 0, RustboroCity_EventScript_001DE90A, 0x0000
	object_event 5, 9, 0, 12, 45, 3, 1, 0, 0, 0, 0, RustboroCity_EventScript_001DE8EB, 0x0000
	object_event 6, 33, 0, 26, 23, 3, 1, 1, 1, 0, 0, RustboroCity_EventScript_001DE8CC, 0x0000
	object_event 7, 11, 0, 24, 51, 3, 10, 0, 0, 0, 0, RustboroCity_EventScript_001DE95B, 0x0000
	object_event 8, 12, 0, 25, 51, 3, 9, 0, 0, 0, 0, RustboroCity_EventScript_001DE971, 0x0000
	object_event 9, 23, 0, 30, 10, 3, 10, 1, 1, 0, 0, RustboroCity_EventScript_001DEB16, 0x02DC
	object_event 10, 117, 0, 13, 21, 3, 10, 0, 0, 0, 0, 0x00000000, 0x02DB
	object_event 11, 116, 0, 13, 34, 3, 2, 1, 1, 0, 0, RustboroCity_EventScript_001DE8B7, 0x0000
	object_event 12, 59, 0, 36, 51, 3, 1, 0, 0, 0, 0, 0x08256E32, 0x0411
	object_event 13, 65, 0, 19, 27, 3, 8, 0, 1, 0, 0, RustboroCity_EventScript_001DE987, 0x0000
	object_event 14, 240, 0, 16, 50, 3, 1, 1, 1, 0, 0, RustboroCity_EventScript_001DEDF1, 0x032E
	object_event 15, 46, 0, 11, 15, 0, 1, 1, 1, 0, 0, 0x00000000, 0x034C
	object_event 16, 7, 0, 31, 36, 3, 1, 0, 1, 0, 0, RustboroCity_EventScript_001DF26F, 0x0000
	.globl RUSTBORO_CITY_EventWarps
RUSTBORO_CITY_EventWarps: @ 0x084FF06C
	warp_def 27, 19, 0, 0, MAP_RUSTBORO_CITY_GYM
	warp_def 13, 30, 0, 0, MAP_RUSTBORO_CITY_FLAT1_1F
	warp_def 16, 45, 0, 0, MAP_RUSTBORO_CITY_MART
	warp_def 16, 38, 0, 0, MAP_RUSTBORO_CITY_POKEMON_CENTER_1F
	warp_def 27, 34, 0, 0, MAP_RUSTBORO_CITY_POKEMON_SCHOOL
	warp_def 11, 15, 0, 0, MAP_RUSTBORO_CITY_DEVON_CORP_1F
	warp_def 12, 15, 0, 1, MAP_RUSTBORO_CITY_DEVON_CORP_1F
	warp_def 33, 19, 0, 0, MAP_RUSTBORO_CITY_HOUSE1
	warp_def 9, 38, 0, 0, MAP_RUSTBORO_CITY_CUTTERS_HOUSE
	warp_def 30, 28, 0, 0, MAP_RUSTBORO_CITY_HOUSE2
	warp_def 5, 51, 0, 0, MAP_RUSTBORO_CITY_FLAT2_1F
	warp_def 26, 46, 0, 0, MAP_RUSTBORO_CITY_HOUSE3
	.globl RUSTBORO_CITY_EventCoordEvents
RUSTBORO_CITY_EventCoordEvents: @ 0x084FF0CC
	coord_event 23, 20, 3, 16474, 1, RustboroCity_EventScript_001DE993
	coord_event 23, 21, 3, 16474, 1, RustboroCity_EventScript_001DE9AA
	coord_event 23, 22, 3, 16474, 1, RustboroCity_EventScript_001DE9C1
	coord_event 23, 23, 3, 16474, 1, RustboroCity_EventScript_001DE9D8
	coord_event 23, 24, 3, 16474, 1, RustboroCity_EventScript_001DE9EF
	coord_event 30, 9, 3, 16474, 2, RustboroCity_EventScript_001DEB37
	coord_event 29, 10, 3, 16474, 2, RustboroCity_EventScript_001DEB43
	coord_event 30, 11, 3, 16474, 2, RustboroCity_EventScript_001DEB4F
	coord_event 30, 12, 3, 16474, 2, RustboroCity_EventScript_001DEB5B
	coord_event 30, 9, 3, 16474, 4, RustboroCity_EventScript_001DEC64
	coord_event 31, 10, 3, 16474, 4, RustboroCity_EventScript_001DEC70
	coord_event 30, 11, 3, 16474, 4, RustboroCity_EventScript_001DEC7C
	coord_event 30, 12, 3, 16474, 4, RustboroCity_EventScript_001DEC88
	coord_event 12, 53, 3, 16474, 7, RustboroCity_EventScript_001DEE2C
	coord_event 13, 53, 3, 16474, 7, RustboroCity_EventScript_001DEE6C
	coord_event 14, 53, 3, 16474, 7, RustboroCity_EventScript_001DEEAC
	coord_event 15, 53, 3, 16474, 7, RustboroCity_EventScript_001DEEEC
	coord_event 16, 53, 3, 16474, 7, RustboroCity_EventScript_001DEF2C
	coord_event 17, 53, 3, 16474, 7, RustboroCity_EventScript_001DEF6C
	coord_event 18, 53, 3, 16474, 7, RustboroCity_EventScript_001DEFAC
	coord_event 19, 53, 3, 16474, 7, RustboroCity_EventScript_001DEFEC
	.globl RUSTBORO_CITY_EventBgEvents
RUSTBORO_CITY_EventBgEvents: @ 0x084FF21C
	bg_event 23, 19, 0, 0, RustboroCity_EventScript_001DE92E, 0, 0
	bg_event 25, 35, 0, 0, RustboroCity_EventScript_001DE949, 0, 0
	bg_event 17, 45, 0, 1, 0x08242EF6, 0, 0
	bg_event 18, 38, 0, 1, 0x08242EFF, 0, 0
	bg_event 19, 49, 0, 0, RustboroCity_EventScript_001DE940, 0, 0
	bg_event 18, 45, 0, 1, 0x08242EF6, 0, 0
	bg_event 17, 38, 0, 1, 0x08242EFF, 0, 0
	bg_event 17, 20, 0, 0, RustboroCity_EventScript_001DE925, 0, 0
	bg_event 30, 8, 0, 0, RustboroCity_EventScript_001DE91C, 0, 0
	bg_event 12, 38, 3, 0, RustboroCity_EventScript_001DE952, 0, 0
	.globl gMapEvents_RUSTBORO_CITY
gMapEvents_RUSTBORO_CITY: @ 0x084FF294
	map_events RUSTBORO_CITY_EventObjects, RUSTBORO_CITY_EventWarps, RUSTBORO_CITY_EventCoordEvents, RUSTBORO_CITY_EventBgEvents
	.globl FORTREE_CITY_EventObjects
FORTREE_CITY_EventObjects: @ 0x084FF2A8
	object_event 1, 23, 0, 31, 3, 4, 1, 0, 0, 0, 0, FortreeCity_EventScript_001DFE00, 0x0000
	object_event 2, 8, 0, 32, 16, 3, 2, 1, 1, 0, 0, FortreeCity_EventScript_001DFE28, 0x0000
	object_event 3, 34, 0, 32, 10, 3, 3, 0, 1, 0, 0, FortreeCity_EventScript_001DFE09, 0x0000
	object_event 4, 7, 0, 11, 14, 4, 1, 0, 0, 0, 0, FortreeCity_EventScript_001DFE3A, 0x0000
	object_event 5, 29, 0, 8, 10, 3, 1, 0, 0, 0, 0, FortreeCity_EventScript_001DFE31, 0x0000
	object_event 6, 189, 0, 9, 16, 3, 8, 0, 0, 0, 0, FortreeCity_EventScript_001DFE43, 0x0000
	object_event 7, 204, 0, 25, 8, 3, 76, 1, 1, 0, 0, FortreeCity_EventScript_001DFE5E, 0x03C9
	.globl FORTREE_CITY_EventWarps
FORTREE_CITY_EventWarps: @ 0x084FF350
	warp_def 5, 6, 0, 0, MAP_FORTREE_CITY_POKEMON_CENTER_1F
	warp_def 10, 3, 0, 0, MAP_FORTREE_CITY_HOUSE1
	warp_def 22, 11, 0, 0, MAP_FORTREE_CITY_GYM
	warp_def 4, 14, 0, 0, MAP_FORTREE_CITY_MART
	warp_def 17, 3, 0, 0, MAP_FORTREE_CITY_HOUSE2
	warp_def 25, 3, 0, 0, MAP_FORTREE_CITY_HOUSE3
	warp_def 32, 2, 0, 0, MAP_FORTREE_CITY_HOUSE4
	warp_def 12, 13, 0, 0, MAP_FORTREE_CITY_HOUSE5
	warp_def 37, 13, 0, 0, MAP_FORTREE_CITY_DECORATION_SHOP
	.globl FORTREE_CITY_EventBgEvents
FORTREE_CITY_EventBgEvents: @ 0x084FF398
	bg_event 6, 9, 0, 0, FortreeCity_EventScript_001DFE4C, 0, 0
	bg_event 7, 6, 0, 1, 0x08242EFF, 0, 0
	bg_event 5, 14, 0, 1, 0x08242EF6, 0, 0
	bg_event 26, 10, 0, 0, FortreeCity_EventScript_001DFE55, 0, 0
	bg_event 6, 6, 0, 1, 0x08242EFF, 0, 0
	bg_event 6, 14, 0, 1, 0x08242EF6, 0, 0
	.globl gMapEvents_FORTREE_CITY
gMapEvents_FORTREE_CITY: @ 0x084FF3E0
	map_events FORTREE_CITY_EventObjects, FORTREE_CITY_EventWarps, 0, FORTREE_CITY_EventBgEvents
	.globl LILYCOVE_CITY_EventObjects
LILYCOVE_CITY_EventObjects: @ 0x084FF3F4
	object_event 1, 49, 0, 32, 20, 3, 3, 0, 1, 0, 0, LilycoveCity_EventScript_001E0288, 0x0000
	object_event 2, 8, 0, 15, 18, 3, 2, 1, 1, 0, 0, LilycoveCity_EventScript_001E0260, 0x0000
	object_event 3, 19, 0, 28, 28, 3, 1, 0, 0, 0, 0, LilycoveCity_EventScript_001E0257, 0x0000
	object_event 4, 15, 0, 21, 15, 3, 2, 1, 1, 0, 0, LilycoveCity_EventScript_001E027F, 0x0000
	object_event 5, 23, 0, 16, 9, 5, 5, 1, 0, 0, 0, LilycoveCity_EventScript_001E02C6, 0x0000
	object_event 6, 20, 0, 35, 27, 3, 2, 1, 1, 0, 0, LilycoveCity_EventScript_001E02A7, 0x0000
	object_event 7, 21, 0, 35, 37, 5, 8, 0, 0, 0, 0, LilycoveCity_EventScript_001E02CF, 0x0000
	object_event 8, 22, 0, 34, 37, 5, 8, 0, 0, 0, 0, LilycoveCity_EventScript_001E02D8, 0x0000
	object_event 9, 21, 0, 57, 17, 3, 1, 0, 0, 0, 0, LilycoveCity_EventScript_001E02E1, 0x0000
	object_event 10, 117, 0, 73, 15, 3, 10, 0, 0, 0, 0, LilycoveCity_EventScript_001E03B2, 0x0354
	object_event 11, 59, 0, 61, 36, 5, 1, 0, 0, 0, 0, 0x08256E3F, 0x0412
	object_event 12, 117, 0, 43, 18, 3, 5, 1, 0, 0, 0, LilycoveCity_EventScript_001E040A, 0x0354
	object_event 13, 117, 0, 46, 12, 3, 9, 0, 0, 0, 0, LilycoveCity_EventScript_001E03EF, 0x0354
	object_event 14, 117, 0, 45, 12, 3, 10, 0, 0, 0, 0, LilycoveCity_EventScript_001E03F8, 0x0354
	object_event 15, 117, 0, 38, 9, 5, 9, 0, 0, 0, 0, LilycoveCity_EventScript_001E0401, 0x0354
	object_event 16, 48, 0, 50, 7, 5, 2, 1, 1, 0, 0, LilycoveCity_EventScript_001E020D, 0x0000
	object_event 17, 240, 0, 27, 7, 5, 8, 1, 1, 0, 0, LilycoveCity_EventScript_001E0413, 0x03CB
	object_event 18, 38, 0, 16, 23, 3, 10, 1, 1, 0, 0, LilycoveCity_EventScript_001E0662, 0x0000
	object_event 19, 24, 0, 41, 25, 3, 9, 1, 1, 0, 0, LilycoveCity_EventScript_001E0323, 0x0000
	object_event 20, 23, 0, 40, 25, 3, 10, 1, 1, 0, 0, LilycoveCity_EventScript_001E0312, 0x0000
	object_event 21, 49, 0, 16, 34, 3, 8, 1, 1, 0, 0, LilycoveCity_EventScript_001E0300, 0x0000
	object_event 22, 17, 0, 16, 35, 3, 7, 1, 1, 0, 0, LilycoveCity_EventScript_001E0309, 0x0000
	.globl LILYCOVE_CITY_EventWarps
LILYCOVE_CITY_EventWarps: @ 0x084FF604
	warp_def 27, 6, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_1F
	warp_def 37, 24, 0, 0, MAP_LILYCOVE_CITY_COVE_LILY_MOTEL_1F
	warp_def 24, 14, 0, 0, MAP_LILYCOVE_CITY_POKEMON_CENTER_1F
	warp_def 11, 5, 0, 0, MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F
	warp_def 23, 24, 0, 0, MAP_LILYCOVE_CITY_CONTEST_LOBBY
	warp_def 39, 14, 0, 1, MAP_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB
	warp_def 70, 5, 1, 0, MAP_AQUA_HIDEOUT_1F
	warp_def 36, 6, 0, 0, MAP_LILYCOVE_CITY_MOVE_DELETERS_HOUSE
	warp_def 42, 6, 0, 0, MAP_LILYCOVE_CITY_HOUSE1
	warp_def 55, 15, 0, 0, MAP_LILYCOVE_CITY_HOUSE2
	warp_def 11, 22, 0, 0, MAP_LILYCOVE_CITY_HOUSE3
	warp_def 12, 14, 0, 0, MAP_LILYCOVE_CITY_HOUSE4
	warp_def 12, 32, 0, 0, MAP_LILYCOVE_CITY_HARBOR
	warp_def 12, 5, 0, 1, MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F
	.globl LILYCOVE_CITY_EventBgEvents
LILYCOVE_CITY_EventBgEvents: @ 0x084FF674
	bg_event 19, 7, 0, 0, LilycoveCity_EventScript_001E034F, 0, 0
	bg_event 25, 14, 0, 1, 0x08242EFF, 0, 0
	bg_event 29, 7, 0, 0, LilycoveCity_EventScript_001E03A0, 0, 0
	bg_event 26, 14, 0, 1, 0x08242EFF, 0, 0
	bg_event 6, 15, 0, 0, LilycoveCity_EventScript_001E0334, 0, 0
	bg_event 29, 24, 0, 0, LilycoveCity_EventScript_001E033D, 0, 0
	bg_event 35, 24, 0, 0, LilycoveCity_EventScript_001E0346, 0, 0
	bg_event 6, 30, 3, 0, LilycoveCity_EventScript_001E0379, 0, 0
	bg_event 36, 14, 0, 0, LilycoveCity_EventScript_001E0397, 0, 0
	bg_event 34, 6, 0, 0, LilycoveCity_EventScript_001E03A9, 0, 0
	bg_event 36, 31, 3, 7, 0x006F, 0x1B, 0x00
	bg_event 61, 7, 0, 7, 0x0045, 0x2B, 0x00
	bg_event 64, 31, 0, 7, 0x0004, 0x4B, 0x00
	.globl gMapEvents_LILYCOVE_CITY
gMapEvents_LILYCOVE_CITY: @ 0x084FF710
	map_events LILYCOVE_CITY_EventObjects, LILYCOVE_CITY_EventWarps, 0, LILYCOVE_CITY_EventBgEvents
	.globl MOSSDEEP_CITY_EventObjects
MOSSDEEP_CITY_EventObjects: @ 0x084FF724
	object_event 1, 49, 0, 38, 12, 5, 2, 1, 1, 0, 0, MossdeepCity_EventScript_001E15A0, 0x0000
	object_event 2, 21, 0, 50, 34, 5, 5, 1, 0, 0, 0, MossdeepCity_EventScript_001E15C8, 0x0000
	object_event 3, 18, 0, 32, 12, 5, 2, 1, 1, 0, 0, MossdeepCity_EventScript_001E1581, 0x0000
	object_event 4, 5, 0, 26, 21, 5, 3, 0, 1, 0, 0, MossdeepCity_EventScript_001E15BF, 0x0000
	object_event 5, 8, 0, 45, 18, 7, 9, 0, 0, 0, 0, MossdeepCity_EventScript_001E15D1, 0x0000
	object_event 6, 59, 0, 62, 35, 5, 1, 0, 0, 0, 0, 0x08256E4C, 0x0413
	object_event 7, 19, 0, 55, 5, 7, 7, 0, 0, 0, 0, MossdeepCity_EventScript_001E16DF, 0x0000
	object_event 8, 16, 0, 56, 21, 7, 10, 1, 1, 0, 0, MossdeepCity_EventScript_001E15DA, 0x0000
	object_event 9, 9, 0, 23, 13, 5, 2, 1, 1, 0, 0, MossdeepCity_EventScript_001E16F5, 0x0000
	object_event 10, 119, 0, 44, 23, 5, 8, 1, 1, 0, 0, 0x00000000, 0x0337
	object_event 11, 119, 0, 44, 24, 5, 7, 1, 1, 0, 0, 0x00000000, 0x0337
	object_event 12, 119, 0, 44, 25, 5, 8, 1, 1, 0, 0, 0x00000000, 0x0337
	object_event 13, 119, 0, 44, 26, 5, 7, 1, 1, 0, 0, 0x00000000, 0x0337
	object_event 14, 196, 0, 45, 25, 5, 9, 1, 1, 0, 0, 0x00000000, 0x0337
	object_event 15, 44, 0, 19, 25, 3, 64, 3, 3, 0, 0, 0x08276B0A, 0x0000
	object_event 16, 219, 0, 61, 29, 5, 17, 0, 0, 0, 0, MossdeepCity_EventScript_001E1754, 0x0314
	object_event 17, 44, 0, 31, 29, 3, 64, 3, 3, 0, 0, MossdeepCity_EventScript_001E174B, 0x0000
	.globl MOSSDEEP_CITY_EventWarps
MOSSDEEP_CITY_EventWarps: @ 0x084FF8BC
	warp_def 28, 9, 0, 0, MAP_MOSSDEEP_CITY_HOUSE1
	warp_def 38, 9, 0, 0, MAP_MOSSDEEP_CITY_GYM
	warp_def 28, 16, 0, 0, MAP_MOSSDEEP_CITY_POKEMON_CENTER_1F
	warp_def 67, 25, 0, 0, MAP_MOSSDEEP_CITY_HOUSE2
	warp_def 37, 18, 0, 0, MAP_MOSSDEEP_CITY_MART
	warp_def 49, 6, 0, 0, MAP_MOSSDEEP_CITY_HOUSE3
	warp_def 19, 10, 0, 0, MAP_MOSSDEEP_CITY_STEVENS_HOUSE
	warp_def 18, 16, 0, 1, MAP_MOSSDEEP_CITY_HOUSE4
	warp_def 64, 15, 0, 0, MAP_MOSSDEEP_CITY_SPACE_CENTER_1F
	warp_def 36, 24, 0, 0, MAP_MOSSDEEP_CITY_GAME_CORNER_1F
	.globl MOSSDEEP_CITY_EventCoordEvents
MOSSDEEP_CITY_EventCoordEvents: @ 0x084FF90C
	coord_event 25, 25, 0, 16385, 0, MossdeepCity_EventScript_001E1607
	coord_event 26, 25, 0, 16385, 0, MossdeepCity_EventScript_001E1607
	coord_event 32, 27, 0, 16385, 0, MossdeepCity_EventScript_001E1607
	coord_event 33, 27, 0, 16385, 0, MossdeepCity_EventScript_001E1607
	coord_event 42, 21, 5, 16477, 1, MossdeepCity_EventScript_001E1610
	coord_event 41, 22, 5, 16477, 1, MossdeepCity_EventScript_001E1610
	coord_event 41, 23, 5, 16477, 1, MossdeepCity_EventScript_001E1610
	coord_event 41, 24, 5, 16477, 1, MossdeepCity_EventScript_001E1610
	coord_event 40, 25, 5, 16477, 1, MossdeepCity_EventScript_001E1610
	coord_event 40, 26, 5, 16477, 1, MossdeepCity_EventScript_001E1610
	.globl MOSSDEEP_CITY_EventBgEvents
MOSSDEEP_CITY_EventBgEvents: @ 0x084FF9AC
	bg_event 25, 16, 0, 0, MossdeepCity_EventScript_001E15F5, 0, 0
	bg_event 34, 9, 0, 0, MossdeepCity_EventScript_001E15EC, 0, 0
	bg_event 29, 16, 0, 1, 0x08242EFF, 0, 0
	bg_event 38, 18, 0, 1, 0x08242EF6, 0, 0
	bg_event 66, 16, 0, 0, MossdeepCity_EventScript_001E15FE, 0, 0
	bg_event 30, 16, 0, 1, 0x08242EFF, 0, 0
	bg_event 39, 18, 0, 1, 0x08242EF6, 0, 0
	bg_event 57, 21, 7, 0, MossdeepCity_EventScript_001E15E3, 0, 0
	.globl gMapEvents_MOSSDEEP_CITY
gMapEvents_MOSSDEEP_CITY: @ 0x084FFA0C
	map_events MOSSDEEP_CITY_EventObjects, MOSSDEEP_CITY_EventWarps, MOSSDEEP_CITY_EventCoordEvents, MOSSDEEP_CITY_EventBgEvents
	.globl SOOTOPOLIS_CITY_EventObjects
SOOTOPOLIS_CITY_EventObjects: @ 0x084FFA20
	object_event 1, 21, 0, 31, 18, 3, 8, 0, 0, 0, 0, SootopolisCity_EventScript_001E2527, 0x0000
	object_event 2, 26, 0, 47, 33, 0, 9, 0, 0, 0, 0, SootopolisCity_EventScript_001E267C, 0x0356
	object_event 3, 10, 0, 9, 43, 3, 5, 1, 0, 0, 0, SootopolisCity_EventScript_001E2572, 0x0000
	object_event 4, 5, 0, 51, 14, 3, 8, 0, 0, 0, 0, SootopolisCity_EventScript_001E2728, 0x0000
	object_event 5, 7, 0, 43, 26, 3, 1, 0, 0, 0, 0, SootopolisCity_EventScript_001E277D, 0x0000
	object_event 6, 19, 0, 26, 4, 3, 5, 1, 0, 0, 0, SootopolisCity_EventScript_001E26B1, 0x0347
	object_event 7, 134, 0, 20, 36, 3, 8, 1, 1, 0, 0, SootopolisCity_EventScript_001E2800, 0x03CD
	object_event 8, 34, 0, 49, 34, 3, 3, 1, 1, 0, 0, SootopolisCity_EventScript_001E26D2, 0x0000
	object_event 9, 222, 0, 28, 44, 0, 80, 1, 1, 0, 0, 0x00000000, 0x03E6
	object_event 10, 221, 0, 34, 44, 1, 79, 1, 1, 0, 0, 0x00000000, 0x03E5
	object_event 11, 207, 0, 31, 41, 1, 10, 1, 1, 0, 0, 0x00000000, 0x03E4
	object_event 12, 39, 0, 17, 44, 3, 10, 1, 1, 0, 0, SootopolisCity_EventScript_001E2AAB, 0x0356
	object_event 13, 14, 0, 14, 42, 3, 10, 1, 1, 0, 0, SootopolisCity_EventScript_001E2A75, 0x0356
	object_event 14, 44, 0, 17, 40, 3, 10, 1, 1, 0, 0, SootopolisCity_EventScript_001E2A2D, 0x0356
	object_event 15, 9, 0, 19, 37, 3, 8, 1, 1, 0, 0, SootopolisCity_EventScript_001E29F7, 0x0356
	object_event 16, 196, 0, 29, 33, 3, 8, 1, 1, 0, 0, SootopolisCity_EventScript_001E2B8C, 0x033B
	object_event 17, 195, 0, 31, 33, 3, 8, 1, 1, 0, 0, SootopolisCity_EventScript_001E2BB9, 0x033A
	object_event 18, 133, 0, 31, 18, 3, 8, 1, 1, 0, 0, SootopolisCity_EventScript_001E2AE0, 0x0330
	.globl SOOTOPOLIS_CITY_EventWarps
SOOTOPOLIS_CITY_EventWarps: @ 0x084FFBD0
	warp_def 43, 31, 0, 0, MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_1F
	warp_def 17, 29, 0, 0, MAP_SOOTOPOLIS_CITY_MART
	warp_def 31, 32, 0, 0, MAP_SOOTOPOLIS_CITY_GYM_1F
	warp_def 31, 16, 3, 0, MAP_CAVE_OF_ORIGIN_ENTRANCE
	warp_def 9, 6, 0, 0, MAP_SOOTOPOLIS_CITY_HOUSE1
	warp_def 45, 6, 0, 0, MAP_SOOTOPOLIS_CITY_HOUSE2
	warp_def 9, 17, 0, 0, MAP_SOOTOPOLIS_CITY_HOUSE3
	warp_def 44, 17, 0, 0, MAP_SOOTOPOLIS_CITY_HOUSE4
	warp_def 9, 26, 0, 0, MAP_SOOTOPOLIS_CITY_HOUSE5
	warp_def 53, 28, 0, 0, MAP_SOOTOPOLIS_CITY_HOUSE6
	warp_def 8, 35, 0, 0, MAP_SOOTOPOLIS_CITY_HOUSE7
	warp_def 48, 25, 0, 0, MAP_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE
	warp_def 51, 36, 0, 0, MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F
	.globl SOOTOPOLIS_CITY_EventBgEvents
SOOTOPOLIS_CITY_EventBgEvents: @ 0x084FFC38
	bg_event 33, 34, 3, 0, SootopolisCity_EventScript_001E27E5, 0, 0
	bg_event 19, 29, 0, 1, 0x08242EF6, 0, 0
	bg_event 44, 31, 0, 1, 0x08242EFF, 0, 0
	bg_event 45, 31, 0, 1, 0x08242EFF, 0, 0
	bg_event 18, 29, 0, 1, 0x08242EF6, 0, 0
	bg_event 41, 37, 0, 0, SootopolisCity_EventScript_001E27EE, 0, 0
	.globl gMapEvents_SOOTOPOLIS_CITY
gMapEvents_SOOTOPOLIS_CITY: @ 0x084FFC80
	map_events SOOTOPOLIS_CITY_EventObjects, SOOTOPOLIS_CITY_EventWarps, 0, SOOTOPOLIS_CITY_EventBgEvents
	.globl EVER_GRANDE_CITY_EventObjects
EVER_GRANDE_CITY_EventObjects: @ 0x00000000
	.globl EVER_GRANDE_CITY_EventWarps
EVER_GRANDE_CITY_EventWarps: @ 0x084FFC94
	warp_def 18, 5, 0, 0, MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F
	warp_def 27, 48, 0, 0, MAP_EVER_GRANDE_CITY_POKEMON_CENTER_1F
	warp_def 18, 41, 0, 0, MAP_VICTORY_ROAD_1F
	warp_def 18, 27, 0, 1, MAP_VICTORY_ROAD_1F
	.globl EVER_GRANDE_CITY_EventCoordEvents
EVER_GRANDE_CITY_EventCoordEvents: @ 0x084FFCB4
	coord_event 17, 58, 1, 16385, 0, EverGrandeCity_EventScript_001E39A4
	coord_event 16, 58, 1, 16385, 0, EverGrandeCity_EventScript_001E39A4
	coord_event 18, 58, 1, 16385, 0, EverGrandeCity_EventScript_001E39A4
	coord_event 19, 58, 1, 16385, 0, EverGrandeCity_EventScript_001E39A4
	coord_event 20, 58, 1, 16385, 0, EverGrandeCity_EventScript_001E39A4
	coord_event 21, 58, 1, 16385, 0, EverGrandeCity_EventScript_001E39A4
	coord_event 22, 58, 1, 16385, 0, EverGrandeCity_EventScript_001E39A4
	coord_event 23, 58, 1, 16385, 0, EverGrandeCity_EventScript_001E39A4
	coord_event 24, 58, 1, 16385, 0, EverGrandeCity_EventScript_001E39A4
	coord_event 25, 58, 1, 16385, 0, EverGrandeCity_EventScript_001E39A4
	coord_event 26, 58, 1, 16385, 0, EverGrandeCity_EventScript_001E39A4
	.globl EVER_GRANDE_CITY_EventBgEvents
EVER_GRANDE_CITY_EventBgEvents: @ 0x084FFD64
	bg_event 19, 43, 5, 0, EverGrandeCity_EventScript_001E3989, 0, 0
	bg_event 29, 48, 0, 1, 0x08242EFF, 0, 0
	bg_event 18, 52, 5, 0, EverGrandeCity_EventScript_001E3992, 0, 0
	bg_event 23, 15, 0, 0, EverGrandeCity_EventScript_001E399B, 0, 0
	bg_event 28, 48, 0, 1, 0x08242EFF, 0, 0
	.globl gMapEvents_EVER_GRANDE_CITY
gMapEvents_EVER_GRANDE_CITY: @ 0x084FFDA0
	map_events 0, EVER_GRANDE_CITY_EventWarps, EVER_GRANDE_CITY_EventCoordEvents, EVER_GRANDE_CITY_EventBgEvents
	.globl LITTLEROOT_TOWN_EventObjects
LITTLEROOT_TOWN_EventObjects: @ 0x084FFDB4
	object_event 1, 6, 0, 16, 10, 3, 2, 1, 2, 0, 0, LittlerootTown_EventScript_001E3C5E, 0x0000
	object_event 2, 17, 0, 12, 13, 3, 2, 2, 1, 0, 0, LittlerootTown_EventScript_001E3C4C, 0x0364
	object_event 3, 9, 0, 14, 17, 3, 2, 2, 1, 0, 0, LittlerootTown_EventScript_001E3C55, 0x0000
	object_event 4, 215, 0, 5, 8, 3, 7, 0, 0, 0, 0, LittlerootTown_EventScript_001E4267, 0x02F0
	object_event 5, 94, 0, 2, 10, 4, 10, 0, 0, 0, 0, 0x00000000, 0x02F9
	object_event 6, 94, 0, 11, 10, 4, 10, 0, 0, 0, 0, 0x00000000, 0x02FA
	object_event 7, 240, 0, 13, 10, 3, 7, 1, 1, 0, 0, 0x00000000, 0x031A
	object_event 8, 64, 0, 14, 10, 3, 7, 1, 1, 0, 0, 0x00000000, 0x031B
	.globl LITTLEROOT_TOWN_EventWarps
LITTLEROOT_TOWN_EventWarps: @ 0x084FFE74
	warp_def 14, 8, 0, 1, MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F
	warp_def 5, 8, 0, 1, MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F
	warp_def 7, 16, 0, 0, MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB
	.globl LITTLEROOT_TOWN_EventCoordEvents
LITTLEROOT_TOWN_EventCoordEvents: @ 0x084FFE8C
	coord_event 10, 1, 3, 16464, 0, LittlerootTown_EventScript_001E3CBB
	coord_event 11, 1, 3, 16464, 0, LittlerootTown_EventScript_001E3D19
	coord_event 11, 1, 3, 16464, 1, LittlerootTown_EventScript_001E3D49
	coord_event 8, 9, 3, 16464, 3, LittlerootTown_EventScript_001E3E23
	coord_event 9, 9, 3, 16464, 3, LittlerootTown_EventScript_001E3E2F
	coord_event 10, 9, 3, 16464, 3, LittlerootTown_EventScript_001E3E0B
	coord_event 11, 9, 3, 16464, 3, LittlerootTown_EventScript_001E3E17
	coord_event 10, 2, 3, 16464, 3, LittlerootTown_EventScript_001E3DE5
	coord_event 11, 2, 3, 16464, 3, LittlerootTown_EventScript_001E3DF8
	.globl LITTLEROOT_TOWN_EventBgEvents
LITTLEROOT_TOWN_EventBgEvents: @ 0x084FFF1C
	bg_event 15, 13, 0, 0, LittlerootTown_EventScript_001E3D7B, 0, 0
	bg_event 6, 17, 0, 0, LittlerootTown_EventScript_001E3D84, 0, 0
	bg_event 7, 8, 3, 0, LittlerootTown_EventScript_001E3D8D, 0, 0
	bg_event 12, 8, 3, 0, LittlerootTown_EventScript_001E3DB9, 0, 0
	.globl gMapEvents_LITTLEROOT_TOWN
gMapEvents_LITTLEROOT_TOWN: @ 0x084FFF4C
	map_events LITTLEROOT_TOWN_EventObjects, LITTLEROOT_TOWN_EventWarps, LITTLEROOT_TOWN_EventCoordEvents, LITTLEROOT_TOWN_EventBgEvents
	.globl OLDALE_TOWN_EventObjects
OLDALE_TOWN_EventObjects: @ 0x084FFF60
	object_event 1, 14, 0, 16, 11, 3, 9, 0, 0, 0, 0, OldaleTown_EventScript_001E47D3, 0x0000
	object_event 2, 83, 0, 13, 7, 3, 8, 0, 0, 0, 0, OldaleTown_EventScript_001E47DC, 0x0000
	object_event 3, 39, 0, 8, 9, 3, 10, 0, 0, 0, 0, OldaleTown_EventScript_001E48FF, 0x0000
	object_event 4, 240, 0, 11, 19, 3, 7, 1, 1, 0, 0, OldaleTown_EventScript_001E4950, 0x03D3
	.globl OLDALE_TOWN_EventWarps
OLDALE_TOWN_EventWarps: @ 0x084FFFC0
	warp_def 5, 7, 0, 0, MAP_OLDALE_TOWN_HOUSE1
	warp_def 15, 16, 0, 0, MAP_OLDALE_TOWN_HOUSE2
	warp_def 6, 16, 0, 0, MAP_OLDALE_TOWN_POKEMON_CENTER_1F
	warp_def 14, 6, 0, 0, MAP_OLDALE_TOWN_MART
	.globl OLDALE_TOWN_EventCoordEvents
OLDALE_TOWN_EventCoordEvents: @ 0x084FFFE0
	coord_event 0, 10, 3, 16465, 0, OldaleTown_EventScript_001E491F
	coord_event 8, 19, 3, 16583, 1, OldaleTown_EventScript_001E4966
	coord_event 9, 19, 3, 16583, 1, OldaleTown_EventScript_001E4986
	coord_event 10, 19, 3, 16583, 1, OldaleTown_EventScript_001E49A6
	.globl OLDALE_TOWN_EventBgEvents
OLDALE_TOWN_EventBgEvents: @ 0x08500020
	bg_event 11, 9, 0, 0, OldaleTown_EventScript_001E47CA, 0, 0
	bg_event 7, 16, 0, 1, 0x08242EFF, 0, 0
	bg_event 15, 6, 0, 1, 0x08242EF6, 0, 0
	bg_event 8, 16, 0, 1, 0x08242EFF, 0, 0
	bg_event 16, 6, 0, 1, 0x08242EF6, 0, 0
	.globl gMapEvents_OLDALE_TOWN
gMapEvents_OLDALE_TOWN: @ 0x0850005C
	map_events OLDALE_TOWN_EventObjects, OLDALE_TOWN_EventWarps, OLDALE_TOWN_EventCoordEvents, OLDALE_TOWN_EventBgEvents
	.globl DEWFORD_TOWN_EventObjects
DEWFORD_TOWN_EventObjects: @ 0x08500070
	object_event 1, 20, 0, 7, 12, 3, 5, 1, 0, 0, 0, DewfordTown_EventScript_001E4D01, 0x0000
	object_event 2, 21, 0, 12, 9, 3, 9, 0, 1, 0, 3, DewfordTown_EventScript_001E4C61, 0x02E4
	object_event 3, 50, 0, 12, 14, 3, 5, 1, 0, 0, 0, DewfordTown_EventScript_001E4D25, 0x0000
	object_event 4, 88, 0, 12, 8, 1, 8, 0, 0, 0, 0, 0x00000000, 0x02E7
	object_event 5, 7, 0, 1, 6, 3, 1, 0, 0, 0, 0, DewfordTown_EventScript_001E5072, 0x0000
	.globl DEWFORD_TOWN_EventWarps
DEWFORD_TOWN_EventWarps: @ 0x085000E8
	warp_def 3, 3, 0, 0, MAP_DEWFORD_TOWN_HALL
	warp_def 2, 10, 0, 0, MAP_DEWFORD_TOWN_POKEMON_CENTER_1F
	warp_def 8, 17, 0, 0, MAP_DEWFORD_TOWN_GYM
	warp_def 17, 14, 0, 0, MAP_DEWFORD_TOWN_HOUSE1
	warp_def 8, 8, 0, 0, MAP_DEWFORD_TOWN_HOUSE2
	.globl DEWFORD_TOWN_EventBgEvents
DEWFORD_TOWN_EventBgEvents: @ 0x08500110
	bg_event 10, 10, 0, 0, DewfordTown_EventScript_001E4D0A, 0, 0
	bg_event 11, 16, 0, 0, DewfordTown_EventScript_001E4D13, 0, 0
	bg_event 4, 10, 0, 1, 0x08242EFF, 0, 0
	bg_event 3, 10, 0, 1, 0x08242EFF, 0, 0
	bg_event 2, 4, 0, 0, DewfordTown_EventScript_001E4D1C, 0, 0
	.globl gMapEvents_DEWFORD_TOWN
gMapEvents_DEWFORD_TOWN: @ 0x0850014C
	map_events DEWFORD_TOWN_EventObjects, DEWFORD_TOWN_EventWarps, 0, DEWFORD_TOWN_EventBgEvents
	.globl LAVARIDGE_TOWN_EventObjects
LAVARIDGE_TOWN_EventObjects: @ 0x08500160
	object_event 1, 22, 0, 8, 7, 3, 8, 0, 0, 0, 0, LavaridgeTown_EventScript_001E58CA, 0x0000
	object_event 2, 21, 0, 5, 1, 3, 8, 0, 0, 0, 0, LavaridgeTown_EventScript_001E589D, 0x0000
	object_event 3, 29, 0, 5, 8, 3, 8, 0, 0, 0, 0, LavaridgeTown_EventScript_001E58A6, 0x0000
	object_event 4, 6, 0, 10, 13, 3, 3, 0, 2, 0, 0, LavaridgeTown_EventScript_001E58AF, 0x0000
	object_event 5, 139, 0, 4, 4, 3, 18, 0, 0, 0, 0, LavaridgeTown_EventScript_001E58B8, 0x0000
	object_event 6, 139, 0, 5, 4, 3, 17, 0, 0, 0, 0, LavaridgeTown_EventScript_001E58C1, 0x0000
	object_event 7, 243, 0, 6, 16, 3, 9, 0, 0, 0, 0, 0x00000000, 0x03A2
	object_event 8, 240, 0, 12, 15, 0, 8, 0, 0, 0, 0, 0x00000000, 0x03A1
	object_event 9, 22, 0, 4, 7, 3, 8, 1, 1, 0, 0, LavaridgeTown_EventScript_001E58D3, 0x0000
	.globl LAVARIDGE_TOWN_EventWarps
LAVARIDGE_TOWN_EventWarps: @ 0x08500238
	warp_def 12, 15, 0, 0, MAP_LAVARIDGE_TOWN_HERB_SHOP
	warp_def 5, 15, 0, 0, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 15, 5, 0, 0, MAP_LAVARIDGE_TOWN_MART
	warp_def 9, 6, 0, 0, MAP_LAVARIDGE_TOWN_POKEMON_CENTER_1F
	warp_def 16, 15, 0, 0, MAP_LAVARIDGE_TOWN_HOUSE
	warp_def 9, 2, 3, 3, MAP_LAVARIDGE_TOWN_POKEMON_CENTER_1F
	.globl LAVARIDGE_TOWN_EventCoordEvents
LAVARIDGE_TOWN_EventCoordEvents: @ 0x08500268
	coord_event 6, 3, 3, 0, 0, LavaridgeTown_EventScript_001E5889
	.globl LAVARIDGE_TOWN_EventBgEvents
LAVARIDGE_TOWN_EventBgEvents: @ 0x08500278
	bg_event 14, 16, 0, 0, LavaridgeTown_EventScript_001E5946, 0, 0
	bg_event 7, 15, 0, 0, LavaridgeTown_EventScript_001E593D, 0, 0
	bg_event 17, 5, 0, 1, 0x08242EF6, 0, 0
	bg_event 13, 8, 0, 0, LavaridgeTown_EventScript_001E5934, 0, 0
	bg_event 10, 6, 0, 1, 0x08242EFF, 0, 0
	bg_event 16, 5, 0, 1, 0x08242EF6, 0, 0
	bg_event 11, 6, 0, 1, 0x08242EFF, 0, 0
	bg_event 4, 5, 3, 7, 0x0010, 0x00, 0x00
	.globl gMapEvents_LAVARIDGE_TOWN
gMapEvents_LAVARIDGE_TOWN: @ 0x085002D8
	map_events LAVARIDGE_TOWN_EventObjects, LAVARIDGE_TOWN_EventWarps, LAVARIDGE_TOWN_EventCoordEvents, LAVARIDGE_TOWN_EventBgEvents
	.globl FALLARBOR_TOWN_EventObjects
FALLARBOR_TOWN_EventObjects: @ 0x085002EC
	object_event 1, 8, 0, 8, 11, 3, 8, 0, 1, 0, 0, FallarborTown_EventScript_001E5E94, 0x0000
	object_event 2, 21, 0, 11, 9, 3, 5, 1, 0, 0, 0, FallarborTown_EventScript_001E5E75, 0x0000
	object_event 3, 48, 0, 11, 15, 3, 3, 1, 1, 0, 0, FallarborTown_EventScript_001E5E9D, 0x0000
	object_event 4, 214, 0, 8, 12, 3, 1, 1, 0, 0, 0, FallarborTown_EventScript_001E5EA6, 0x038B
	.globl FALLARBOR_TOWN_EventWarps
FALLARBOR_TOWN_EventWarps: @ 0x0850034C
	warp_def 15, 15, 0, 0, MAP_FALLARBOR_TOWN_MART
	warp_def 8, 7, 0, 0, MAP_FALLARBOR_TOWN_BATTLE_TENT_LOBBY
	warp_def 14, 7, 0, 0, MAP_FALLARBOR_TOWN_POKEMON_CENTER_1F
	warp_def 6, 17, 0, 0, MAP_FALLARBOR_TOWN_COZMOS_HOUSE
	warp_def 1, 6, 0, 0, MAP_FALLARBOR_TOWN_MOVE_RELEARNERS_HOUSE
	.globl FALLARBOR_TOWN_EventBgEvents
FALLARBOR_TOWN_EventBgEvents: @ 0x08500374
	bg_event 16, 15, 0, 1, 0x08242EF6, 0, 0
	bg_event 15, 7, 0, 1, 0x08242EFF, 0, 0
	bg_event 6, 8, 0, 0, FallarborTown_EventScript_001E5EB9, 0, 0
	bg_event 16, 7, 0, 1, 0x08242EFF, 0, 0
	bg_event 10, 11, 0, 0, FallarborTown_EventScript_001E5EC2, 0, 0
	bg_event 17, 15, 0, 1, 0x08242EF6, 0, 0
	bg_event 3, 7, 0, 0, FallarborTown_EventScript_001E5ECB, 0, 0
	bg_event 2, 15, 3, 7, 0x006E, 0x1C, 0x00
	.globl gMapEvents_FALLARBOR_TOWN
gMapEvents_FALLARBOR_TOWN: @ 0x085003D4
	map_events FALLARBOR_TOWN_EventObjects, FALLARBOR_TOWN_EventWarps, 0, FALLARBOR_TOWN_EventBgEvents
	.globl VERDANTURF_TOWN_EventObjects
VERDANTURF_TOWN_EventObjects: @ 0x085003E8
	object_event 1, 23, 0, 4, 17, 3, 5, 1, 0, 0, 0, VerdanturfTown_EventScript_001E609B, 0x0000
	object_event 2, 6, 0, 9, 2, 3, 9, 1, 0, 0, 0, VerdanturfTown_EventScript_001E6068, 0x0000
	object_event 3, 7, 0, 7, 11, 3, 3, 0, 1, 0, 0, VerdanturfTown_EventScript_001E60AD, 0x0000
	object_event 4, 31, 0, 7, 6, 3, 5, 1, 0, 0, 0, VerdanturfTown_EventScript_001E60A4, 0x0000
	.globl VERDANTURF_TOWN_EventWarps
VERDANTURF_TOWN_EventWarps: @ 0x08500448
	warp_def 3, 7, 0, 0, MAP_VERDANTURF_TOWN_BATTLE_TENT_LOBBY
	warp_def 12, 3, 0, 0, MAP_VERDANTURF_TOWN_MART
	warp_def 16, 3, 0, 0, MAP_VERDANTURF_TOWN_POKEMON_CENTER_1F
	warp_def 10, 14, 0, 0, MAP_VERDANTURF_TOWN_WANDAS_HOUSE
	warp_def 8, 1, 0, 1, MAP_RUSTURF_TUNNEL
	warp_def 1, 14, 0, 0, MAP_VERDANTURF_TOWN_FRIENDSHIP_RATERS_HOUSE
	warp_def 17, 15, 0, 0, MAP_VERDANTURF_TOWN_HOUSE
	.globl VERDANTURF_TOWN_EventBgEvents
VERDANTURF_TOWN_EventBgEvents: @ 0x08500480
	bg_event 14, 3, 0, 1, 0x08242EF6, 0, 0
	bg_event 14, 6, 0, 0, VerdanturfTown_EventScript_001E60CC, 0, 0
	bg_event 17, 3, 0, 1, 0x08242EFF, 0, 0
	bg_event 7, 14, 0, 0, VerdanturfTown_EventScript_001E60D5, 0, 0
	bg_event 13, 3, 0, 1, 0x08242EF6, 0, 0
	bg_event 18, 3, 0, 1, 0x08242EFF, 0, 0
	bg_event 1, 8, 0, 0, VerdanturfTown_EventScript_001E60DE, 0, 0
	bg_event 7, 3, 0, 0, VerdanturfTown_EventScript_001E60E7, 0, 0
	.globl gMapEvents_VERDANTURF_TOWN
gMapEvents_VERDANTURF_TOWN: @ 0x085004E0
	map_events VERDANTURF_TOWN_EventObjects, VERDANTURF_TOWN_EventWarps, 0, VERDANTURF_TOWN_EventBgEvents
	.globl PACIFIDLOG_TOWN_EventObjects
PACIFIDLOG_TOWN_EventObjects: @ 0x085004F4
	object_event 1, 8, 0, 10, 23, 3, 9, 0, 0, 0, 0, PacifidlogTown_EventScript_001E639C, 0x0000
	object_event 2, 50, 0, 11, 14, 3, 10, 0, 0, 0, 0, PacifidlogTown_EventScript_001E63A5, 0x0000
	object_event 3, 5, 0, 9, 16, 3, 8, 0, 0, 0, 0, PacifidlogTown_EventScript_001E6393, 0x0000
	.globl PACIFIDLOG_TOWN_EventWarps
PACIFIDLOG_TOWN_EventWarps: @ 0x0850053C
	warp_def 8, 15, 0, 0, MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_1F
	warp_def 16, 13, 0, 0, MAP_PACIFIDLOG_TOWN_HOUSE1
	warp_def 3, 22, 0, 0, MAP_PACIFIDLOG_TOWN_HOUSE2
	warp_def 12, 24, 0, 0, MAP_PACIFIDLOG_TOWN_HOUSE3
	warp_def 2, 12, 0, 0, MAP_PACIFIDLOG_TOWN_HOUSE4
	warp_def 17, 21, 0, 0, MAP_PACIFIDLOG_TOWN_HOUSE5
	.globl PACIFIDLOG_TOWN_EventBgEvents
PACIFIDLOG_TOWN_EventBgEvents: @ 0x0850056C
	bg_event 9, 15, 0, 1, 0x08242EFF, 0, 0
	bg_event 7, 16, 0, 0, PacifidlogTown_EventScript_001E63AE, 0, 0
	bg_event 10, 15, 0, 1, 0x08242EFF, 0, 0
	.globl gMapEvents_PACIFIDLOG_TOWN
gMapEvents_PACIFIDLOG_TOWN: @ 0x08500590
	map_events PACIFIDLOG_TOWN_EventObjects, PACIFIDLOG_TOWN_EventWarps, 0, PACIFIDLOG_TOWN_EventBgEvents
	.globl ROUTE101_EventObjects
ROUTE101_EventObjects: @ 0x085005A4
	object_event 1, 35, 0, 16, 8, 3, 1, 0, 0, 0, 0, Route101_EventScript_001E65F7, 0x0000
	object_event 2, 64, 0, 9, 13, 0, 71, 0, 0, 0, 0, 0x00000000, 0x02D0
	object_event 3, 97, 0, 7, 14, 3, 1, 0, 0, 0, 0, Route101_EventScript_001E6612, 0x02BC
	object_event 4, 98, 0, 10, 13, 0, 70, 0, 0, 0, 0, 0x00000000, 0x02EE
	object_event 5, 64, 0, 5, 11, 3, 1, 0, 0, 0, 0, 0x082431CD, 0x0381
	object_event 6, 9, 0, 2, 13, 3, 5, 1, 1, 0, 0, Route101_EventScript_001E6600, 0x03DF
	.globl ROUTE101_EventCoordEvents
ROUTE101_EventCoordEvents: @ 0x08500634
	coord_event 10, 19, 3, 16480, 1, Route101_EventScript_001E64DA
	coord_event 11, 19, 3, 16480, 1, Route101_EventScript_001E64DA
	coord_event 10, 18, 3, 16480, 2, Route101_EventScript_001E654A
	coord_event 11, 18, 3, 16480, 2, Route101_EventScript_001E654A
	coord_event 6, 16, 3, 16480, 2, Route101_EventScript_001E6560
	coord_event 6, 15, 3, 16480, 2, Route101_EventScript_001E6560
	coord_event 6, 17, 3, 16480, 2, Route101_EventScript_001E6560
	coord_event 6, 18, 3, 16480, 2, Route101_EventScript_001E6560
	coord_event 7, 13, 3, 16480, 2, Route101_EventScript_001E6576
	.globl ROUTE101_EventBgEvents
ROUTE101_EventBgEvents: @ 0x085006C4
	bg_event 5, 9, 0, 0, Route101_EventScript_001E6609, 0, 0
	.globl gMapEvents_ROUTE101
gMapEvents_ROUTE101: @ 0x085006D0
	map_events ROUTE101_EventObjects, 0, ROUTE101_EventCoordEvents, ROUTE101_EventBgEvents
	.globl ROUTE102_EventObjects
ROUTE102_EventObjects: @ 0x085006E4
	object_event 1, 11, 0, 18, 11, 3, 1, 0, 0, 0, 0, 0x081E6825, 0x0000
	object_event 2, 35, 0, 33, 14, 3, 8, 0, 0, 1, 3, 0x081E6849, 0x0000
	object_event 3, 36, 0, 25, 15, 3, 7, 0, 0, 1, 2, 0x081E68F7, 0x0000
	object_event 4, 47, 0, 8, 7, 3, 18, 0, 0, 1, 3, 0x081E690E, 0x0000
	object_event 5, 7, 0, 37, 4, 3, 2, 1, 1, 0, 0, 0x081E6840, 0x0000
	object_event 6, 59, 0, 11, 15, 3, 8, 0, 0, 0, 0, 0x08256A2F, 0x03E8
	object_event 7, 60, 0, 24, 2, 3, 12, 0, 0, 0, 2, 0x08244D23, 0x0000
	object_event 8, 60, 0, 25, 2, 3, 12, 0, 0, 0, 1, 0x08244D23, 0x0000
	object_event 9, 35, 0, 19, 4, 3, 8, 1, 1, 1, 3, 0x081E6925, 0x0000
	.globl ROUTE102_EventBgEvents
ROUTE102_EventBgEvents: @ 0x085007BC
	bg_event 17, 2, 0, 0, 0x081E6837, 0, 0
	bg_event 40, 9, 0, 0, 0x081E682E, 0, 0
	.globl gMapEvents_ROUTE102
gMapEvents_ROUTE102: @ 0x085007D4
	map_events ROUTE102_EventObjects, 0, 0, ROUTE102_EventBgEvents
	.globl ROUTE103_EventObjects
ROUTE103_EventObjects: @ 0x085007E8
	object_event 1, 33, 0, 49, 12, 3, 9, 0, 0, 0, 0, Route103_EventScript_001E6CAD, 0x0000
	object_event 2, 240, 0, 10, 3, 3, 10, 0, 0, 0, 0, Route103_EventScript_001E6A8C, 0x02D3
	object_event 3, 20, 0, 71, 11, 3, 18, 0, 0, 1, 3, 0x081E6CBF, 0x0000
	object_event 4, 6, 0, 65, 12, 3, 8, 0, 0, 1, 1, 0x081E6D39, 0x0000
	object_event 5, 6, 0, 64, 12, 3, 8, 0, 0, 1, 1, 0x081E6CD6, 0x0000
	object_event 6, 50, 0, 50, 8, 3, 26, 0, 1, 1, 3, 0x081E6D9C, 0x0000
	object_event 7, 60, 0, 58, 5, 3, 12, 0, 0, 0, 5, 0x08244D23, 0x0000
	object_event 8, 60, 0, 59, 5, 3, 12, 0, 0, 0, 6, 0x08244D23, 0x0000
	object_event 9, 60, 0, 60, 5, 3, 12, 0, 0, 0, 7, 0x08244D23, 0x0000
	object_event 10, 7, 0, 20, 10, 3, 2, 1, 2, 0, 0, Route103_EventScript_001E6CA4, 0x0000
	object_event 11, 64, 0, 7, 3, 3, 2, 1, 1, 0, 0, 0x082431CD, 0x0382
	object_event 12, 25, 0, 56, 13, 3, 10, 0, 0, 1, 5, 0x081E6DB3, 0x0000
	object_event 13, 59, 0, 50, 5, 3, 1, 1, 1, 0, 0, 0x08256A3C, 0x045A
	object_event 14, 82, 0, 67, 7, 3, 1, 1, 1, 0, 0, 0x082565C8, 0x0012
	object_event 15, 82, 0, 72, 8, 3, 1, 1, 1, 0, 0, 0x082565C8, 0x0013
	object_event 16, 44, 0, 67, 5, 3, 8, 1, 1, 1, 2, 0x081E6E2C, 0x0000
	object_event 17, 66, 0, 67, 9, 3, 7, 1, 1, 1, 2, 0x081E6E15, 0x0000
	object_event 18, 43, 0, 36, 6, 1, 26, 1, 3, 1, 5, 0x081E6E5A, 0x0000
	object_event 19, 42, 0, 36, 13, 1, 25, 1, 3, 1, 5, 0x081E6E43, 0x0000
	object_event 20, 59, 0, 64, 7, 0, 1, 1, 1, 0, 0, 0x08256A49, 0x0471
	.globl ROUTE103_EventWarps
ROUTE103_EventWarps: @ 0x085009C8
	warp_def 45, 6, 0, 0, MAP_ALTERING_CAVE
	.globl ROUTE103_EventBgEvents
ROUTE103_EventBgEvents: @ 0x085009D0
	bg_event 11, 9, 0, 0, Route103_EventScript_001E6CB6, 0, 0
	.globl gMapEvents_ROUTE103
gMapEvents_ROUTE103: @ 0x085009DC
	map_events ROUTE103_EventObjects, ROUTE103_EventWarps, 0, ROUTE103_EventBgEvents
	.globl ROUTE104_EventObjects
ROUTE104_EventObjects: @ 0x085009F0
	object_event 1, 36, 0, 15, 60, 3, 9, 0, 0, 0, 0, Route104_EventScript_001E750B, 0x0000
	object_event 2, 10, 0, 25, 49, 3, 2, 1, 1, 0, 0, Route104_EventScript_001E7502, 0x0000
	object_event 3, 47, 0, 31, 24, 3, 9, 0, 0, 1, 7, 0x081E7889, 0x0000
	object_event 4, 7, 0, 27, 63, 3, 3, 0, 1, 0, 0, Route104_EventScript_001E7541, 0x0000
	object_event 5, 20, 0, 30, 50, 3, 2, 1, 1, 0, 0, Route104_EventScript_001E754A, 0x0000
	object_event 6, 14, 0, 28, 74, 3, 7, 0, 0, 0, 0, Route104_EventScript_001E758C, 0x0000
	object_event 7, 88, 0, 12, 54, 1, 7, 0, 0, 0, 0, 0x00000000, 0x02E6
	object_event 8, 21, 0, 12, 51, 4, 10, 0, 0, 0, 0, 0x00000000, 0x02E2
	object_event 9, 50, 0, 29, 8, 3, 8, 0, 0, 1, 0, 0x081E785B, 0x0000
	object_event 10, 60, 0, 34, 6, 3, 12, 0, 0, 0, 8, 0x08244D23, 0x0000
	object_event 11, 60, 0, 35, 6, 3, 12, 0, 0, 0, 9, 0x08244D23, 0x0000
	object_event 12, 60, 0, 36, 6, 3, 12, 0, 0, 0, 10, 0x08244D23, 0x0000
	object_event 13, 60, 0, 22, 41, 3, 12, 0, 0, 0, 11, 0x08244D23, 0x0000
	object_event 14, 60, 0, 23, 41, 3, 12, 0, 0, 0, 12, 0x08244D23, 0x0000
	object_event 15, 60, 0, 24, 41, 3, 12, 0, 0, 0, 13, 0x08244D23, 0x0000
	object_event 16, 22, 0, 37, 8, 3, 9, 1, 1, 0, 0, Route104_EventScript_001E7488, 0x0000
	object_event 17, 60, 0, 3, 22, 3, 12, 0, 0, 0, 3, 0x08244D23, 0x0000
	object_event 18, 60, 0, 3, 23, 3, 12, 0, 0, 0, 4, 0x08244D23, 0x0000
	object_event 19, 60, 0, 3, 24, 3, 12, 0, 0, 0, 75, 0x08244D23, 0x0000
	object_event 20, 60, 0, 3, 25, 3, 12, 0, 0, 0, 76, 0x08244D23, 0x0000
	object_event 21, 59, 0, 39, 15, 3, 1, 0, 0, 0, 0, 0x08256A56, 0x03EA
	object_event 22, 34, 0, 8, 19, 3, 5, 1, 0, 0, 0, Route104_EventScript_001E74C9, 0x038A
	object_event 23, 6, 0, 27, 15, 3, 8, 0, 0, 1, 1, 0x081E7A93, 0x0000
	object_event 24, 6, 0, 28, 15, 3, 8, 0, 0, 1, 1, 0x081E7AB2, 0x0000
	object_event 25, 15, 0, 21, 25, 3, 23, 0, 0, 1, 3, 0x081E7937, 0x0000
	object_event 26, 20, 0, 11, 44, 3, 16, 0, 0, 1, 3, 0x081E79E5, 0x0000
	object_event 27, 59, 0, 29, 53, 3, 1, 1, 1, 0, 0, 0x08256A63, 0x0421
	object_event 28, 35, 0, 18, 67, 3, 46, 5, 6, 1, 2, 0x081E7872, 0x0000
	object_event 29, 59, 0, 37, 22, 3, 1, 1, 1, 0, 0, 0x08256A70, 0x045B
	object_event 30, 82, 0, 35, 22, 3, 1, 1, 1, 0, 0, 0x082565C8, 0x0011
	object_event 31, 59, 0, 5, 8, 3, 1, 1, 1, 0, 0, 0x08256A7D, 0x046F
	object_event 32, 9, 0, 5, 26, 3, 1, 1, 1, 0, 0, Route104_EventScript_001E7553, 0x0000
	object_event 33, 50, 0, 15, 59, 3, 9, 0, 0, 1, 0, 0x081E7AD1, 0x0000
	object_event 34, 240, 0, 17, 50, 0, 1, 1, 1, 0, 0, Route104_EventScript_001E719A, 0x02CF
	.globl ROUTE104_EventWarps
ROUTE104_EventWarps: @ 0x08500D20
	warp_def 17, 50, 0, 0, MAP_ROUTE104_MR_BRINEYS_HOUSE
	warp_def 5, 18, 0, 0, MAP_ROUTE104_PRETTY_PETAL_FLOWER_SHOP
	warp_def 10, 30, 3, 0, MAP_PETALBURG_WOODS
	warp_def 11, 30, 3, 1, MAP_PETALBURG_WOODS
	warp_def 10, 38, 3, 2, MAP_PETALBURG_WOODS
	warp_def 11, 38, 3, 3, MAP_PETALBURG_WOODS
	warp_def 32, 42, 3, 4, MAP_PETALBURG_WOODS
	warp_def 33, 42, 3, 5, MAP_PETALBURG_WOODS
	.globl ROUTE104_EventCoordEvents
ROUTE104_EventCoordEvents: @ 0x08500D60
	coord_event 17, 51, 3, 16483, 1, Route104_EventScript_001E71AF
	.globl ROUTE104_EventBgEvents
ROUTE104_EventBgEvents: @ 0x08500D70
	bg_event 20, 50, 0, 0, Route104_EventScript_001E7514, 0, 0
	bg_event 27, 66, 0, 0, Route104_EventScript_001E751D, 0, 0
	bg_event 23, 5, 0, 0, Route104_EventScript_001E7526, 0, 0
	bg_event 7, 20, 0, 0, Route104_EventScript_001E752F, 0, 0
	bg_event 17, 23, 3, 0, Route104_EventScript_001E7538, 0, 0
	bg_event 7, 6, 3, 7, 0x0016, 0x2C, 0x00
	bg_event 3, 9, 3, 7, 0x0004, 0x3E, 0x00
	bg_event 14, 55, 3, 7, 0x000D, 0x25, 0x00
	bg_event 16, 72, 3, 7, 0x000E, 0x55, 0x00
	bg_event 16, 64, 3, 7, 0x006F, 0x58, 0x00
	.globl gMapEvents_ROUTE104
gMapEvents_ROUTE104: @ 0x08500DE8
	map_events ROUTE104_EventObjects, ROUTE104_EventWarps, ROUTE104_EventCoordEvents, ROUTE104_EventBgEvents
	.globl ROUTE105_EventObjects
ROUTE105_EventObjects: @ 0x08500DFC
	object_event 1, 42, 0, 19, 60, 1, 10, 0, 0, 1, 6, 0x081E8224, 0x0000
	object_event 2, 42, 0, 27, 36, 1, 27, 7, 0, 1, 3, 0x081E823B, 0x0000
	object_event 3, 43, 0, 8, 45, 1, 25, 0, 7, 1, 3, 0x081E8252, 0x0000
	object_event 4, 43, 0, 19, 9, 1, 24, 0, 5, 1, 3, 0x081E8269, 0x0000
	object_event 5, 59, 0, 8, 73, 3, 1, 0, 0, 0, 0, 0x08256A8A, 0x03EB
	object_event 6, 55, 0, 17, 48, 3, 26, 0, 7, 1, 3, 0x081E820D, 0x0000
	object_event 7, 66, 0, 4, 54, 3, 8, 0, 2, 1, 2, 0x081E8280, 0x0000
	object_event 8, 55, 0, 4, 58, 3, 7, 0, 2, 1, 4, 0x081E8297, 0x0000
	.globl ROUTE105_EventWarps
ROUTE105_EventWarps: @ 0x08500EBC
	warp_def 9, 20, 0, 0, MAP_ISLAND_CAVE
	.globl ROUTE105_EventBgEvents
ROUTE105_EventBgEvents: @ 0x08500EC4
	bg_event 15, 68, 3, 7, 0x006F, 0x59, 0x00
	bg_event 5, 56, 3, 7, 0x006B, 0x6F, 0x00
	.globl gMapEvents_ROUTE105
gMapEvents_ROUTE105: @ 0x08500EDC
	map_events ROUTE105_EventObjects, ROUTE105_EventWarps, 0, ROUTE105_EventBgEvents
	.globl ROUTE106_EventObjects
ROUTE106_EventObjects: @ 0x08500EF0
	object_event 1, 42, 0, 18, 5, 1, 27, 4, 0, 1, 3, 0x081E83D4, 0x0000
	object_event 2, 43, 0, 29, 10, 1, 1, 0, 0, 1, 3, 0x081E83EB, 0x0000
	object_event 3, 50, 0, 51, 14, 3, 10, 0, 0, 1, 4, 0x081E8402, 0x0000
	object_event 4, 50, 0, 65, 14, 3, 1, 0, 0, 1, 3, 0x081E8464, 0x0000
	object_event 5, 59, 0, 29, 14, 3, 1, 0, 0, 0, 0, 0x08256A97, 0x03EC
	.globl ROUTE106_EventWarps
ROUTE106_EventWarps: @ 0x08500F68
	warp_def 48, 16, 0, 0, MAP_GRANITE_CAVE_1F
	.globl ROUTE106_EventBgEvents
ROUTE106_EventBgEvents: @ 0x08500F70
	bg_event 41, 11, 3, 7, 0x0004, 0x3F, 0x00
	bg_event 53, 12, 0, 7, 0x006C, 0x2E, 0x00
	bg_event 68, 15, 3, 7, 0x006F, 0x2F, 0x00
	bg_event 59, 13, 3, 0, 0x081E83CB, 0, 0
	.globl gMapEvents_ROUTE106
gMapEvents_ROUTE106: @ 0x08500FA0
	map_events ROUTE106_EventObjects, ROUTE106_EventWarps, 0, ROUTE106_EventBgEvents
	.globl ROUTE107_EventObjects
ROUTE107_EventObjects: @ 0x08500FB4
	object_event 1, 42, 0, 41, 10, 1, 24, 1, 1, 1, 3, 0x081E84AC, 0x0000
	object_event 2, 42, 0, 23, 11, 1, 52, 6, 2, 1, 2, 0x081E84C3, 0x0000
	object_event 3, 43, 0, 16, 7, 1, 13, 0, 0, 1, 5, 0x081E8525, 0x0000
	object_event 4, 43, 0, 50, 11, 1, 65, 1, 1, 1, 5, 0x081E853C, 0x0000
	object_event 5, 43, 0, 33, 4, 1, 8, 1, 1, 1, 1, 0x081E8553, 0x0000
	object_event 6, 213, 0, 32, 4, 1, 8, 1, 1, 1, 1, 0x081E856E, 0x0000
	object_event 7, 42, 0, 50, 5, 1, 64, 1, 1, 1, 5, 0x081E8589, 0x0000
	.globl gMapEvents_ROUTE107
gMapEvents_ROUTE107: @ 0x0850105C
	map_events ROUTE107_EventObjects, 0, 0, 0
	.globl ROUTE108_EventObjects
ROUTE108_EventObjects: @ 0x08501070
	object_event 1, 42, 0, 52, 13, 1, 45, 3, 3, 1, 3, 0x081E85A1, 0x0000
	object_event 2, 43, 0, 35, 12, 1, 13, 1, 1, 1, 3, 0x081E85CF, 0x0000
	object_event 3, 42, 0, 13, 13, 1, 24, 0, 0, 1, 3, 0x081E85B8, 0x0000
	object_event 4, 43, 0, 8, 7, 1, 20, 6, 0, 1, 3, 0x081E85E6, 0x0000
	object_event 5, 34, 0, 41, 5, 3, 10, 1, 1, 1, 1, 0x081E85FD, 0x0000
	object_event 6, 49, 0, 43, 5, 3, 9, 1, 1, 1, 1, 0x081E8614, 0x0000
	object_event 7, 59, 0, 42, 4, 3, 1, 1, 1, 0, 0, 0x08256AA4, 0x0473
	.globl ROUTE108_EventWarps
ROUTE108_EventWarps: @ 0x08501118
	warp_def 29, 6, 3, 0, MAP_ABANDONED_SHIP_DECK
	.globl ROUTE108_EventBgEvents
ROUTE108_EventBgEvents: @ 0x08501120
	bg_event 38, 14, 3, 7, 0x0044, 0x56, 0x00
	.globl gMapEvents_ROUTE108
gMapEvents_ROUTE108: @ 0x0850112C
	map_events ROUTE108_EventObjects, ROUTE108_EventWarps, 0, ROUTE108_EventBgEvents
	.globl ROUTE109_EventObjects
ROUTE109_EventObjects: @ 0x08501140
	object_event 1, 88, 0, 21, 26, 1, 7, 0, 0, 0, 0, 0x00000000, 0x02E8
	object_event 2, 21, 0, 21, 24, 3, 7, 0, 0, 0, 0, 0x081E8827, 0x02E5
	object_event 3, 42, 0, 12, 36, 3, 10, 0, 0, 1, 5, 0x081E8954, 0x0000
	object_event 4, 43, 0, 25, 39, 1, 15, 0, 0, 1, 5, 0x081E896B, 0x0000
	object_event 5, 49, 0, 15, 17, 4, 8, 0, 0, 1, 1, 0x081E8982, 0x0000
	object_event 6, 49, 0, 24, 13, 3, 9, 0, 0, 1, 6, 0x081E8999, 0x0000
	object_event 7, 54, 0, 19, 10, 3, 8, 0, 0, 1, 3, 0x081E89B0, 0x0000
	object_event 8, 53, 0, 22, 7, 3, 80, 0, 0, 1, 4, 0x081E8A12, 0x0000
	object_event 9, 12, 0, 11, 6, 3, 8, 0, 0, 0, 0, 0x081E88AC, 0x0000
	object_event 10, 59, 0, 27, 46, 3, 1, 0, 0, 0, 0, 0x08256AB1, 0x03ED
	object_event 11, 53, 0, 29, 32, 3, 13, 0, 0, 1, 3, 0x081E8A8B, 0x0000
	object_event 12, 53, 0, 28, 31, 3, 17, 0, 0, 1, 3, 0x081E8A74, 0x0000
	object_event 13, 50, 0, 21, 56, 0, 9, 0, 0, 1, 3, 0x081E8AA2, 0x0000
	object_event 14, 54, 0, 24, 18, 3, 10, 1, 1, 0, 0, 0x081E88B5, 0x0000
	object_event 15, 53, 0, 25, 18, 3, 9, 1, 1, 0, 0, 0x081E88CC, 0x0000
	object_event 16, 18, 0, 30, 32, 3, 8, 1, 1, 0, 0, 0x081E891D, 0x0000
	object_event 17, 26, 0, 8, 41, 3, 8, 1, 1, 1, 1, 0x081E8AD4, 0x0000
	object_event 18, 65, 0, 9, 41, 3, 8, 1, 1, 1, 1, 0x081E8AB9, 0x0000
	object_event 19, 29, 0, 33, 6, 3, 1, 1, 1, 0, 0, 0x081E8926, 0x0000
	object_event 20, 208, 0, 32, 6, 3, 1, 1, 1, 0, 0, 0x081E892F, 0x0000
	object_event 21, 53, 0, 17, 13, 3, 80, 1, 1, 1, 6, 0x081E8B06, 0x0000
	object_event 22, 54, 0, 27, 7, 3, 79, 1, 1, 1, 4, 0x081E8AEF, 0x0000
	object_event 23, 59, 0, 25, 6, 3, 1, 1, 1, 0, 0, 0x08256ABE, 0x0474
	object_event 24, 66, 0, 17, 56, 3, 80, 1, 1, 1, 3, 0x081E8B1D, 0x0000
	.globl ROUTE109_EventWarps
ROUTE109_EventWarps: @ 0x08501380
	warp_def 12, 5, 0, 0, MAP_ROUTE109_SEASHORE_HOUSE
	.globl ROUTE109_EventBgEvents
ROUTE109_EventBgEvents: @ 0x08501388
	bg_event 15, 5, 0, 0, 0x081E8942, 0, 0
	bg_event 29, 10, 3, 0, 0x081E894B, 0, 0
	bg_event 16, 23, 3, 7, 0x0018, 0x32, 0x00
	bg_event 33, 5, 3, 7, 0x006F, 0x34, 0x00
	bg_event 9, 10, 3, 7, 0x0003, 0x33, 0x00
	bg_event 28, 20, 3, 7, 0x0022, 0x40, 0x00
	bg_event 13, 16, 3, 7, 0x006F, 0x5A, 0x00
	bg_event 8, 42, 3, 7, 0x006F, 0x5B, 0x00
	.globl gMapEvents_ROUTE109
gMapEvents_ROUTE109: @ 0x085013E8
	map_events ROUTE109_EventObjects, ROUTE109_EventWarps, 0, ROUTE109_EventBgEvents
	.globl ROUTE110_EventObjects
ROUTE110_EventObjects: @ 0x085013FC
	object_event 1, 31, 0, 17, 90, 3, 8, 0, 0, 0, 0, Route110_EventScript_001E8F18, 0x0000
	object_event 2, 56, 0, 29, 79, 4, 8, 0, 0, 0, 0, Route110_EventScript_001E8F0F, 0x0000
	object_event 3, 22, 0, 14, 69, 3, 3, 0, 1, 0, 0, Route110_EventScript_001E8F06, 0x0000
	object_event 4, 56, 0, 9, 57, 4, 2, 1, 1, 0, 0, Route110_EventScript_001E8EF4, 0x0000
	object_event 5, 21, 0, 10, 11, 3, 2, 1, 1, 0, 0, Route110_EventScript_001E8EFD, 0x0000
	object_event 6, 57, 0, 27, 24, 4, 2, 1, 3, 0, 0, Route110_EventScript_001E8EEB, 0x0000
	object_event 7, 13, 0, 15, 7, 3, 2, 1, 1, 0, 0, Route110_EventScript_001E8EE2, 0x0000
	object_event 8, 57, 0, 16, 73, 4, 49, 2, 14, 1, 3, 0x081E9109, 0x0000
	object_event 9, 56, 0, 19, 31, 4, 51, 10, 1, 1, 3, 0x081E9090, 0x0000
	object_event 10, 57, 0, 30, 31, 4, 9, 1, 1, 1, 4, 0x081E9120, 0x0000
	object_event 11, 56, 0, 16, 55, 4, 45, 4, 4, 1, 3, 0x081E90A7, 0x0000
	object_event 12, 37, 0, 3, 39, 3, 10, 0, 0, 1, 6, 0x081E8FD2, 0x0000
	object_event 13, 47, 0, 33, 15, 3, 9, 0, 0, 1, 1, 0x081E8FE9, 0x0000
	object_event 14, 39, 0, 34, 40, 3, 67, 0, 0, 1, 4, 0x081E9000, 0x0000
	object_event 15, 50, 0, 10, 19, 3, 8, 0, 0, 1, 1, 0x081E9062, 0x0000
	object_event 16, 60, 0, 5, 11, 3, 12, 0, 0, 0, 16, 0x08244D23, 0x0000
	object_event 17, 60, 0, 6, 11, 3, 12, 0, 0, 0, 17, 0x08244D23, 0x0000
	object_event 18, 60, 0, 7, 11, 3, 12, 0, 0, 0, 18, 0x08244D23, 0x0000
	object_event 19, 59, 0, 30, 69, 3, 1, 0, 0, 0, 0, 0x08256AD8, 0x03EF
	object_event 20, 59, 0, 26, 47, 3, 1, 0, 0, 0, 0, 0x08256ACB, 0x03EE
	object_event 21, 56, 0, 27, 92, 3, 8, 0, 0, 0, 0, Route110_EventScript_001E8F97, 0x0000
	object_event 22, 117, 0, 7, 83, 3, 7, 0, 0, 0, 0, Route110_EventScript_001E8E8A, 0x0384
	object_event 23, 117, 0, 8, 83, 3, 7, 0, 0, 0, 0, Route110_EventScript_001E8EA0, 0x0384
	object_event 24, 117, 0, 9, 83, 3, 7, 0, 0, 0, 0, Route110_EventScript_001E8EB6, 0x0384
	object_event 25, 117, 0, 10, 83, 3, 7, 0, 0, 0, 0, Route110_EventScript_001E8ECC, 0x0384
	object_event 26, 117, 0, 8, 82, 3, 8, 0, 0, 0, 0, 0x00000000, 0x0384
	object_event 27, 56, 0, 21, 78, 4, 51, 7, 1, 1, 2, 0x081E9079, 0x0000
	object_event 28, 240, 0, 34, 54, 3, 14, 0, 0, 0, 0, 0x00000000, 0x0397
	object_event 29, 243, 0, 34, 54, 3, 8, 0, 0, 0, 0, 0x00000000, 0x039A
	object_event 30, 35, 0, 33, 69, 3, 14, 0, 0, 1, 3, 0x081E91E4, 0x0000
	object_event 31, 18, 0, 10, 76, 3, 9, 0, 0, 1, 2, 0x081E9182, 0x0000
	object_event 32, 25, 0, 7, 76, 3, 10, 1, 1, 1, 2, 0x081E91FC, 0x0000
	object_event 33, 57, 0, 10, 39, 3, 9, 1, 1, 1, 6, 0x081E922A, 0x0000
	object_event 34, 66, 0, 36, 40, 3, 66, 1, 1, 1, 3, 0x081E9213, 0x0000
	object_event 35, 59, 0, 6, 38, 3, 1, 1, 1, 0, 0, 0x08256AE5, 0x0475
	object_event 36, 64, 0, 9, 79, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0345
	.globl ROUTE110_EventWarps
ROUTE110_EventWarps: @ 0x0850175C
	warp_def 35, 24, 3, 0, MAP_NEW_MAUVILLE_ENTRANCE
	warp_def 11, 66, 0, 0, MAP_ROUTE110_TRICK_HOUSE_ENTRANCE
	warp_def 15, 16, 0, 0, MAP_ROUTE110_SEASIDE_CYCLING_ROAD_NORTH_ENTRANCE
	warp_def 18, 16, 0, 2, MAP_ROUTE110_SEASIDE_CYCLING_ROAD_NORTH_ENTRANCE
	warp_def 16, 88, 0, 0, MAP_ROUTE110_SEASIDE_CYCLING_ROAD_SOUTH_ENTRANCE
	warp_def 19, 88, 0, 2, MAP_ROUTE110_SEASIDE_CYCLING_ROAD_SOUTH_ENTRANCE
	.globl ROUTE110_EventCoordEvents
ROUTE110_EventCoordEvents: @ 0x0850178C
	coord_event 28, 92, 3, 16553, 2, Route110_EventScript_001E9241
	coord_event 29, 92, 3, 16553, 2, Route110_EventScript_001E9241
	coord_event 33, 56, 3, 16489, 0, Route110_EventScript_001E932D
	coord_event 34, 56, 3, 16489, 0, Route110_EventScript_001E9338
	coord_event 35, 56, 3, 16489, 0, Route110_EventScript_001E9343
	coord_event 7, 85, 3, 16602, 1, Route110_EventScript_001E95AB
	coord_event 8, 85, 3, 16602, 1, Route110_EventScript_001E95B6
	coord_event 9, 85, 3, 16602, 1, Route110_EventScript_001E95C1
	coord_event 10, 85, 3, 16602, 1, Route110_EventScript_001E95CC
	.globl ROUTE110_EventBgEvents
ROUTE110_EventBgEvents: @ 0x0850181C
	bg_event 15, 25, 0, 0, Route110_EventScript_001E8F33, 0, 0
	bg_event 9, 51, 0, 0, Route110_EventScript_001E8F45, 0, 0
	bg_event 14, 88, 0, 0, Route110_EventScript_001E8F2A, 0, 0
	bg_event 20, 94, 0, 0, Route110_EventScript_001E8F21, 0, 0
	bg_event 7, 79, 0, 0, Route110_EventScript_001E8F3C, 0, 0
	bg_event 3, 17, 0, 0, Route110_EventScript_001E8F4E, 0, 0
	bg_event 16, 25, 0, 8, 0x00B5, 0x00, 0x00
	bg_event 17, 25, 0, 8, 0x00BF, 0x00, 0x00
	bg_event 33, 39, 3, 0, Route110_EventScript_001E8F57, 0, 0
	bg_event 37, 70, 3, 0, Route110_EventScript_001E8F60, 0, 0
	bg_event 8, 67, 0, 0, Route110_EventScript_001E8F69, 0, 0
	bg_event 32, 93, 0, 0, Route110_EventScript_001E8F72, 0, 0
	bg_event 35, 39, 3, 7, 0x0018, 0x36, 0x00
	bg_event 33, 45, 3, 7, 0x0003, 0x35, 0x00
	bg_event 4, 35, 3, 7, 0x0004, 0x41, 0x00
	bg_event 37, 67, 3, 7, 0x0017, 0x37, 0x00
	bg_event 13, 16, 0, 0, Route110_EventScript_001E8F2A, 0, 0
	.globl gMapEvents_ROUTE110
gMapEvents_ROUTE110: @ 0x085018E8
	map_events ROUTE110_EventObjects, ROUTE110_EventWarps, ROUTE110_EventCoordEvents, ROUTE110_EventBgEvents
	.globl ROUTE111_EventObjects
ROUTE111_EventObjects: @ 0x085018FC
	object_event 1, 19, 0, 13, 114, 3, 8, 0, 0, 0, 0, Route111_EventScript_001EA46B, 0x0300
	object_event 2, 18, 0, 13, 113, 0, 8, 0, 0, 0, 0, 0x00000000, 0x0301
	object_event 3, 47, 0, 13, 113, 0, 8, 1, 0, 0, 0, 0x00000000, 0x0302
	object_event 4, 22, 0, 13, 113, 0, 8, 0, 0, 0, 0, 0x00000000, 0x0303
	object_event 5, 32, 0, 28, 51, 3, 17, 0, 0, 1, 3, 0x081EA6C1, 0x0000
	object_event 6, 60, 0, 22, 5, 3, 12, 0, 0, 0, 19, 0x08244D23, 0x0000
	object_event 7, 60, 0, 23, 5, 3, 12, 0, 0, 0, 20, 0x08244D23, 0x0000
	object_event 8, 33, 0, 8, 91, 3, 2, 1, 1, 0, 0, Route111_EventScript_001EA62F, 0x0000
	object_event 9, 31, 0, 29, 37, 3, 17, 0, 0, 1, 3, 0x081EA6AA, 0x0000
	object_event 10, 55, 0, 27, 69, 3, 50, 2, 2, 1, 2, 0x081EA706, 0x0000
	object_event 11, 31, 0, 21, 47, 3, 9, 0, 0, 1, 4, 0x081EA6D8, 0x0000
	object_event 12, 32, 0, 32, 66, 3, 24, 0, 0, 1, 3, 0x081EA6EF, 0x0000
	object_event 13, 110, 0, 14, 86, 3, 8, 0, 0, 0, 0, 0x0825420E, 0x031C
	object_event 14, 68, 0, 13, 86, 3, 8, 0, 0, 0, 0, 0x082541EE, 0x031C
	object_event 15, 86, 0, 18, 101, 3, 1, 0, 0, 0, 0, 0x0825667C, 0x0011
	object_event 16, 86, 0, 19, 100, 3, 1, 0, 0, 0, 0, 0x0825667C, 0x0012
	object_event 17, 8, 0, 23, 8, 3, 5, 1, 0, 0, 0, Route111_EventScript_001EA35F, 0x0000
	object_event 18, 59, 0, 33, 104, 3, 1, 0, 0, 0, 0, 0x08256AF2, 0x03F0
	object_event 19, 60, 0, 18, 5, 3, 12, 0, 0, 0, 80, 0x08244D23, 0x0000
	object_event 20, 60, 0, 19, 5, 3, 12, 0, 0, 0, 81, 0x08244D23, 0x0000
	object_event 21, 68, 0, 13, 86, 3, 8, 0, 0, 0, 0, 0x082542AE, 0x031F
	object_event 22, 110, 0, 14, 86, 3, 8, 0, 0, 0, 0, 0x082542CE, 0x031F
	object_event 23, 68, 0, 13, 86, 3, 8, 0, 0, 0, 0, 0x0825432E, 0x0387
	object_event 24, 110, 0, 14, 86, 3, 8, 0, 0, 0, 0, 0x0825434E, 0x0387
	object_event 25, 59, 0, 12, 54, 3, 1, 0, 0, 0, 0, 0x08256AFF, 0x03F1
	object_event 26, 59, 0, 3, 114, 3, 1, 0, 0, 0, 0, 0x08256B0C, 0x03F2
	object_event 27, 82, 0, 22, 21, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0013
	object_event 28, 32, 0, 10, 82, 3, 14, 0, 0, 1, 2, 0x081EA77F, 0x0000
	object_event 29, 31, 0, 11, 71, 3, 22, 0, 0, 1, 3, 0x081EA768, 0x0000
	object_event 30, 44, 0, 32, 29, 3, 28, 1, 0, 1, 2, 0x081EA796, 0x0000
	object_event 31, 34, 0, 11, 11, 3, 7, 4, 0, 1, 4, 0x081EA80F, 0x0000
	object_event 32, 33, 0, 9, 27, 3, 17, 0, 0, 1, 3, 0x081EA7AD, 0x0000
	object_event 33, 7, 0, 13, 20, 3, 7, 1, 1, 0, 0, 0x08246512, 0x03C0
	object_event 34, 65, 0, 20, 114, 3, 2, 1, 1, 0, 0, Route111_EventScript_001EA638, 0x0000
	object_event 35, 31, 0, 26, 132, 3, 9, 1, 1, 1, 5, 0x081EA89F, 0x0000
	object_event 36, 20, 0, 20, 132, 3, 10, 1, 1, 1, 5, 0x081EA8B6, 0x0000
	object_event 37, 32, 0, 19, 121, 3, 7, 1, 1, 1, 2, 0x081EA888, 0x0000
	object_event 38, 66, 0, 16, 119, 3, 10, 1, 1, 1, 3, 0x081EA871, 0x0000
	object_event 39, 55, 0, 29, 77, 3, 14, 1, 1, 1, 7, 0x081EA8E4, 0x0000
	object_event 40, 32, 0, 22, 77, 3, 10, 1, 1, 1, 6, 0x081EA8CD, 0x0000
	object_event 41, 31, 0, 37, 77, 3, 9, 1, 1, 1, 7, 0x081EA8FB, 0x0000
	object_event 42, 59, 0, 19, 118, 3, 1, 1, 1, 0, 0, 0x08256B19, 0x0476
	object_event 43, 55, 0, 14, 56, 3, 16, 1, 1, 0, 0, Route111_EventScript_001EA641, 0x0000
	object_event 44, 199, 0, 20, 53, 3, 8, 1, 1, 0, 0, 0x00000000, 0x036C
	object_event 45, 240, 0, 19, 53, 3, 8, 1, 1, 0, 0, 0x00000000, 0x036B
	object_event 46, 17, 0, 19, 101, 3, 7, 1, 1, 0, 0, Route111_EventScript_001EA68A, 0x034B
	.globl ROUTE111_EventWarps
ROUTE111_EventWarps: @ 0x08501D4C
	warp_def 13, 113, 0, 0, MAP_ROUTE111_WINSTRATE_FAMILYS_HOUSE
	warp_def 29, 87, 0, 0, MAP_DESERT_RUINS
	warp_def 26, 18, 0, 0, MAP_ROUTE111_OLD_LADYS_REST_STOP
	warp_def 19, 58, 0, 0, MAP_MIRAGE_TOWER_1F
	warp_def 31, 113, 0, 0, MAP_TRAINER_HILL_ENTRANCE
	.globl ROUTE111_EventCoordEvents
ROUTE111_EventCoordEvents: @ 0x08501D74
	coord_event 12, 62, 3, 0, 0, Route111_EventScript_001EA463
	coord_event 11, 61, 3, 16387, 0, Route111_EventScript_001EA3B0
	coord_event 12, 61, 3, 16387, 0, Route111_EventScript_001EA3B0
	coord_event 13, 61, 3, 16387, 0, Route111_EventScript_001EA3B0
	coord_event 7, 63, 3, 0, 0, Route111_EventScript_001EA456
	coord_event 12, 44, 3, 16387, 0, Route111_EventScript_001EA3BC
	coord_event 13, 43, 3, 16387, 0, Route111_EventScript_001EA3BC
	coord_event 14, 42, 3, 16387, 0, Route111_EventScript_001EA3BC
	coord_event 16, 40, 3, 16387, 0, Route111_EventScript_001EA3BC
	coord_event 14, 61, 3, 16387, 0, Route111_EventScript_001EA3B0
	coord_event 18, 32, 3, 0, 0, Route111_EventScript_001EA456
	coord_event 17, 31, 3, 0, 0, Route111_EventScript_001EA456
	coord_event 9, 37, 3, 0, 0, Route111_EventScript_001EA456
	coord_event 10, 36, 3, 0, 0, Route111_EventScript_001EA456
	coord_event 17, 39, 3, 16387, 0, Route111_EventScript_001EA3BC
	coord_event 18, 38, 3, 16387, 0, Route111_EventScript_001EA3BC
	coord_event 8, 64, 3, 0, 0, Route111_EventScript_001EA456
	coord_event 9, 65, 3, 0, 0, Route111_EventScript_001EA456
	coord_event 10, 65, 3, 0, 0, Route111_EventScript_001EA456
	coord_event 11, 66, 3, 0, 0, Route111_EventScript_001EA456
	coord_event 12, 67, 3, 0, 0, Route111_EventScript_001EA456
	coord_event 13, 68, 3, 0, 0, Route111_EventScript_001EA456
	coord_event 14, 69, 3, 0, 0, Route111_EventScript_001EA456
	coord_event 10, 61, 3, 0, 0, Route111_EventScript_001EA463
	coord_event 11, 62, 3, 0, 0, Route111_EventScript_001EA463
	coord_event 13, 62, 3, 0, 0, Route111_EventScript_001EA463
	coord_event 14, 62, 3, 0, 0, Route111_EventScript_001EA463
	coord_event 17, 38, 3, 0, 0, Route111_EventScript_001EA463
	coord_event 16, 39, 3, 0, 0, Route111_EventScript_001EA463
	coord_event 15, 40, 3, 0, 0, Route111_EventScript_001EA463
	coord_event 14, 41, 3, 0, 0, Route111_EventScript_001EA463
	coord_event 13, 42, 3, 0, 0, Route111_EventScript_001EA463
	coord_event 12, 43, 3, 0, 0, Route111_EventScript_001EA463
	coord_event 11, 44, 3, 0, 0, Route111_EventScript_001EA463
	.globl ROUTE111_EventBgEvents
ROUTE111_EventBgEvents: @ 0x08501F94
	bg_event 16, 114, 0, 0, Route111_EventScript_001EA602, 0, 0
	bg_event 24, 126, 0, 0, Route111_EventScript_001EA5F9, 0, 0
	bg_event 7, 66, 0, 0, Route111_EventScript_001EA60B, 0, 0
	bg_event 13, 6, 0, 0, Route111_EventScript_001EA614, 0, 0
	bg_event 24, 36, 0, 8, 0x0083, 0x00, 0x00
	bg_event 34, 50, 0, 8, 0x008D, 0x00, 0x00
	bg_event 33, 34, 0, 8, 0x0079, 0x00, 0x00
	bg_event 25, 19, 0, 0, Route111_EventScript_001EA61D, 0, 0
	bg_event 35, 1, 0, 8, 0x000D, 0x00, 0x00
	bg_event 35, 31, 0, 8, 0x0099, 0x00, 0x00
	bg_event 26, 70, 0, 7, 0x006C, 0x02, 0x00
	bg_event 27, 27, 3, 8, 0x0021, 0x00, 0x00
	bg_event 7, 84, 3, 0, Route111_EventScript_001EA626, 0, 0
	bg_event 14, 19, 0, 8, 0x00A4, 0x00, 0x00
	bg_event 13, 19, 0, 8, 0x00A1, 0x00, 0x00
	bg_event 19, 55, 0, 7, 0x0040, 0x38, 0x00
	bg_event 35, 66, 0, 7, 0x0044, 0x39, 0x00
	bg_event 24, 116, 0, 0, Route111_EventScript_001EA912, 0, 0
	.globl gMapEvents_ROUTE111
gMapEvents_ROUTE111: @ 0x0850206C
	map_events ROUTE111_EventObjects, ROUTE111_EventWarps, ROUTE111_EventCoordEvents, ROUTE111_EventBgEvents
	.globl ROUTE112_EventObjects
ROUTE112_EventObjects: @ 0x08502080
	object_event 1, 119, 0, 26, 30, 3, 7, 1, 1, 0, 0, Route112_EventScript_001EAE9B, 0x0333
	object_event 2, 55, 0, 24, 34, 3, 14, 0, 0, 1, 2, 0x081EAF4E, 0x0000
	object_event 3, 31, 0, 29, 49, 3, 8, 0, 0, 1, 3, 0x081EAFC7, 0x0000
	object_event 4, 32, 0, 22, 46, 3, 23, 0, 0, 1, 3, 0x081EAFDE, 0x0000
	object_event 5, 55, 0, 15, 40, 3, 16, 0, 0, 1, 3, 0x081EAF65, 0x0000
	object_event 6, 119, 0, 27, 30, 3, 7, 0, 0, 0, 0, Route112_EventScript_001EAE9B, 0x0333
	object_event 7, 60, 0, 27, 6, 0, 12, 0, 0, 0, 24, 0x08244D23, 0x0000
	object_event 8, 60, 0, 28, 6, 0, 12, 0, 0, 0, 23, 0x08244D23, 0x0000
	object_event 9, 60, 0, 29, 6, 0, 12, 0, 0, 0, 22, 0x08244D23, 0x0000
	object_event 10, 60, 0, 30, 6, 3, 12, 0, 0, 0, 21, 0x08244D23, 0x0000
	object_event 11, 55, 0, 8, 50, 3, 26, 0, 3, 0, 0, Route112_EventScript_001EAF45, 0x0000
	object_event 12, 59, 0, 14, 43, 3, 1, 0, 0, 0, 0, 0x08256B26, 0x03F3
	object_event 13, 66, 0, 31, 7, 3, 18, 1, 1, 1, 3, 0x081EAFF5, 0x0000
	object_event 14, 20, 0, 31, 11, 3, 15, 1, 1, 1, 3, 0x081EB00C, 0x0000
	.globl ROUTE112_EventWarps
ROUTE112_EventWarps: @ 0x085021D0
	warp_def 28, 27, 0, 0, MAP_ROUTE112_CABLE_CAR_STATION
	warp_def 29, 27, 0, 1, MAP_ROUTE112_CABLE_CAR_STATION
	warp_def 6, 46, 3, 0, MAP_JAGGED_PASS
	warp_def 7, 46, 3, 1, MAP_JAGGED_PASS
	warp_def 11, 36, 0, 0, MAP_FIERY_PATH
	warp_def 22, 10, 0, 1, MAP_FIERY_PATH
	.globl ROUTE112_EventBgEvents
ROUTE112_EventBgEvents: @ 0x08502200
	bg_event 19, 44, 3, 0, Route112_EventScript_001EAF33, 0, 0
	bg_event 22, 37, 0, 0, Route112_EventScript_001EAF2A, 0, 0
	bg_event 4, 49, 0, 0, Route112_EventScript_001EAF3C, 0, 0
	.globl gMapEvents_ROUTE112
gMapEvents_ROUTE112: @ 0x08502224
	map_events ROUTE112_EventObjects, ROUTE112_EventWarps, 0, ROUTE112_EventBgEvents
	.globl ROUTE113_EventObjects
ROUTE113_EventObjects: @ 0x08502238
	object_event 1, 5, 0, 66, 12, 3, 5, 1, 0, 0, 0, Route113_EventScript_001EB193, 0x0000
	object_event 2, 48, 0, 36, 10, 3, 3, 0, 1, 0, 0, Route113_EventScript_001EB18A, 0x0000
	object_event 3, 35, 0, 62, 8, 3, 8, 0, 0, 1, 3, 0x081EB1C0, 0x0000
	object_event 4, 35, 0, 21, 11, 3, 17, 0, 0, 1, 3, 0x081EB1D7, 0x0000
	object_event 5, 34, 0, 51, 11, 3, 23, 0, 0, 1, 2, 0x081EB1EE, 0x0000
	object_event 6, 59, 0, 53, 7, 3, 1, 0, 0, 0, 0, 0x08256B33, 0x03F4
	object_event 7, 59, 0, 79, 5, 3, 1, 0, 0, 0, 0, 0x08256B40, 0x03F5
	object_event 8, 5, 0, 29, 6, 3, 63, 0, 0, 3, 1, 0x081EB250, 0x0000
	object_event 9, 5, 0, 71, 2, 3, 63, 0, 0, 3, 1, 0x081EB2B2, 0x0000
	object_event 10, 6, 0, 45, 6, 3, 8, 1, 1, 1, 1, 0x081EB2C9, 0x0000
	object_event 11, 6, 0, 46, 6, 3, 8, 1, 1, 1, 1, 0x081EB2E4, 0x0000
	object_event 12, 59, 0, 15, 15, 3, 1, 1, 1, 0, 0, 0x08256B4D, 0x0477
	object_event 13, 39, 0, 75, 3, 3, 9, 1, 1, 1, 4, 0x081EB344, 0x0000
	object_event 14, 31, 0, 71, 4, 3, 7, 1, 1, 1, 1, 0x081EB32D, 0x0000
	object_event 15, 32, 0, 7, 6, 3, 26, 1, 3, 1, 6, 0x081EB2FF, 0x0000
	object_event 16, 66, 0, 7, 13, 3, 25, 1, 3, 1, 6, 0x081EB316, 0x0000
	.globl ROUTE113_EventWarps
ROUTE113_EventWarps: @ 0x085023B8
	warp_def 33, 5, 0, 0, MAP_ROUTE113_GLASS_WORKSHOP
	warp_def 41, 12, 0, 0, MAP_TERRA_CAVE_ENTRANCE
	warp_def 88, 5, 0, 0, MAP_TERRA_CAVE_ENTRANCE
	.globl ROUTE113_EventCoordEvents
ROUTE113_EventCoordEvents: @ 0x085023D0
	coord_event 19, 11, 3, 8, 0, 0x00000000
	coord_event 19, 10, 3, 8, 0, 0x00000000
	coord_event 19, 12, 3, 8, 0, 0x00000000
	coord_event 19, 13, 3, 8, 0, 0x00000000
	coord_event 86, 9, 3, 8, 0, 0x00000000
	coord_event 85, 10, 3, 8, 0, 0x00000000
	coord_event 85, 11, 3, 8, 0, 0x00000000
	coord_event 14, 10, 3, 2, 0, 0x00000000
	coord_event 14, 11, 3, 2, 0, 0x00000000
	coord_event 14, 12, 3, 2, 0, 0x00000000
	coord_event 14, 13, 3, 2, 0, 0x00000000
	coord_event 94, 8, 3, 2, 0, 0x00000000
	coord_event 94, 9, 3, 2, 0, 0x00000000
	coord_event 94, 10, 3, 2, 0, 0x00000000
	coord_event 94, 11, 0, 2, 0, 0x00000000
	coord_event 19, 14, 3, 8, 0, 0x00000000
	coord_event 87, 8, 3, 8, 0, 0x00000000
	coord_event 87, 6, 3, 8, 0, 0x00000000
	coord_event 87, 7, 3, 8, 0, 0x00000000
	.globl ROUTE113_EventBgEvents
ROUTE113_EventBgEvents: @ 0x08502500
	bg_event 85, 6, 0, 0, Route113_EventScript_001EB19C, 0, 0
	bg_event 12, 9, 0, 0, Route113_EventScript_001EB1A5, 0, 0
	bg_event 58, 4, 3, 0, Route113_EventScript_001EB1B7, 0, 0
	bg_event 31, 5, 0, 0, Route113_EventScript_001EB1AE, 0, 0
	bg_event 49, 8, 3, 8, 0x0003, 0x00, 0x00
	bg_event 66, 3, 3, 7, 0x0022, 0x03, 0x00
	bg_event 22, 5, 3, 7, 0x0140, 0x1E, 0x00
	bg_event 73, 3, 3, 7, 0x006E, 0x62, 0x00
	.globl gMapEvents_ROUTE113
gMapEvents_ROUTE113: @ 0x08502560
	map_events ROUTE113_EventObjects, ROUTE113_EventWarps, ROUTE113_EventCoordEvents, ROUTE113_EventBgEvents
	.globl ROUTE114_EventObjects
ROUTE114_EventObjects: @ 0x08502574
	object_event 1, 60, 0, 31, 43, 3, 12, 0, 0, 0, 77, 0x08244D23, 0x0000
	object_event 2, 60, 0, 31, 44, 3, 12, 0, 0, 0, 78, 0x08244D23, 0x0000
	object_event 3, 55, 0, 15, 65, 7, 10, 0, 0, 1, 6, 0x081EB585, 0x0000
	object_event 4, 55, 0, 30, 72, 5, 9, 0, 0, 1, 4, 0x081EB59C, 0x0000
	object_event 5, 31, 0, 22, 50, 3, 10, 0, 0, 1, 3, 0x081EB5B3, 0x0000
	object_event 6, 32, 0, 19, 35, 3, 1, 0, 0, 1, 3, 0x081EB5CA, 0x0000
	object_event 7, 39, 0, 20, 56, 3, 7, 0, 0, 1, 3, 0x081EB5E1, 0x0000
	object_event 8, 60, 0, 31, 45, 3, 12, 0, 0, 0, 68, 0x08244D23, 0x0000
	object_event 9, 59, 0, 7, 6, 3, 1, 0, 0, 0, 0, 0x08256B5A, 0x03F6
	object_event 10, 59, 0, 11, 37, 4, 1, 0, 0, 0, 0, 0x08256B67, 0x03F7
	object_event 11, 86, 0, 12, 43, 4, 1, 0, 0, 0, 0, 0x0825667C, 0x0011
	object_event 12, 48, 0, 19, 11, 3, 10, 0, 0, 0, 0, Route114_EventScript_001EB516, 0x0000
	object_event 13, 220, 0, 19, 12, 3, 10, 0, 0, 0, 0, Route114_EventScript_001EB557, 0x0000
	object_event 14, 65, 0, 27, 42, 3, 3, 0, 1, 0, 0, Route114_EventScript_001EB4C7, 0x0000
	object_event 15, 50, 0, 25, 6, 3, 8, 0, 0, 1, 0, 0x081EB6BC, 0x0000
	object_event 16, 50, 0, 19, 26, 3, 9, 0, 0, 1, 0, 0x081EB6A5, 0x0000
	object_event 17, 66, 0, 30, 58, 5, 23, 0, 0, 1, 3, 0x081EB643, 0x0000
	object_event 18, 86, 0, 29, 53, 5, 1, 1, 1, 0, 0, 0x0825667C, 0x0012
	object_event 19, 86, 0, 30, 54, 5, 1, 1, 1, 0, 0, 0x0825667C, 0x0013
	object_event 20, 86, 0, 22, 69, 7, 1, 1, 1, 0, 0, 0x0825667C, 0x0014
	object_event 21, 86, 0, 11, 64, 5, 1, 1, 1, 0, 0, 0x0825667C, 0x0015
	object_event 22, 47, 0, 24, 44, 3, 8, 1, 1, 1, 1, 0x081EB6EE, 0x0000
	object_event 23, 47, 0, 23, 44, 3, 8, 1, 1, 1, 1, 0x081EB6D3, 0x0000
	object_event 24, 32, 0, 28, 20, 3, 7, 1, 1, 1, 3, 0x081EB720, 0x0000
	object_event 25, 32, 0, 26, 72, 5, 18, 1, 1, 1, 4, 0x081EB709, 0x0000
	object_event 26, 59, 0, 31, 19, 3, 1, 1, 1, 0, 0, 0x08256B74, 0x0488
	object_event 27, 50, 0, 28, 16, 3, 17, 1, 1, 1, 3, 0x081EB737, 0x0000
	.globl ROUTE114_EventWarps
ROUTE114_EventWarps: @ 0x085027FC
	warp_def 8, 63, 0, 0, MAP_METEOR_FALLS_1F_1R
	warp_def 29, 5, 0, 0, MAP_ROUTE114_FOSSIL_MANIACS_HOUSE
	warp_def 27, 36, 0, 0, MAP_ROUTE114_LANETTES_HOUSE
	warp_def 6, 46, 0, 0, MAP_TERRA_CAVE_ENTRANCE
	warp_def 7, 4, 0, 0, MAP_TERRA_CAVE_ENTRANCE
	.globl ROUTE114_EventBgEvents
ROUTE114_EventBgEvents: @ 0x08502824
	bg_event 7, 64, 0, 0, Route114_EventScript_001EB56A, 0, 0
	bg_event 31, 7, 0, 0, Route114_EventScript_001EB573, 0, 0
	bg_event 9, 47, 0, 8, 0x0029, 0x00, 0x00
	bg_event 30, 51, 0, 8, 0x0033, 0x00, 0x00
	bg_event 11, 62, 0, 8, 0x003D, 0x00, 0x00
	bg_event 19, 70, 0, 8, 0x0047, 0x00, 0x00
	bg_event 11, 27, 0, 8, 0x00B6, 0x00, 0x00
	bg_event 12, 27, 0, 8, 0x00C0, 0x00, 0x00
	bg_event 25, 38, 3, 0, Route114_EventScript_001EB57C, 0, 0
	bg_event 20, 57, 3, 7, 0x0042, 0x04, 0x00
	bg_event 32, 57, 0, 8, 0x0049, 0x00, 0x00
	bg_event 7, 30, 3, 7, 0x0018, 0x2A, 0x00
	.globl gMapEvents_ROUTE114
gMapEvents_ROUTE114: @ 0x085028B4
	map_events ROUTE114_EventObjects, ROUTE114_EventWarps, 0, ROUTE114_EventBgEvents
	.globl ROUTE115_EventObjects
ROUTE115_EventObjects: @ 0x085028C8
	object_event 1, 20, 0, 18, 68, 3, 2, 1, 1, 0, 0, Route115_EventScript_001EB857, 0x0000
	object_event 2, 21, 0, 5, 15, 3, 10, 0, 0, 1, 6, 0x081EB872, 0x0000
	object_event 3, 44, 0, 27, 53, 3, 15, 1, 1, 1, 4, 0x081EB8EB, 0x0000
	object_event 4, 60, 0, 12, 5, 3, 12, 0, 0, 0, 69, 0x08244D23, 0x0000
	object_event 5, 60, 0, 13, 5, 3, 12, 0, 0, 0, 70, 0x08244D23, 0x0000
	object_event 6, 60, 0, 14, 5, 3, 12, 0, 0, 0, 71, 0x08244D23, 0x0000
	object_event 7, 14, 0, 15, 50, 3, 64, 0, 0, 1, 3, 0x081EB94D, 0x0000
	object_event 8, 44, 0, 19, 15, 3, 27, 5, 0, 1, 2, 0x081EB8D4, 0x0000
	object_event 9, 39, 0, 24, 62, 3, 18, 0, 0, 1, 4, 0x081EB9AF, 0x0000
	object_event 10, 59, 0, 20, 60, 3, 1, 0, 0, 0, 0, 0x08256B81, 0x03F8
	object_event 11, 59, 0, 18, 7, 3, 1, 0, 0, 0, 0, 0x08256B8E, 0x03F9
	object_event 12, 59, 0, 23, 29, 3, 1, 0, 0, 0, 0, 0x08256B9B, 0x03FA
	object_event 13, 60, 0, 31, 64, 3, 12, 0, 0, 0, 55, 0x08244D23, 0x0000
	object_event 14, 60, 0, 31, 65, 3, 12, 0, 0, 0, 56, 0x08244D23, 0x0000
	object_event 15, 86, 0, 29, 50, 3, 1, 1, 1, 0, 0, 0x0825667C, 0x0011
	object_event 16, 59, 0, 31, 56, 3, 1, 1, 1, 0, 0, 0x08256BA8, 0x045E
	object_event 17, 52, 0, 10, 15, 3, 46, 3, 3, 1, 2, 0x081EB9C6, 0x0000
	object_event 18, 5, 0, 11, 12, 3, 57, 1, 1, 1, 3, 0x081EB9DD, 0x0000
	object_event 19, 14, 0, 15, 7, 3, 9, 1, 1, 1, 4, 0x081EBA0B, 0x0000
	object_event 20, 47, 0, 10, 7, 3, 10, 1, 1, 1, 4, 0x081EB9F4, 0x0000
	object_event 21, 47, 0, 28, 62, 3, 9, 1, 1, 1, 4, 0x081EBA22, 0x0000
	object_event 22, 59, 0, 26, 67, 3, 1, 1, 1, 0, 0, 0x08256BC2, 0x0489
	object_event 23, 59, 0, 12, 14, 3, 1, 1, 1, 0, 0, 0x08256BB5, 0x0478
	.globl ROUTE115_EventWarps
ROUTE115_EventWarps: @ 0x08502AF0
	warp_def 27, 37, 0, 1, MAP_METEOR_FALLS_1F_1R
	warp_def 21, 6, 0, 0, MAP_TERRA_CAVE_ENTRANCE
	warp_def 36, 10, 0, 0, MAP_TERRA_CAVE_ENTRANCE
	.globl ROUTE115_EventBgEvents
ROUTE115_EventBgEvents: @ 0x08502B08
	bg_event 32, 6, 0, 8, 0x0048, 0x00, 0x00
	bg_event 21, 18, 0, 8, 0x003E, 0x00, 0x00
	bg_event 16, 64, 0, 0, Route115_EventScript_001EB860, 0, 0
	bg_event 25, 38, 3, 0, Route115_EventScript_001EB869, 0, 0
	bg_event 8, 30, 0, 8, 0x0085, 0x00, 0x00
	bg_event 32, 39, 0, 8, 0x002A, 0x00, 0x00
	bg_event 26, 15, 0, 8, 0x0034, 0x00, 0x00
	bg_event 23, 8, 0, 8, 0x002B, 0x00, 0x00
	bg_event 32, 46, 0, 8, 0x0035, 0x00, 0x00
	bg_event 7, 20, 0, 8, 0x00AE, 0x00, 0x00
	bg_event 8, 20, 0, 8, 0x00B7, 0x00, 0x00
	bg_event 25, 24, 0, 8, 0x003F, 0x00, 0x00
	bg_event 20, 53, 0, 8, 0x0015, 0x00, 0x00
	bg_event 15, 49, 3, 7, 0x006F, 0x61, 0x00
	.globl gMapEvents_ROUTE115
gMapEvents_ROUTE115: @ 0x08502BB0
	map_events ROUTE115_EventObjects, ROUTE115_EventWarps, 0, ROUTE115_EventBgEvents
	.globl ROUTE116_EventObjects
ROUTE116_EventObjects: @ 0x08502BC4
	object_event 1, 60, 0, 18, 2, 3, 12, 0, 0, 0, 25, 0x08244D23, 0x0000
	object_event 2, 60, 0, 19, 2, 3, 12, 0, 0, 0, 26, 0x08244D23, 0x0000
	object_event 3, 35, 0, 12, 7, 3, 16, 0, 0, 1, 3, 0x081EBD32, 0x0000
	object_event 4, 82, 0, 21, 6, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0011
	object_event 5, 82, 0, 32, 10, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0012
	object_event 6, 36, 0, 13, 17, 3, 24, 0, 0, 1, 2, 0x081EBD49, 0x0000
	object_event 7, 59, 0, 19, 6, 3, 1, 0, 0, 0, 0, 0x08256BDC, 0x03FB
	object_event 8, 59, 0, 10, 17, 3, 1, 0, 0, 0, 0, 0x08256BE9, 0x03FC
	object_event 9, 60, 0, 20, 2, 3, 12, 0, 0, 0, 66, 0x08244D23, 0x0000
	object_event 10, 60, 0, 21, 2, 3, 12, 0, 0, 0, 67, 0x08244D23, 0x0000
	object_event 11, 21, 0, 46, 9, 3, 1, 0, 0, 0, 0, Route116_EventScript_001EBC2D, 0x037B
	object_event 12, 82, 0, 28, 11, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0013
	object_event 13, 55, 0, 36, 17, 3, 15, 0, 0, 1, 3, 0x081EBE0E, 0x0000
	object_event 14, 82, 0, 24, 9, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0014
	object_event 15, 59, 0, 80, 8, 3, 1, 0, 0, 0, 0, 0x08256BF6, 0x03FD
	object_event 16, 47, 0, 26, 6, 3, 10, 0, 0, 1, 2, 0x081EBE25, 0x0000
	object_event 17, 14, 0, 22, 16, 3, 13, 0, 0, 1, 3, 0x081EBE3C, 0x0000
	object_event 18, 38, 0, 28, 8, 3, 7, 0, 0, 1, 4, 0x081EBD60, 0x0000
	object_event 19, 23, 0, 46, 11, 3, 1, 1, 1, 0, 0, Route116_EventScript_001EBB4B, 0x03B3
	object_event 20, 59, 0, 55, 12, 4, 1, 1, 1, 0, 0, 0x08256BCF, 0x03E9
	object_event 21, 44, 0, 38, 9, 3, 10, 1, 1, 0, 0, Route116_EventScript_001EBB19, 0x037E
	object_event 22, 39, 0, 74, 13, 3, 1, 1, 1, 0, 0, Route116_EventScript_001EBC5F, 0x032D
	object_event 23, 20, 0, 33, 8, 3, 7, 0, 0, 1, 1, 0x081EBEEA, 0x0000
	object_event 24, 9, 0, 33, 5, 3, 8, 0, 0, 1, 2, 0x081EBF01, 0x0000
	object_event 25, 59, 0, 34, 7, 0, 1, 1, 1, 0, 0, 0x08256C03, 0x047A
	object_event 26, 82, 0, 30, 5, 3, 1, 1, 1, 0, 0, 0x082565C8, 0x0015
	object_event 27, 35, 0, 36, 13, 3, 18, 1, 1, 1, 5, 0x081EBF2F, 0x0000
	object_event 28, 55, 0, 42, 13, 3, 9, 1, 1, 1, 5, 0x081EBF18, 0x0000
	.globl ROUTE116_EventWarps
ROUTE116_EventWarps: @ 0x08502E64
	warp_def 47, 8, 0, 0, MAP_RUSTURF_TUNNEL
	warp_def 38, 8, 0, 0, MAP_ROUTE116_TUNNELERS_REST_HOUSE
	warp_def 65, 10, 0, 2, MAP_RUSTURF_TUNNEL
	warp_def 59, 13, 0, 0, MAP_TERRA_CAVE_ENTRANCE
	warp_def 79, 6, 0, 0, MAP_TERRA_CAVE_ENTRANCE
	.globl ROUTE116_EventCoordEvents
ROUTE116_EventCoordEvents: @ 0x08502E8C
	coord_event 47, 9, 3, 16495, 1, Route116_EventScript_001EBC3E
	.globl ROUTE116_EventBgEvents
ROUTE116_EventBgEvents: @ 0x08502E9C
	bg_event 5, 10, 0, 0, Route116_EventScript_001EBC00, 0, 0
	bg_event 48, 9, 0, 0, Route116_EventScript_001EBC09, 0, 0
	bg_event 40, 9, 0, 0, Route116_EventScript_001EBC12, 0, 0
	bg_event 71, 4, 0, 8, 0x0051, 0x00, 0x00
	bg_event 79, 11, 0, 8, 0x005B, 0x00, 0x00
	bg_event 16, 12, 0, 0, Route116_EventScript_001EBC1B, 0, 0
	bg_event 29, 10, 0, 0, Route116_EventScript_001EBC24, 0, 0
	bg_event 56, 6, 0, 8, 0x0066, 0x00, 0x00
	bg_event 55, 15, 0, 8, 0x0070, 0x00, 0x00
	bg_event 22, 9, 3, 7, 0x0016, 0x2D, 0x00
	bg_event 70, 13, 3, 7, 0x00CE, 0x60, 0x00
	.globl gMapEvents_ROUTE116
gMapEvents_ROUTE116: @ 0x08502F20
	map_events ROUTE116_EventObjects, ROUTE116_EventWarps, ROUTE116_EventCoordEvents, ROUTE116_EventBgEvents
	.globl ROUTE117_EventObjects
ROUTE117_EventObjects: @ 0x08502F34
	object_event 1, 16, 0, 13, 13, 3, 8, 0, 0, 0, 0, Route117_EventScript_001EC440, 0x0000
	object_event 2, 11, 0, 25, 5, 3, 40, 2, 2, 0, 0, Route117_EventScript_001EC449, 0x0000
	object_event 3, 29, 0, 47, 4, 3, 8, 0, 0, 0, 0, 0x082576E1, 0x0000
	object_event 4, 208, 0, 33, 3, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 5, 204, 0, 39, 4, 3, 1, 0, 0, 0, 0, 0x00000000, 0x0000
	object_event 6, 210, 0, 42, 2, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 7, 209, 0, 49, 2, 3, 1, 0, 0, 0, 0, 0x00000000, 0x0000
	object_event 8, 51, 0, 38, 16, 3, 28, 8, 0, 1, 4, 0x081EC53A, 0x0000
	object_event 9, 20, 0, 8, 10, 3, 23, 0, 0, 1, 3, 0x081EC4D8, 0x0000
	object_event 10, 65, 0, 33, 11, 3, 16, 0, 0, 1, 4, 0x081EC476, 0x0000
	object_event 11, 60, 0, 41, 13, 3, 12, 0, 0, 0, 29, 0x08244D23, 0x0000
	object_event 12, 60, 0, 42, 13, 3, 12, 0, 0, 0, 28, 0x08244D23, 0x0000
	object_event 13, 60, 0, 43, 13, 3, 12, 0, 0, 0, 27, 0x08244D23, 0x0000
	object_event 14, 59, 0, 16, 18, 3, 1, 0, 0, 0, 0, 0x08256C10, 0x03FE
	object_event 15, 82, 0, 15, 2, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0011
	object_event 16, 59, 0, 9, 1, 3, 1, 0, 0, 0, 0, 0x08256C1D, 0x03FF
	object_event 17, 52, 0, 26, 13, 3, 33, 2, 2, 1, 5, 0x081EC59C, 0x0000
	object_event 18, 39, 0, 17, 12, 3, 7, 1, 1, 1, 4, 0x081EC5FE, 0x0000
	object_event 19, 47, 0, 43, 6, 3, 8, 0, 0, 1, 1, 0x081EC679, 0x0000
	object_event 20, 47, 0, 42, 6, 3, 8, 0, 0, 1, 1, 0x081EC615, 0x0000
	object_event 21, 10, 0, 48, 10, 3, 2, 1, 1, 0, 0, Route117_EventScript_001EC452, 0x0000
	object_event 22, 47, 0, 15, 4, 3, 10, 1, 1, 1, 4, 0x081EC6F4, 0x0000
	object_event 23, 14, 0, 21, 4, 3, 9, 1, 1, 1, 4, 0x081EC70B, 0x0000
	object_event 24, 52, 0, 16, 4, 3, 28, 4, 1, 1, 4, 0x081EC6DD, 0x0000
	.globl ROUTE117_EventWarps
ROUTE117_EventWarps: @ 0x08503174
	warp_def 51, 5, 0, 0, MAP_ROUTE117_POKEMON_DAY_CARE
	.globl ROUTE117_EventBgEvents
ROUTE117_EventBgEvents: @ 0x0850317C
	bg_event 16, 6, 0, 0, Route117_EventScript_001EC45B, 0, 0
	bg_event 49, 12, 0, 0, Route117_EventScript_001EC464, 0, 0
	bg_event 49, 5, 0, 0, Route117_EventScript_001EC46D, 0, 0
	bg_event 3, 18, 3, 7, 0x0056, 0x48, 0x00
	.globl gMapEvents_ROUTE117
gMapEvents_ROUTE117: @ 0x085031AC
	map_events ROUTE117_EventObjects, ROUTE117_EventWarps, 0, ROUTE117_EventBgEvents
	.globl ROUTE118_EventObjects
ROUTE118_EventObjects: @ 0x085031C0
	object_event 1, 60, 0, 35, 5, 3, 12, 0, 0, 0, 31, 0x08244D23, 0x0000
	object_event 2, 60, 0, 36, 5, 3, 12, 0, 0, 0, 32, 0x08244D23, 0x0000
	object_event 3, 60, 0, 37, 5, 3, 12, 0, 0, 0, 33, 0x08244D23, 0x0000
	object_event 4, 66, 0, 64, 10, 3, 8, 0, 0, 1, 3, 0x081ECAA6, 0x0000
	object_event 5, 68, 0, 33, 8, 3, 8, 0, 0, 0, 0, 0x0825422E, 0x031D
	object_event 6, 110, 0, 34, 8, 3, 8, 0, 0, 0, 0, 0x0825424E, 0x031D
	object_event 7, 10, 0, 12, 10, 3, 2, 1, 1, 0, 0, Route118_EventScript_001EC8A0, 0x0000
	object_event 8, 68, 0, 33, 8, 3, 8, 0, 0, 0, 0, 0x082542EE, 0x0385
	object_event 9, 110, 0, 34, 8, 3, 8, 0, 0, 0, 0, 0x0825430E, 0x0385
	object_event 10, 68, 0, 33, 8, 3, 8, 0, 0, 0, 0, 0x0825432E, 0x0388
	object_event 11, 110, 0, 34, 8, 3, 8, 0, 0, 0, 0, 0x0825434E, 0x0388
	object_event 12, 82, 0, 38, 8, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0011
	object_event 13, 50, 0, 28, 8, 3, 9, 0, 0, 0, 0, Route118_EventScript_001EC841, 0x0000
	object_event 14, 20, 0, 7, 12, 3, 7, 0, 0, 1, 4, 0x081EC9B4, 0x0000
	object_event 15, 50, 0, 14, 14, 3, 8, 0, 0, 1, 0, 0x081ECA2D, 0x0000
	object_event 16, 66, 0, 56, 7, 3, 16, 0, 0, 1, 3, 0x081ECABD, 0x0000
	object_event 17, 50, 0, 39, 15, 3, 1, 0, 0, 1, 2, 0x081ECA16, 0x0000
	object_event 18, 66, 0, 17, 11, 3, 15, 1, 1, 1, 3, 0x081ECA44, 0x0000
	object_event 19, 134, 0, 44, 7, 3, 8, 1, 1, 0, 0, 0x00000000, 0x03C6
	object_event 20, 59, 0, 69, 7, 3, 1, 1, 1, 0, 0, 0x08256C2A, 0x0461
	object_event 21, 35, 0, 7, 7, 3, 8, 1, 1, 1, 4, 0x081ECAD4, 0x0000
	.globl ROUTE118_EventWarps
ROUTE118_EventWarps: @ 0x085033B8
	warp_def 42, 6, 0, 0, MAP_TERRA_CAVE_ENTRANCE
	warp_def 9, 6, 0, 0, MAP_TERRA_CAVE_ENTRANCE
	.globl ROUTE118_EventCoordEvents
ROUTE118_EventCoordEvents: @ 0x085033C8
	coord_event 43, 11, 3, 16497, 0, Route118_EventScript_001EC8BB
	coord_event 44, 11, 3, 16497, 0, Route118_EventScript_001EC8DB
	coord_event 45, 11, 3, 16497, 0, Route118_EventScript_001EC8F1
	.globl ROUTE118_EventBgEvents
ROUTE118_EventBgEvents: @ 0x085033F8
	bg_event 47, 14, 0, 8, 0x0001, 0x00, 0x00
	bg_event 13, 6, 0, 0, Route118_EventScript_001EC8A9, 0, 0
	bg_event 56, 8, 0, 0, Route118_EventScript_001EC8B2, 0, 0
	bg_event 67, 6, 0, 8, 0x000B, 0x00, 0x00
	bg_event 29, 5, 0, 8, 0x007A, 0x00, 0x00
	bg_event 47, 5, 0, 8, 0x00A3, 0x00, 0x00
	bg_event 46, 5, 0, 8, 0x00AB, 0x00, 0x00
	bg_event 31, 13, 3, 7, 0x0041, 0x43, 0x00
	bg_event 12, 14, 3, 7, 0x006F, 0x42, 0x00
	.globl gMapEvents_ROUTE118
gMapEvents_ROUTE118: @ 0x08503464
	map_events ROUTE118_EventObjects, ROUTE118_EventWarps, ROUTE118_EventCoordEvents, ROUTE118_EventBgEvents
	.globl ROUTE119_EventObjects
ROUTE119_EventObjects: @ 0x08503478
	object_event 1, 60, 0, 24, 5, 3, 12, 0, 0, 0, 34, 0x08244D23, 0x0000
	object_event 2, 60, 0, 25, 5, 3, 12, 0, 0, 0, 35, 0x08244D23, 0x0000
	object_event 3, 60, 0, 26, 5, 3, 12, 0, 0, 0, 36, 0x08244D23, 0x0000
	object_event 4, 36, 0, 12, 123, 3, 59, 0, 0, 1, 1, 0x081ED0A3, 0x0000
	object_event 5, 39, 0, 26, 123, 3, 60, 0, 0, 1, 1, 0x081ED075, 0x0000
	object_event 6, 39, 0, 5, 125, 3, 62, 0, 0, 1, 1, 0x081ED05E, 0x0000
	object_event 7, 31, 0, 7, 74, 3, 18, 0, 0, 1, 3, 0x081ED0D1, 0x0000
	object_event 8, 39, 0, 28, 116, 3, 60, 0, 0, 1, 1, 0x081ED047, 0x0000
	object_event 9, 32, 0, 35, 83, 4, 8, 0, 0, 1, 2, 0x081ED133, 0x0000
	object_event 10, 36, 0, 34, 122, 3, 61, 0, 0, 1, 1, 0x081ED08C, 0x0000
	object_event 11, 36, 0, 17, 128, 3, 61, 0, 0, 1, 1, 0x081ED0BA, 0x0000
	object_event 12, 5, 0, 28, 14, 3, 57, 0, 0, 1, 1, 0x081ED1C3, 0x0000
	object_event 13, 5, 0, 19, 49, 3, 58, 0, 0, 1, 3, 0x081ED1DA, 0x0000
	object_event 14, 66, 0, 10, 50, 4, 10, 0, 0, 1, 3, 0x081ED195, 0x0000
	object_event 15, 66, 0, 8, 63, 3, 8, 0, 0, 1, 5, 0x081ED1AC, 0x0000
	object_event 16, 240, 0, 25, 32, 3, 7, 0, 0, 0, 0, 0x00000000, 0x0353
	object_event 17, 59, 0, 12, 121, 3, 1, 0, 0, 0, 0, 0x08256C37, 0x0400
	object_event 18, 59, 0, 4, 96, 3, 1, 0, 0, 0, 0, 0x08256C44, 0x0401
	object_event 19, 59, 0, 29, 53, 3, 1, 0, 0, 0, 0, 0x08256C51, 0x0402
	object_event 20, 59, 0, 25, 76, 3, 1, 0, 0, 0, 0, 0x08256C5E, 0x0403
	object_event 21, 59, 0, 8, 18, 3, 1, 0, 0, 0, 0, 0x08256C6B, 0x0404
	object_event 22, 59, 0, 33, 117, 3, 1, 0, 0, 0, 0, 0x08256C78, 0x0405
	object_event 23, 117, 0, 13, 33, 4, 10, 0, 0, 0, 0, Route119_EventScript_001ED264, 0x037A
	object_event 24, 117, 0, 13, 34, 4, 10, 0, 0, 0, 0, Route119_EventScript_001ED27B, 0x037A
	object_event 25, 243, 0, 17, 33, 4, 7, 0, 0, 0, 0, 0x00000000, 0x039B
	object_event 26, 13, 0, 31, 109, 3, 8, 1, 1, 0, 0, Route119_EventScript_001ED292, 0x0000
	object_event 27, 60, 0, 8, 23, 3, 12, 0, 0, 0, 83, 0x08244D23, 0x0000
	object_event 28, 60, 0, 9, 23, 3, 12, 0, 0, 0, 84, 0x08244D23, 0x0000
	object_event 29, 60, 0, 29, 90, 3, 12, 0, 0, 0, 85, 0x08244D23, 0x0000
	object_event 30, 60, 0, 30, 90, 3, 12, 0, 0, 0, 86, 0x08244D23, 0x0000
	object_event 31, 56, 0, 19, 133, 3, 5, 2, 1, 0, 0, Route119_EventScript_001ED02C, 0x0000
	object_event 32, 59, 0, 3, 56, 3, 1, 1, 1, 0, 0, 0x08256C85, 0x0452
	object_event 33, 9, 0, 35, 93, 4, 2, 1, 1, 0, 0, Route119_EventScript_001ED29B, 0x0000
	object_event 34, 5, 0, 29, 6, 3, 57, 1, 1, 1, 3, 0x081ED1F1, 0x0000
	object_event 35, 204, 0, 31, 6, 3, 76, 1, 1, 0, 0, 0x0824339F, 0x03DD
	object_event 36, 204, 0, 25, 15, 3, 76, 1, 1, 0, 0, 0x082433AC, 0x03DE
	object_event 37, 50, 0, 13, 104, 3, 10, 1, 1, 1, 0, 0x081ED208, 0x0000
	object_event 38, 20, 0, 8, 68, 3, 7, 1, 1, 1, 5, 0x081ED24D, 0x0000
	object_event 39, 66, 0, 16, 52, 3, 10, 1, 1, 1, 3, 0x081ED236, 0x0000
	object_event 40, 66, 0, 32, 15, 3, 9, 1, 1, 1, 4, 0x081ED21F, 0x0000
	object_event 41, 59, 0, 19, 5, 4, 1, 1, 1, 0, 0, 0x082570F0, 0x046E
	object_event 42, 59, 0, 24, 42, 3, 1, 1, 1, 0, 0, 0x08256C92, 0x047B
	object_event 43, 219, 0, 28, 25, 3, 8, 0, 0, 0, 0, 0x00000000, 0x0312
	.globl ROUTE119_EventWarps
ROUTE119_EventWarps: @ 0x08503880
	warp_def 6, 32, 0, 0, MAP_ROUTE119_WEATHER_INSTITUTE_1F
	warp_def 33, 109, 0, 0, MAP_ROUTE119_HOUSE
	.globl ROUTE119_EventCoordEvents
ROUTE119_EventCoordEvents: @ 0x08503890
	coord_event 25, 31, 0, 16498, 0, Route119_EventScript_001ECD33
	coord_event 26, 31, 0, 16498, 0, Route119_EventScript_001ECD3E
	coord_event 28, 13, 0, 20, 0, 0x00000000
	coord_event 29, 13, 3, 20, 0, 0x00000000
	coord_event 30, 13, 3, 20, 0, 0x00000000
	coord_event 31, 13, 3, 20, 0, 0x00000000
	coord_event 32, 13, 3, 20, 0, 0x00000000
	coord_event 33, 13, 3, 20, 0, 0x00000000
	coord_event 15, 133, 3, 20, 0, 0x00000000
	coord_event 16, 132, 3, 20, 0, 0x00000000
	coord_event 17, 131, 3, 20, 0, 0x00000000
	coord_event 18, 130, 3, 20, 0, 0x00000000
	coord_event 19, 131, 3, 20, 0, 0x00000000
	coord_event 20, 132, 3, 20, 0, 0x00000000
	coord_event 21, 133, 3, 20, 0, 0x00000000
	coord_event 36, 6, 3, 2, 0, 0x00000000
	coord_event 36, 7, 3, 2, 0, 0x00000000
	coord_event 35, 8, 3, 2, 0, 0x00000000
	coord_event 35, 9, 3, 2, 0, 0x00000000
	coord_event 34, 10, 3, 2, 0, 0x00000000
	coord_event 16, 137, 3, 2, 0, 0x00000000
	coord_event 17, 137, 3, 2, 0, 0x00000000
	coord_event 18, 137, 3, 2, 0, 0x00000000
	coord_event 19, 137, 3, 2, 0, 0x00000000
	coord_event 20, 137, 3, 2, 0, 0x00000000
	.globl ROUTE119_EventBgEvents
ROUTE119_EventBgEvents: @ 0x08503A20
	bg_event 9, 33, 0, 0, Route119_EventScript_001ED03E, 0, 0
	bg_event 27, 19, 0, 0, Route119_EventScript_001ED035, 0, 0
	bg_event 5, 2, 0, 8, 0x00C9, 0x00, 0x00
	bg_event 4, 89, 0, 8, 0x00CA, 0x00, 0x00
	bg_event 5, 15, 0, 8, 0x00D3, 0x00, 0x00
	bg_event 7, 101, 3, 8, 0x00D4, 0x00, 0x00
	bg_event 34, 24, 3, 8, 0x00DD, 0x00, 0x00
	bg_event 31, 73, 3, 8, 0x00E7, 0x00, 0x00
	bg_event 16, 81, 0, 8, 0x0067, 0x00, 0x00
	bg_event 16, 28, 0, 8, 0x0071, 0x00, 0x00
	bg_event 17, 82, 3, 7, 0x0043, 0x05, 0x00
	bg_event 38, 63, 3, 7, 0x0002, 0x06, 0x00
	bg_event 26, 81, 0, 8, 0x0017, 0x00, 0x00
	bg_event 19, 76, 0, 8, 0x00AD, 0x00, 0x00
	bg_event 18, 76, 0, 8, 0x00C1, 0x00, 0x00
	bg_event 4, 15, 0, 8, 0x00DF, 0x00, 0x00
	bg_event 6, 2, 0, 8, 0x00E9, 0x00, 0x00
	bg_event 26, 120, 3, 7, 0x0017, 0x44, 0x00
	bg_event 20, 29, 3, 7, 0x0023, 0x57, 0x00
	bg_event 28, 9, 0, 0, Route119_EventScript_001ED2A4, 0, 0
	.globl gMapEvents_ROUTE119
gMapEvents_ROUTE119: @ 0x08503B10
	map_events ROUTE119_EventObjects, ROUTE119_EventWarps, ROUTE119_EventCoordEvents, ROUTE119_EventBgEvents
	.globl ROUTE120_EventObjects
ROUTE120_EventObjects: @ 0x08503B24
	object_event 1, 60, 0, 4, 79, 3, 12, 0, 0, 0, 46, 0x08244D23, 0x0000
	object_event 2, 60, 0, 5, 79, 3, 12, 0, 0, 0, 45, 0x08244D23, 0x0000
	object_event 3, 60, 0, 6, 79, 3, 12, 0, 0, 0, 44, 0x08244D23, 0x0000
	object_event 4, 60, 0, 7, 79, 3, 12, 0, 0, 0, 43, 0x08244D23, 0x0000
	object_event 5, 60, 0, 34, 24, 3, 12, 0, 0, 0, 37, 0x08244D23, 0x0000
	object_event 6, 60, 0, 35, 24, 3, 12, 0, 0, 0, 38, 0x08244D23, 0x0000
	object_event 7, 60, 0, 36, 24, 3, 12, 0, 0, 0, 39, 0x08244D23, 0x0000
	object_event 8, 60, 0, 9, 92, 5, 12, 0, 0, 0, 40, 0x08244D23, 0x0000
	object_event 9, 60, 0, 10, 92, 5, 12, 0, 0, 0, 41, 0x08244D23, 0x0000
	object_event 10, 60, 0, 11, 92, 5, 12, 0, 0, 0, 42, 0x08244D23, 0x0000
	object_event 11, 66, 0, 5, 22, 3, 14, 0, 0, 1, 3, 0x081EDC4F, 0x0000
	object_event 12, 66, 0, 32, 14, 3, 10, 0, 0, 1, 3, 0x081EDC66, 0x0000
	object_event 13, 31, 0, 27, 51, 3, 9, 0, 0, 1, 7, 0x081EDCC8, 0x0000
	object_event 14, 32, 0, 36, 45, 3, 9, 0, 0, 1, 2, 0x081EDCDF, 0x0000
	object_event 15, 39, 0, 19, 80, 5, 15, 0, 0, 1, 3, 0x081EDCF6, 0x0000
	object_event 16, 59, 0, 20, 55, 3, 1, 0, 0, 0, 0, 0x08256C9F, 0x0406
	object_event 17, 110, 0, 37, 5, 3, 8, 0, 0, 0, 0, 0x0825428E, 0x031E
	object_event 18, 68, 0, 36, 5, 3, 8, 0, 0, 0, 0, 0x0825426E, 0x031E
	object_event 19, 68, 0, 36, 5, 3, 8, 0, 0, 0, 0, 0x0825432E, 0x0386
	object_event 20, 110, 0, 37, 5, 3, 8, 0, 0, 0, 0, 0x0825434E, 0x0386
	object_event 21, 82, 0, 35, 32, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0011
	object_event 22, 59, 0, 7, 89, 3, 1, 0, 0, 0, 0, 0x08256CAC, 0x0407
	object_event 23, 45, 0, 14, 92, 5, 5, 1, 0, 0, 0, Route120_EventScript_001ED99F, 0x0000
	object_event 24, 34, 0, 31, 37, 3, 15, 0, 0, 1, 4, 0x081EDD58, 0x0000
	object_event 25, 55, 0, 9, 60, 3, 21, 0, 0, 1, 4, 0x081EDD6F, 0x0000
	object_event 26, 34, 0, 16, 6, 3, 23, 0, 0, 1, 4, 0x081EDD86, 0x0000
	object_event 27, 34, 0, 18, 34, 3, 9, 0, 0, 1, 3, 0x081EDD9D, 0x0000
	object_event 28, 59, 0, 22, 13, 3, 1, 1, 1, 0, 0, 0x08256CC6, 0x0454
	object_event 29, 59, 0, 23, 82, 5, 1, 1, 1, 0, 0, 0x08256CB9, 0x0453
	object_event 30, 204, 0, 12, 16, 4, 76, 1, 1, 0, 0, Route120_EventScript_001EDC34, 0x03CA
	object_event 31, 134, 0, 13, 15, 4, 8, 1, 1, 0, 0, Route120_EventScript_001EDAB9, 0x03CC
	object_event 32, 82, 0, 20, 1, 3, 1, 1, 1, 0, 0, 0x082565C8, 0x0014
	object_event 33, 82, 0, 15, 1, 3, 1, 1, 1, 0, 0, 0x082565C8, 0x0012
	object_event 34, 5, 0, 10, 72, 3, 58, 1, 1, 1, 3, 0x081EDDB4, 0x0000
	object_event 35, 5, 0, 19, 28, 3, 57, 1, 1, 1, 3, 0x081EDDCB, 0x0000
	object_event 36, 212, 0, 12, 16, 3, 8, 1, 1, 0, 0, 0x00000000, 0x03D5
	object_event 37, 204, 0, 20, 11, 3, 76, 1, 1, 0, 0, 0x0824335E, 0x03D6
	object_event 38, 204, 0, 27, 2, 3, 76, 1, 1, 0, 0, 0x0824336B, 0x03D9
	object_event 39, 204, 0, 4, 77, 3, 76, 1, 1, 0, 0, 0x08243378, 0x03DA
	object_event 40, 204, 0, 7, 51, 3, 76, 1, 1, 0, 0, 0x08243392, 0x03DC
	object_event 41, 204, 0, 19, 48, 3, 76, 1, 1, 0, 0, 0x08243385, 0x03DB
	object_event 42, 14, 0, 19, 32, 3, 7, 1, 1, 1, 3, 0x081EDDF9, 0x0000
	object_event 43, 33, 0, 14, 34, 3, 10, 1, 1, 1, 3, 0x081EDDE2, 0x0000
	object_event 44, 59, 0, 24, 33, 3, 1, 1, 1, 0, 0, 0x08256CD3, 0x047C
	.globl ROUTE120_EventWarps
ROUTE120_EventWarps: @ 0x08503F44
	warp_def 7, 55, 0, 0, MAP_ANCIENT_TOMB
	warp_def 19, 23, 1, 0, MAP_SCORCHED_SLAB
	.globl ROUTE120_EventCoordEvents
ROUTE120_EventCoordEvents: @ 0x08503F54
	coord_event 7, 15, 0, 3, 0, 0x00000000
	coord_event 7, 16, 0, 3, 0, 0x00000000
	coord_event 22, 61, 3, 3, 0, 0x00000000
	coord_event 12, 64, 3, 3, 0, 0x00000000
	coord_event 35, 63, 3, 1, 0, 0x00000000
	coord_event 36, 63, 3, 1, 0, 0x00000000
	coord_event 37, 63, 3, 1, 0, 0x00000000
	coord_event 38, 63, 3, 1, 0, 0x00000000
	coord_event 32, 88, 5, 1, 0, 0x00000000
	coord_event 28, 15, 0, 2, 0, 0x00000000
	coord_event 28, 16, 0, 2, 0, 0x00000000
	coord_event 28, 17, 3, 2, 0, 0x00000000
	coord_event 32, 89, 5, 1, 0, 0x00000000
	coord_event 32, 90, 5, 1, 0, 0x00000000
	coord_event 32, 91, 5, 1, 0, 0x00000000
	coord_event 10, 75, 3, 1, 0, 0x00000000
	coord_event 11, 75, 3, 1, 0, 0x00000000
	coord_event 12, 75, 3, 1, 0, 0x00000000
	coord_event 13, 75, 3, 1, 0, 0x00000000
	.globl ROUTE120_EventBgEvents
ROUTE120_EventBgEvents: @ 0x08504084
	bg_event 27, 3, 3, 0, Route120_EventScript_001EDC3D, 0, 0
	bg_event 38, 88, 3, 0, Route120_EventScript_001EDC46, 0, 0
	bg_event 28, 62, 0, 8, 0x0065, 0x00, 0x00
	bg_event 30, 62, 0, 8, 0x006F, 0x00, 0x00
	bg_event 26, 10, 0, 8, 0x00DE, 0x00, 0x00
	bg_event 29, 85, 5, 8, 0x00E8, 0x00, 0x00
	bg_event 18, 12, 0, 8, 0x005D, 0x00, 0x00
	bg_event 38, 54, 0, 8, 0x00CB, 0x00, 0x00
	bg_event 31, 23, 0, 8, 0x00D5, 0x00, 0x00
	bg_event 9, 1, 3, 7, 0x0044, 0x47, 0x00
	bg_event 31, 11, 3, 7, 0x0018, 0x54, 0x00
	bg_event 0, 86, 3, 7, 0x0044, 0x45, 0x00
	bg_event 24, 42, 3, 7, 0x0046, 0x46, 0x00
	bg_event 5, 76, 0, 8, 0x00CC, 0x00, 0x00
	.globl gMapEvents_ROUTE120
gMapEvents_ROUTE120: @ 0x0850412C
	map_events ROUTE120_EventObjects, ROUTE120_EventWarps, ROUTE120_EventCoordEvents, ROUTE120_EventBgEvents
	.globl ROUTE121_EventObjects
ROUTE121_EventObjects: @ 0x08504140
	object_event 1, 24, 0, 29, 14, 3, 10, 1, 1, 0, 0, 0x081EE0DA, 0x0000
	object_event 2, 60, 0, 14, 2, 3, 12, 0, 0, 0, 47, 0x08244D23, 0x0000
	object_event 3, 60, 0, 15, 2, 3, 12, 0, 0, 0, 48, 0x08244D23, 0x0000
	object_event 4, 60, 0, 16, 2, 3, 12, 0, 0, 0, 49, 0x08244D23, 0x0000
	object_event 5, 60, 0, 17, 2, 3, 12, 0, 0, 0, 50, 0x08244D23, 0x0000
	object_event 6, 60, 0, 64, 14, 3, 12, 0, 0, 0, 51, 0x08244D23, 0x0000
	object_event 7, 60, 0, 65, 14, 3, 12, 0, 0, 0, 52, 0x08244D23, 0x0000
	object_event 8, 60, 0, 66, 14, 3, 12, 0, 0, 0, 53, 0x08244D23, 0x0000
	object_event 9, 60, 0, 67, 14, 3, 12, 0, 0, 0, 54, 0x08244D23, 0x0000
	object_event 10, 47, 0, 39, 9, 3, 8, 0, 0, 1, 1, 0x081EE1E1, 0x0000
	object_event 11, 47, 0, 40, 9, 3, 8, 0, 0, 1, 1, 0x081EE1FC, 0x0000
	object_event 12, 117, 0, 30, 8, 3, 7, 0, 0, 0, 0, 0x00000000, 0x0392
	object_event 13, 117, 0, 30, 7, 3, 10, 0, 0, 0, 0, 0x00000000, 0x0392
	object_event 14, 117, 0, 31, 7, 3, 9, 0, 0, 0, 0, 0x00000000, 0x0392
	object_event 15, 82, 0, 32, 5, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0011
	object_event 16, 82, 0, 65, 4, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0012
	object_event 17, 18, 0, 63, 5, 3, 9, 0, 0, 1, 4, 0x081EE151, 0x0000
	object_event 18, 48, 0, 55, 8, 3, 9, 0, 0, 1, 3, 0x081EE168, 0x0000
	object_event 19, 40, 0, 11, 11, 3, 7, 0, 0, 1, 4, 0x081EE1CA, 0x0000
	object_event 20, 45, 0, 22, 5, 3, 17, 0, 0, 1, 4, 0x081EE217, 0x0000
	object_event 21, 59, 0, 55, 10, 3, 1, 1, 1, 0, 0, 0x08256CE0, 0x044F
	object_event 22, 82, 0, 26, 12, 3, 1, 1, 1, 0, 0, 0x082565C8, 0x0013
	object_event 23, 39, 0, 11, 6, 3, 26, 1, 4, 1, 3, 0x081EE279, 0x0000
	object_event 24, 65, 0, 59, 8, 3, 8, 1, 1, 1, 4, 0x081EE290, 0x0000
	object_event 25, 20, 0, 59, 13, 3, 7, 1, 1, 1, 4, 0x081EE2A7, 0x0000
	object_event 26, 33, 0, 65, 9, 3, 18, 1, 1, 1, 6, 0x081EE2BE, 0x0000
	object_event 27, 34, 0, 72, 9, 3, 17, 1, 1, 1, 6, 0x081EE2D5, 0x0000
	object_event 28, 59, 0, 60, 10, 3, 1, 1, 1, 0, 0, 0x08256CED, 0x047D
	object_event 29, 59, 0, 38, 13, 3, 1, 1, 1, 0, 0, 0x08256CFA, 0x047E
	.globl ROUTE121_EventWarps
ROUTE121_EventWarps: @ 0x085043F8
	warp_def 37, 5, 0, 2, MAP_ROUTE121_SAFARI_ZONE_ENTRANCE
	.globl ROUTE121_EventCoordEvents
ROUTE121_EventCoordEvents: @ 0x08504400
	coord_event 25, 5, 3, 16500, 0, 0x081EE0F5
	coord_event 25, 6, 3, 16500, 0, 0x081EE0F5
	coord_event 25, 7, 3, 16500, 0, 0x081EE0F5
	coord_event 25, 8, 3, 16500, 0, 0x081EE0F5
	.globl ROUTE121_EventBgEvents
ROUTE121_EventBgEvents: @ 0x08504440
	bg_event 32, 14, 0, 0, 0x081EE0E3, 0, 0
	bg_event 40, 11, 0, 8, 0x000C, 0x00, 0x00
	bg_event 18, 13, 0, 8, 0x0016, 0x00, 0x00
	bg_event 43, 7, 0, 8, 0x00A2, 0x00, 0x00
	bg_event 42, 7, 0, 8, 0x00AC, 0x00, 0x00
	bg_event 39, 6, 0, 0, 0x081EE0EC, 0, 0
	bg_event 23, 10, 3, 7, 0x003F, 0x27, 0x00
	bg_event 58, 3, 3, 7, 0x006E, 0x28, 0x00
	bg_event 72, 5, 3, 7, 0x0017, 0x49, 0x00
	bg_event 68, 8, 3, 7, 0x0019, 0x64, 0x00
	.globl gMapEvents_ROUTE121
gMapEvents_ROUTE121: @ 0x085044B8
	map_events ROUTE121_EventObjects, ROUTE121_EventWarps, ROUTE121_EventCoordEvents, ROUTE121_EventBgEvents
	.globl ROUTE122_EventObjects
ROUTE122_EventObjects: @ 0x00000000
	.globl ROUTE122_EventWarps
ROUTE122_EventWarps: @ 0x085044CC
	warp_def 22, 29, 0, 0, MAP_MT_PYRE_1F
	.globl gMapEvents_ROUTE122
gMapEvents_ROUTE122: @ 0x085044D4
	map_events 0, ROUTE122_EventWarps, 0, 0
	.globl ROUTE123_EventObjects
ROUTE123_EventObjects: @ 0x085044E8
	object_event 1, 60, 0, 11, 3, 3, 12, 0, 0, 0, 58, 0x08244D23, 0x0000
	object_event 2, 60, 0, 12, 3, 3, 12, 0, 0, 0, 59, 0x08244D23, 0x0000
	object_event 3, 60, 0, 14, 3, 3, 12, 0, 0, 0, 60, 0x08244D23, 0x0000
	object_event 4, 60, 0, 15, 3, 3, 12, 0, 0, 0, 61, 0x08244D23, 0x0000
	object_event 5, 60, 0, 81, 1, 3, 12, 0, 0, 0, 62, 0x08244D23, 0x0000
	object_event 6, 60, 0, 82, 1, 3, 12, 0, 0, 0, 63, 0x08244D23, 0x0000
	object_event 7, 60, 0, 83, 1, 3, 12, 0, 0, 0, 64, 0x08244D23, 0x0000
	object_event 8, 34, 0, 70, 12, 3, 24, 0, 0, 1, 1, 0x081EE454, 0x0000
	object_event 9, 33, 0, 58, 7, 3, 17, 0, 0, 1, 2, 0x081EE46B, 0x0000
	object_event 10, 60, 0, 14, 5, 3, 12, 0, 0, 0, 65, 0x08244D23, 0x0000
	object_event 11, 60, 0, 15, 5, 3, 12, 0, 0, 0, 72, 0x08244D23, 0x0000
	object_event 12, 60, 0, 17, 5, 3, 12, 0, 0, 0, 73, 0x08244D23, 0x0000
	object_event 13, 60, 0, 18, 5, 3, 12, 0, 0, 0, 74, 0x08244D23, 0x0000
	object_event 14, 60, 0, 17, 3, 3, 12, 0, 0, 0, 79, 0x08244D23, 0x0000
	object_event 15, 60, 0, 18, 3, 3, 12, 0, 0, 0, 14, 0x08244D23, 0x0000
	object_event 16, 60, 0, 11, 5, 3, 12, 0, 0, 0, 15, 0x08244D23, 0x0000
	object_event 17, 60, 0, 12, 5, 3, 12, 0, 0, 0, 30, 0x08244D23, 0x0000
	object_event 18, 82, 0, 101, 13, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0011
	object_event 19, 82, 0, 129, 14, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0012
	object_event 20, 82, 0, 92, 9, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0013
	object_event 21, 59, 0, 31, 8, 3, 1, 0, 0, 0, 0, 0x08256D07, 0x0408
	object_event 22, 14, 0, 108, 13, 3, 15, 0, 0, 0, 0, Route123_EventScript_001EE3E0, 0x0000
	object_event 23, 60, 0, 109, 13, 3, 12, 0, 0, 0, 87, 0x08244D23, 0x0000
	object_event 24, 60, 0, 110, 13, 3, 12, 0, 0, 0, 88, 0x08244D23, 0x0000
	object_event 25, 60, 0, 111, 13, 3, 12, 0, 0, 0, 89, 0x08244D23, 0x0000
	object_event 26, 20, 0, 18, 9, 3, 23, 0, 0, 1, 2, 0x081EE482, 0x0000
	object_event 27, 6, 0, 38, 13, 3, 8, 0, 0, 1, 1, 0x081EE578, 0x0000
	object_event 28, 6, 0, 37, 13, 3, 8, 0, 0, 1, 1, 0x081EE55D, 0x0000
	object_event 29, 37, 0, 138, 12, 3, 9, 0, 0, 1, 7, 0x081EE499, 0x0000
	object_event 30, 47, 0, 49, 16, 3, 8, 0, 0, 1, 1, 0x081EE4FB, 0x0000
	object_event 31, 40, 0, 87, 12, 3, 8, 0, 0, 1, 4, 0x081EE593, 0x0000
	object_event 32, 59, 0, 27, 18, 3, 1, 1, 1, 0, 0, 0x08256D14, 0x0450
	object_event 33, 59, 0, 75, 9, 3, 1, 1, 1, 0, 0, 0x08256D21, 0x0455
	object_event 34, 5, 0, 138, 14, 3, 57, 1, 1, 1, 1, 0x081EE606, 0x0000
	object_event 35, 20, 0, 138, 16, 3, 7, 1, 1, 1, 1, 0x081EE5EF, 0x0000
	object_event 36, 39, 0, 87, 17, 3, 7, 1, 1, 1, 4, 0x081EE5D8, 0x0000
	object_event 37, 66, 0, 66, 16, 3, 8, 1, 1, 1, 2, 0x081EE64B, 0x0000
	object_event 38, 66, 0, 66, 19, 3, 7, 1, 1, 1, 2, 0x081EE5C1, 0x0000
	object_event 39, 21, 0, 49, 19, 3, 7, 1, 1, 1, 2, 0x081EE5AA, 0x0000
	object_event 40, 59, 0, 43, 15, 3, 1, 1, 1, 0, 0, 0x08256D2E, 0x0480
	object_event 41, 34, 0, 14, 16, 3, 7, 1, 1, 1, 3, 0x081EE61D, 0x0000
	object_event 42, 35, 0, 14, 12, 3, 26, 1, 3, 1, 3, 0x081EE634, 0x0000
	object_event 43, 59, 0, 57, 16, 3, 1, 1, 1, 0, 0, 0x08256D3B, 0x0481
	.globl ROUTE123_EventWarps
ROUTE123_EventWarps: @ 0x085048F0
	warp_def 22, 6, 0, 0, MAP_ROUTE123_BERRY_MASTERS_HOUSE
	.globl ROUTE123_EventCoordEvents
ROUTE123_EventCoordEvents: @ 0x085048F8
	coord_event 90, 16, 3, 21, 0, 0x00000000
	coord_event 92, 9, 3, 21, 0, 0x00000000
	coord_event 93, 12, 3, 21, 0, 0x00000000
	coord_event 92, 13, 3, 21, 0, 0x00000000
	coord_event 91, 14, 3, 21, 0, 0x00000000
	coord_event 19, 13, 3, 21, 0, 0x00000000
	coord_event 19, 12, 3, 21, 0, 0x00000000
	coord_event 34, 13, 3, 21, 0, 0x00000000
	coord_event 19, 14, 3, 21, 0, 0x00000000
	coord_event 19, 15, 3, 21, 0, 0x00000000
	coord_event 19, 16, 3, 21, 0, 0x00000000
	coord_event 108, 14, 3, 2, 0, 0x00000000
	coord_event 109, 15, 3, 2, 0, 0x00000000
	coord_event 110, 16, 3, 2, 0, 0x00000000
	coord_event 111, 17, 3, 2, 0, 0x00000000
	coord_event 112, 18, 3, 2, 0, 0x00000000
	coord_event 9, 12, 3, 2, 0, 0x00000000
	coord_event 9, 13, 3, 2, 0, 0x00000000
	coord_event 9, 14, 3, 2, 0, 0x00000000
	coord_event 9, 15, 3, 2, 0, 0x00000000
	coord_event 9, 16, 3, 2, 0, 0x00000000
	coord_event 94, 10, 3, 21, 0, 0x00000000
	.globl ROUTE123_EventBgEvents
ROUTE123_EventBgEvents: @ 0x08504A58
	bg_event 117, 10, 0, 0, Route123_EventScript_001EE442, 0, 0
	bg_event 47, 3, 0, 8, 0x0052, 0x00, 0x00
	bg_event 49, 3, 0, 8, 0x005C, 0x00, 0x00
	bg_event 10, 12, 3, 0, Route123_EventScript_001EE439, 0, 0
	bg_event 75, 1, 3, 7, 0x0053, 0x07, 0x00
	bg_event 20, 7, 3, 0, Route123_EventScript_001EE44B, 0, 0
	bg_event 57, 5, 0, 8, 0x0053, 0x00, 0x00
	bg_event 12, 1, 3, 7, 0x0018, 0x29, 0x00
	bg_event 91, 15, 3, 7, 0x0015, 0x4A, 0x00
	bg_event 139, 15, 3, 7, 0x0045, 0x63, 0x00
	bg_event 138, 18, 3, 7, 0x0044, 0x6E, 0x00
	.globl gMapEvents_ROUTE123
gMapEvents_ROUTE123: @ 0x08504ADC
	map_events ROUTE123_EventObjects, ROUTE123_EventWarps, ROUTE123_EventCoordEvents, ROUTE123_EventBgEvents
	.globl ROUTE124_EventObjects
ROUTE124_EventObjects: @ 0x08504AF0
	object_event 1, 42, 0, 34, 25, 1, 1, 5, 0, 1, 3, 0x081EE7B8, 0x0000
	object_event 2, 42, 0, 61, 74, 1, 67, 5, 3, 1, 7, 0x081EE7CF, 0x0000
	object_event 3, 43, 0, 49, 45, 1, 24, 0, 0, 1, 3, 0x081EE7E6, 0x0000
	object_event 4, 43, 0, 7, 23, 1, 18, 6, 8, 1, 5, 0x081EE848, 0x0000
	object_event 5, 42, 0, 58, 58, 1, 28, 7, 0, 1, 2, 0x081EE85F, 0x0000
	object_event 6, 59, 0, 28, 12, 3, 1, 1, 1, 0, 0, 0x08256D48, 0x0444
	object_event 7, 59, 0, 31, 53, 3, 1, 1, 1, 0, 0, 0x08256D55, 0x0445
	object_event 8, 59, 0, 58, 11, 3, 1, 1, 1, 0, 0, 0x08256D62, 0x042A
	object_event 9, 43, 0, 18, 44, 1, 8, 1, 1, 1, 1, 0x081EE876, 0x0000
	object_event 10, 213, 0, 17, 44, 1, 8, 1, 1, 1, 1, 0x081EE8DA, 0x0000
	object_event 11, 42, 0, 7, 29, 1, 7, 1, 1, 1, 5, 0x081EE93E, 0x0000
	object_event 12, 43, 0, 69, 74, 1, 66, 1, 1, 1, 7, 0x081EE955, 0x0000
	.globl ROUTE124_EventWarps
ROUTE124_EventWarps: @ 0x08504C10
	warp_def 70, 48, 3, 0, MAP_ROUTE124_DIVING_TREASURE_HUNTERS_HOUSE
	.globl ROUTE124_EventBgEvents
ROUTE124_EventBgEvents: @ 0x08504C18
	bg_event 73, 48, 3, 0, Route124_EventScript_001EE7AF, 0, 0
	.globl gMapEvents_ROUTE124
gMapEvents_ROUTE124: @ 0x08504C24
	map_events ROUTE124_EventObjects, ROUTE124_EventWarps, 0, ROUTE124_EventBgEvents
	.globl ROUTE125_EventObjects
ROUTE125_EventObjects: @ 0x08504C38
	object_event 1, 42, 0, 7, 31, 1, 28, 0, 0, 1, 2, 0x081EE9D8, 0x0000
	object_event 2, 42, 0, 45, 9, 1, 10, 2, 5, 1, 2, 0x081EE9EF, 0x0000
	object_event 3, 43, 0, 38, 24, 1, 28, 6, 0, 1, 3, 0x081EEA06, 0x0000
	object_event 4, 43, 0, 30, 28, 1, 52, 9, 9, 1, 3, 0x081EEA1D, 0x0000
	object_event 5, 49, 0, 21, 30, 3, 13, 0, 0, 1, 2, 0x081EEA34, 0x0000
	object_event 6, 47, 0, 17, 19, 3, 8, 1, 1, 1, 1, 0x081EEA96, 0x0000
	object_event 7, 47, 0, 18, 19, 3, 8, 1, 1, 1, 1, 0x081EEAB1, 0x0000
	object_event 8, 66, 0, 43, 19, 3, 28, 2, 1, 1, 3, 0x081EEACC, 0x0000
	object_event 9, 21, 0, 48, 19, 3, 27, 2, 1, 1, 3, 0x081EEAE3, 0x0000
	object_event 10, 59, 0, 46, 17, 3, 1, 1, 1, 0, 0, 0x08256D6F, 0x0482
	.globl ROUTE125_EventWarps
ROUTE125_EventWarps: @ 0x08504D28
	warp_def 22, 19, 0, 0, MAP_SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM
	.globl ROUTE125_EventBgEvents
ROUTE125_EventBgEvents: @ 0x08504D30
	bg_event 53, 10, 0, 8, 0x0002, 0x00, 0x00
	bg_event 55, 11, 0, 8, 0x0020, 0x00, 0x00
	bg_event 7, 25, 0, 8, 0x0084, 0x00, 0x00
	bg_event 24, 32, 0, 8, 0x0098, 0x00, 0x00
	.globl gMapEvents_ROUTE125
gMapEvents_ROUTE125: @ 0x08504D60
	map_events ROUTE125_EventObjects, ROUTE125_EventWarps, 0, ROUTE125_EventBgEvents
	.globl ROUTE126_EventObjects
ROUTE126_EventObjects: @ 0x08504D74
	object_event 1, 42, 0, 51, 65, 1, 51, 10, 3, 1, 3, 0x081EEB0A, 0x0000
	object_event 2, 42, 0, 56, 22, 1, 28, 9, 0, 1, 3, 0x081EEB21, 0x0000
	object_event 3, 43, 0, 63, 43, 1, 24, 0, 0, 1, 3, 0x081EEB38, 0x0000
	object_event 4, 43, 0, 9, 48, 1, 7, 0, 0, 1, 3, 0x081EEB4F, 0x0000
	object_event 5, 59, 0, 14, 1, 3, 1, 1, 1, 0, 0, 0x08256D7C, 0x0451
	object_event 6, 43, 0, 15, 66, 1, 66, 1, 1, 1, 7, 0x081EEB94, 0x0000
	object_event 7, 42, 0, 7, 66, 1, 67, 1, 1, 1, 7, 0x081EEBAB, 0x0000
	object_event 8, 43, 0, 64, 5, 1, 66, 1, 1, 1, 7, 0x081EEB7D, 0x0000
	object_event 9, 42, 0, 56, 5, 1, 67, 1, 1, 1, 7, 0x081EEB66, 0x0000
	.globl gMapEvents_ROUTE126
gMapEvents_ROUTE126: @ 0x08504E4C
	map_events ROUTE126_EventObjects, 0, 0, 0
	.globl ROUTE127_EventObjects
ROUTE127_EventObjects: @ 0x08504E60
	object_event 1, 42, 0, 45, 42, 1, 14, 0, 0, 1, 2, 0x081EEC69, 0x0000
	object_event 2, 43, 0, 18, 68, 1, 21, 0, 0, 1, 4, 0x081EEC80, 0x0000
	object_event 3, 59, 0, 14, 6, 3, 1, 0, 0, 0, 0, 0x08256D89, 0x040A
	object_event 4, 59, 0, 64, 39, 3, 1, 0, 0, 0, 0, 0x08256D96, 0x040B
	object_event 5, 50, 0, 42, 21, 3, 9, 1, 1, 1, 0, 0x081EEC97, 0x0000
	object_event 6, 50, 0, 64, 19, 3, 10, 1, 1, 1, 0, 0x081EECC5, 0x0000
	object_event 7, 50, 0, 54, 14, 3, 7, 1, 1, 1, 0, 0x081EECAE, 0x0000
	object_event 8, 66, 0, 15, 23, 3, 9, 1, 1, 1, 2, 0x081EECDC, 0x0000
	object_event 9, 44, 0, 63, 63, 3, 1, 1, 1, 1, 3, 0x081EED0A, 0x0000
	object_event 10, 34, 0, 12, 23, 3, 10, 1, 1, 1, 2, 0x081EECF3, 0x0000
	object_event 11, 59, 0, 13, 20, 3, 1, 0, 0, 0, 0, 0x08256DA3, 0x0483
	.globl ROUTE127_EventBgEvents
ROUTE127_EventBgEvents: @ 0x08504F68
	bg_event 59, 67, 0, 8, 0x001F, 0x00, 0x00
	bg_event 59, 72, 0, 8, 0x008E, 0x00, 0x00
	bg_event 67, 63, 0, 8, 0x0097, 0x00, 0x00
	bg_event 61, 21, 0, 8, 0x008F, 0x00, 0x00
	bg_event 45, 24, 0, 8, 0x007B, 0x00, 0x00
	.globl gMapEvents_ROUTE127
gMapEvents_ROUTE127: @ 0x08504FA4
	map_events ROUTE127_EventObjects, 0, 0, ROUTE127_EventBgEvents
	.globl ROUTE128_EventObjects
ROUTE128_EventObjects: @ 0x08504FB8
	object_event 1, 42, 0, 35, 33, 1, 48, 5, 5, 1, 3, 0x081EEEF2, 0x0000
	object_event 2, 43, 0, 78, 24, 1, 28, 5, 0, 1, 7, 0x081EEF54, 0x0000
	object_event 3, 134, 0, 40, 22, 3, 8, 0, 0, 0, 0, 0x00000000, 0x0342
	object_event 4, 195, 0, 37, 22, 3, 9, 1, 1, 0, 0, 0x00000000, 0x03B0
	object_event 5, 196, 0, 38, 21, 3, 7, 1, 1, 0, 0, 0x00000000, 0x03B1
	object_event 6, 50, 0, 63, 28, 3, 7, 1, 1, 1, 0, 0x081EEFE4, 0x0000
	object_event 7, 33, 0, 47, 9, 3, 10, 1, 1, 1, 3, 0x081EEFCD, 0x0000
	object_event 8, 34, 0, 24, 8, 3, 17, 1, 1, 1, 3, 0x081EEFB6, 0x0000
	object_event 9, 43, 0, 101, 29, 1, 25, 1, 3, 1, 4, 0x081EF012, 0x0000
	object_event 10, 42, 0, 101, 22, 1, 26, 1, 3, 1, 4, 0x081EEFFB, 0x0000
	.globl ROUTE128_EventBgEvents
ROUTE128_EventBgEvents: @ 0x085050A8
	bg_event 49, 9, 3, 7, 0x006F, 0x5C, 0x00
	bg_event 57, 21, 3, 7, 0x006F, 0x5D, 0x00
	bg_event 31, 33, 3, 7, 0x006F, 0x5E, 0x00
	.globl gMapEvents_ROUTE128
gMapEvents_ROUTE128: @ 0x085050CC
	map_events ROUTE128_EventObjects, 0, 0, ROUTE128_EventBgEvents
	.globl ROUTE129_EventObjects
ROUTE129_EventObjects: @ 0x085050E0
	object_event 1, 42, 0, 28, 16, 1, 50, 3, 4, 1, 3, 0x081EF31C, 0x0000
	object_event 2, 43, 0, 10, 14, 1, 52, 5, 2, 1, 2, 0x081EF333, 0x0000
	object_event 3, 43, 0, 13, 22, 1, 64, 1, 1, 1, 5, 0x081EF361, 0x0000
	object_event 4, 42, 0, 35, 9, 1, 24, 1, 1, 1, 2, 0x081EF34A, 0x0000
	object_event 5, 42, 0, 13, 27, 1, 65, 1, 1, 1, 5, 0x081EF378, 0x0000
	.globl gMapEvents_ROUTE129
gMapEvents_ROUTE129: @ 0x08505158
	map_events ROUTE129_EventObjects, 0, 0, 0
	.globl ROUTE130_EventObjects
ROUTE130_EventObjects: @ 0x0850516C
	object_event 1, 42, 0, 70, 21, 1, 51, 3, 6, 1, 3, 0x081EF3EF, 0x0000
	object_event 2, 43, 0, 7, 21, 1, 26, 1, 4, 1, 5, 0x081EF406, 0x0000
	object_event 3, 60, 0, 52, 9, 3, 12, 0, 0, 0, 82, 0x08244D23, 0x0011
	object_event 4, 42, 0, 7, 30, 1, 25, 1, 4, 1, 5, 0x081EF41D, 0x0000
	.globl gMapEvents_ROUTE130
gMapEvents_ROUTE130: @ 0x085051CC
	map_events ROUTE130_EventObjects, 0, 0, 0
	.globl ROUTE131_EventObjects
ROUTE131_EventObjects: @ 0x085051E0
	object_event 1, 42, 0, 41, 32, 1, 29, 5, 7, 1, 3, 0x081EF459, 0x0000
	object_event 2, 42, 0, 18, 19, 1, 22, 0, 7, 1, 4, 0x081EF470, 0x0000
	object_event 3, 43, 0, 10, 22, 1, 20, 6, 0, 1, 4, 0x081EF487, 0x0000
	object_event 4, 43, 0, 31, 25, 1, 47, 3, 5, 1, 3, 0x081EF49E, 0x0000
	object_event 5, 43, 0, 9, 16, 1, 8, 1, 1, 1, 1, 0x081EF4B5, 0x0000
	object_event 6, 213, 0, 8, 16, 1, 8, 1, 1, 1, 1, 0x081EF4D0, 0x0000
	object_event 7, 42, 0, 52, 20, 1, 26, 1, 3, 1, 5, 0x081EF502, 0x0000
	object_event 8, 43, 0, 52, 27, 1, 25, 1, 3, 1, 5, 0x081EF4EB, 0x0000
	.globl ROUTE131_EventWarps
ROUTE131_EventWarps: @ 0x085052A0
	warp_def 36, 6, 3, 0, MAP_SKY_PILLAR_ENTRANCE
	.globl gMapEvents_ROUTE131
gMapEvents_ROUTE131: @ 0x085052A8
	map_events ROUTE131_EventObjects, ROUTE131_EventWarps, 0, 0
	.globl ROUTE132_EventObjects
ROUTE132_EventObjects: @ 0x085052BC
	object_event 1, 42, 0, 40, 13, 1, 46, 3, 3, 1, 2, 0x081EF51A, 0x0000
	object_event 2, 43, 0, 10, 6, 1, 45, 3, 3, 1, 2, 0x081EF531, 0x0000
	object_event 3, 59, 0, 10, 11, 3, 1, 0, 0, 0, 0, 0x08256DB0, 0x040C
	object_event 4, 44, 0, 9, 15, 3, 8, 0, 0, 1, 4, 0x081EF55F, 0x0000
	object_event 5, 50, 0, 49, 28, 3, 10, 0, 0, 1, 1, 0x081EF548, 0x0000
	object_event 6, 21, 0, 33, 26, 3, 8, 1, 1, 1, 4, 0x081EF576, 0x0000
	object_event 7, 34, 0, 33, 31, 3, 25, 1, 4, 1, 4, 0x081EF58D, 0x0000
	object_event 8, 22, 0, 21, 30, 3, 7, 1, 1, 1, 4, 0x081EF5BB, 0x0000
	object_event 9, 33, 0, 21, 25, 3, 26, 1, 4, 1, 4, 0x081EF5A4, 0x0000
	object_event 10, 59, 0, 20, 27, 3, 1, 1, 1, 0, 0, 0x08256DBD, 0x0484
	.globl gMapEvents_ROUTE132
gMapEvents_ROUTE132: @ 0x085053AC
	map_events ROUTE132_EventObjects, 0, 0, 0
	.globl ROUTE133_EventObjects
ROUTE133_EventObjects: @ 0x085053C0
	object_event 1, 42, 0, 68, 27, 1, 25, 0, 2, 1, 3, 0x081EF5D3, 0x0000
	object_event 2, 43, 0, 13, 3, 1, 8, 0, 0, 1, 3, 0x081EF601, 0x0000
	object_event 3, 43, 0, 68, 28, 1, 26, 0, 2, 1, 3, 0x081EF5EA, 0x0000
	object_event 4, 59, 0, 53, 12, 3, 1, 0, 0, 0, 0, 0x08256DCA, 0x040D
	object_event 5, 59, 0, 8, 10, 3, 1, 0, 0, 0, 0, 0x08256DD7, 0x040E
	object_event 6, 66, 0, 7, 14, 3, 18, 1, 1, 1, 2, 0x081EF62F, 0x0000
	object_event 7, 33, 0, 37, 15, 3, 18, 0, 0, 1, 4, 0x081EF618, 0x0000
	object_event 8, 22, 0, 56, 11, 3, 8, 1, 1, 1, 3, 0x081EF646, 0x0000
	object_event 9, 21, 0, 56, 15, 3, 16, 1, 1, 1, 3, 0x081EF65D, 0x0000
	object_event 10, 59, 0, 48, 28, 3, 1, 1, 1, 0, 0, 0x08256DE4, 0x0485
	.globl gMapEvents_ROUTE133
gMapEvents_ROUTE133: @ 0x085054B0
	map_events ROUTE133_EventObjects, 0, 0, 0
	.globl ROUTE134_EventObjects
ROUTE134_EventObjects: @ 0x085054C4
	object_event 1, 42, 0, 49, 9, 1, 49, 3, 5, 1, 2, 0x081EF683, 0x0000
	object_event 2, 43, 0, 58, 7, 1, 1, 0, 0, 1, 3, 0x081EF69A, 0x0000
	object_event 3, 33, 0, 41, 23, 3, 10, 0, 0, 1, 2, 0x081EF6C8, 0x0000
	object_event 4, 66, 0, 24, 23, 3, 26, 0, 3, 1, 6, 0x081EF6B1, 0x0000
	object_event 5, 44, 0, 49, 16, 3, 27, 6, 0, 1, 5, 0x081EF6DF, 0x0000
	object_event 6, 34, 0, 43, 23, 1, 9, 1, 1, 1, 2, 0x081EF724, 0x0000
	object_event 7, 49, 0, 24, 30, 3, 25, 0, 3, 1, 6, 0x081EF73B, 0x0000
	object_event 8, 14, 0, 50, 16, 3, 28, 6, 0, 1, 5, 0x081EF70D, 0x0000
	object_event 9, 49, 0, 63, 14, 3, 18, 1, 1, 1, 3, 0x081EF6F6, 0x0000
	object_event 10, 59, 0, 50, 17, 3, 1, 1, 1, 0, 0, 0x08256DF1, 0x0486
	object_event 11, 59, 0, 22, 27, 3, 1, 1, 1, 0, 0, 0x08256DFE, 0x0487
	.globl gMapEvents_ROUTE134
gMapEvents_ROUTE134: @ 0x085055CC
	map_events ROUTE134_EventObjects, 0, 0, 0
	.globl UNDERWATER_ROUTE124_EventObjects
UNDERWATER_ROUTE124_EventObjects: @ 0x00000000
	.globl UNDERWATER_ROUTE124_EventBgEvents
UNDERWATER_ROUTE124_EventBgEvents: @ 0x085055E0
	bg_event 42, 51, 0, 7, 0x0042, 0x08, 0x00
	bg_event 14, 40, 0, 7, 0x0033, 0x09, 0x00
	bg_event 66, 34, 3, 7, 0x006A, 0x0A, 0x00
	bg_event 64, 54, 3, 7, 0x006B, 0x0B, 0x00
	bg_event 70, 64, 3, 7, 0x006F, 0x0D, 0x00
	bg_event 42, 5, 3, 7, 0x0043, 0x24, 0x00
	bg_event 45, 36, 3, 7, 0x006F, 0x26, 0x00
	.globl gMapEvents_UNDERWATER_ROUTE124
gMapEvents_UNDERWATER_ROUTE124: @ 0x08505634
	map_events 0, 0, 0, UNDERWATER_ROUTE124_EventBgEvents
	.globl UNDERWATER_ROUTE126_EventObjects
UNDERWATER_ROUTE126_EventObjects: @ 0x00000000
	.globl UNDERWATER_ROUTE126_EventWarps
UNDERWATER_ROUTE126_EventWarps: @ 0x08505648
	warp_def 45, 65, 0, 0, MAP_UNDERWATER_SOOTOPOLIS_CITY
	.globl UNDERWATER_ROUTE126_EventBgEvents
UNDERWATER_ROUTE126_EventBgEvents: @ 0x08505650
	bg_event 30, 17, 3, 7, 0x006F, 0x0E, 0x00
	bg_event 41, 19, 3, 7, 0x0002, 0x0F, 0x00
	bg_event 63, 19, 3, 7, 0x006C, 0x10, 0x00
	bg_event 10, 36, 3, 7, 0x006A, 0x11, 0x00
	bg_event 11, 39, 3, 7, 0x0041, 0x13, 0x00
	bg_event 12, 35, 3, 7, 0x0032, 0x12, 0x00
	bg_event 65, 60, 3, 7, 0x006B, 0x14, 0x00
	bg_event 9, 77, 3, 7, 0x0031, 0x0C, 0x00
	.globl gMapEvents_UNDERWATER_ROUTE126
gMapEvents_UNDERWATER_ROUTE126: @ 0x085056B0
	map_events 0, UNDERWATER_ROUTE126_EventWarps, 0, UNDERWATER_ROUTE126_EventBgEvents
	.globl UNDERWATER_ROUTE127_EventObjects
UNDERWATER_ROUTE127_EventObjects: @ 0x00000000
	.globl UNDERWATER_ROUTE127_EventWarps
UNDERWATER_ROUTE127_EventWarps: @ 0x085056C4
	warp_def 57, 5, 0, 0, MAP_UNDERWATER_MARINE_CAVE
	warp_def 67, 38, 0, 0, MAP_UNDERWATER_MARINE_CAVE
	.globl UNDERWATER_ROUTE127_EventBgEvents
UNDERWATER_ROUTE127_EventBgEvents: @ 0x085056D4
	bg_event 12, 42, 3, 7, 0x006D, 0x15, 0x00
	bg_event 50, 36, 3, 7, 0x003F, 0x16, 0x00
	bg_event 34, 72, 3, 7, 0x006F, 0x17, 0x00
	bg_event 72, 20, 3, 7, 0x0030, 0x18, 0x00
	.globl gMapEvents_UNDERWATER_ROUTE127
gMapEvents_UNDERWATER_ROUTE127: @ 0x08505704
	map_events 0, UNDERWATER_ROUTE127_EventWarps, 0, UNDERWATER_ROUTE127_EventBgEvents
	.globl UNDERWATER_ROUTE128_EventObjects
UNDERWATER_ROUTE128_EventObjects: @ 0x00000000
	.globl UNDERWATER_ROUTE128_EventWarps
UNDERWATER_ROUTE128_EventWarps: @ 0x08505718
	warp_def 38, 26, 3, 0, MAP_UNDERWATER_SEAFLOOR_CAVERN
	.globl UNDERWATER_ROUTE128_EventBgEvents
UNDERWATER_ROUTE128_EventBgEvents: @ 0x08505720
	bg_event 38, 19, 3, 7, 0x0040, 0x19, 0x00
	bg_event 69, 18, 3, 7, 0x006A, 0x1A, 0x00
	.globl gMapEvents_UNDERWATER_ROUTE128
gMapEvents_UNDERWATER_ROUTE128: @ 0x08505738
	map_events 0, UNDERWATER_ROUTE128_EventWarps, 0, UNDERWATER_ROUTE128_EventBgEvents
	.globl UNDERWATER_ROUTE129_EventObjects
UNDERWATER_ROUTE129_EventObjects: @ 0x00000000
	.globl UNDERWATER_ROUTE129_EventWarps
UNDERWATER_ROUTE129_EventWarps: @ 0x0850574C
	warp_def 26, 3, 0, 0, MAP_UNDERWATER_MARINE_CAVE
	warp_def 32, 21, 0, 0, MAP_UNDERWATER_MARINE_CAVE
	.globl gMapEvents_UNDERWATER_ROUTE129
gMapEvents_UNDERWATER_ROUTE129: @ 0x0850575C
	map_events 0, UNDERWATER_ROUTE129_EventWarps, 0, 0
	.globl UNDERWATER_ROUTE105_EventObjects
UNDERWATER_ROUTE105_EventObjects: @ 0x00000000
	.globl UNDERWATER_ROUTE105_EventWarps
UNDERWATER_ROUTE105_EventWarps: @ 0x08505770
	warp_def 13, 4, 0, 0, MAP_UNDERWATER_MARINE_CAVE
	warp_def 17, 66, 0, 0, MAP_UNDERWATER_MARINE_CAVE
	.globl gMapEvents_UNDERWATER_ROUTE105
gMapEvents_UNDERWATER_ROUTE105: @ 0x08505780
	map_events 0, UNDERWATER_ROUTE105_EventWarps, 0, 0
	.globl UNDERWATER_ROUTE125_EventObjects
UNDERWATER_ROUTE125_EventObjects: @ 0x00000000
	.globl UNDERWATER_ROUTE125_EventWarps
UNDERWATER_ROUTE125_EventWarps: @ 0x08505794
	warp_def 22, 10, 0, 0, MAP_UNDERWATER_MARINE_CAVE
	warp_def 45, 30, 0, 0, MAP_UNDERWATER_MARINE_CAVE
	.globl gMapEvents_UNDERWATER_ROUTE125
gMapEvents_UNDERWATER_ROUTE125: @ 0x085057A4
	map_events 0, UNDERWATER_ROUTE125_EventWarps, 0, 0
	.globl LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_EventObjects
LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_EventObjects: @ 0x085057B8
	object_event 1, 215, 0, 2, 6, 3, 10, 0, 0, 0, 0, 0x082581AF, 0x02F6
	object_event 2, 95, 0, 1, 3, 3, 28, 3, 0, 0, 0, 0x082582B7, 0x02F3
	object_event 3, 96, 0, 4, 5, 3, 65, 0, 0, 0, 0, 0x082582A4, 0x02F2
	object_event 4, 26, 0, 2, 7, 3, 10, 0, 0, 0, 0, LittlerootTown_MaysHouse_1F_EventScript_001F04A6, 0x0310
	object_event 5, 129, 0, 5, 6, 3, 9, 1, 1, 0, 0, 0x00000000, 0x02DE
	object_event 6, 5, 0, 1, 5, 3, 5, 1, 1, 0, 0, LittlerootTown_MaysHouse_1F_EventScript_001F04F0, 0x02DF
	object_event 7, 100, 0, 8, 8, 3, 7, 1, 1, 0, 0, 0x00000000, 0x02E9
	.globl LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_EventWarps
LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_EventWarps: @ 0x08505860
	warp_def 9, 8, 0, 1, MAP_LITTLEROOT_TOWN
	warp_def 8, 8, 0, 1, MAP_LITTLEROOT_TOWN
	warp_def 8, 2, 0, 0, MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	.globl LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_EventCoordEvents
LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_EventCoordEvents: @ 0x08505878
	coord_event 8, 8, 0, 16530, 4, LittlerootTown_BrendansHouse_1F_EventScript_001EF8D3
	coord_event 7, 3, 0, 16525, 2, LittlerootTown_BrendansHouse_1F_EventScript_001EF8EE
	coord_event 8, 4, 0, 16525, 2, LittlerootTown_BrendansHouse_1F_EventScript_001EF8FA
	coord_event 9, 3, 0, 16525, 2, LittlerootTown_BrendansHouse_1F_EventScript_001EF906
	.globl gMapEvents_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F
gMapEvents_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F: @ 0x085058B8
	map_events LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_EventObjects, LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_EventWarps, LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_EventCoordEvents, 0
	.globl LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_EventObjects
LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_EventObjects: @ 0x085058CC
	object_event 1, 100, 0, 7, 1, 0, 8, 1, 0, 0, 0, LittlerootTown_MaysHouse_2F_EventScript_001F0D0D, 0x02F8
	object_event 2, 240, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0x00000000, 0x00AE
	object_event 3, 241, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0x00000000, 0x00AF
	object_event 4, 242, 0, 0, 2, 3, 1, 0, 0, 0, 0, 0x00000000, 0x00B0
	object_event 5, 243, 0, 0, 3, 3, 1, 0, 0, 0, 0, 0x00000000, 0x00B1
	object_event 6, 244, 0, 0, 4, 0, 1, 0, 0, 0, 0, 0x00000000, 0x00B2
	object_event 7, 245, 0, 0, 5, 4, 1, 0, 0, 0, 0, 0x00000000, 0x00B3
	object_event 8, 246, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0x00000000, 0x00B4
	object_event 9, 247, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0x00000000, 0x00B5
	object_event 10, 248, 0, 1, 2, 3, 1, 0, 0, 0, 0, 0x00000000, 0x00B6
	object_event 11, 249, 0, 1, 3, 3, 1, 0, 0, 0, 0, 0x00000000, 0x00B7
	object_event 12, 250, 0, 1, 4, 3, 1, 0, 0, 0, 0, 0x00000000, 0x00B8
	object_event 13, 251, 0, 1, 5, 0, 1, 0, 0, 0, 0, 0x00000000, 0x00B9
	object_event 14, 215, 0, 7, 1, 3, 8, 1, 0, 0, 0, 0x00000000, 0x02F5
	object_event 15, 59, 0, 3, 4, 0, 1, 1, 1, 0, 0, LittlerootTown_BrendansHouse_2F_EventScript_001F0030, 0x0331
	object_event 16, 163, 0, 5, 5, 3, 1, 1, 1, 0, 0, 0x00000000, 0x032F
	.globl LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_EventWarps
LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_EventWarps: @ 0x08505A4C
	warp_def 7, 1, 0, 2, MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F
	.globl LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_EventBgEvents
LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_EventBgEvents: @ 0x08505A54
	bg_event 0, 1, 0, 1, LittlerootTown_BrendansHouse_2F_EventScript_001F01BC, 0, 0
	bg_event 1, 1, 0, 0, LittlerootTown_BrendansHouse_2F_EventScript_001F0205, 0, 0
	bg_event 5, 1, 0, 0, 0x08257F6B, 0, 0
	bg_event 3, 1, 0, 0, LittlerootTown_BrendansHouse_2F_EventScript_001F020E, 0, 0
	.globl gMapEvents_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
gMapEvents_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F: @ 0x08505A84
	map_events LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_EventObjects, LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_EventWarps, 0, LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_EventBgEvents
	.globl LITTLEROOT_TOWN_MAYS_HOUSE_1F_EventObjects
LITTLEROOT_TOWN_MAYS_HOUSE_1F_EventObjects: @ 0x08505A98
	object_event 1, 215, 0, 8, 6, 3, 9, 0, 0, 0, 0, 0x082581AF, 0x02F7
	object_event 2, 96, 0, 6, 5, 3, 65, 0, 0, 0, 0, 0x082582A4, 0x02F2
	object_event 3, 95, 0, 9, 3, 3, 27, 3, 0, 0, 0, 0x082582B7, 0x02F3
	object_event 4, 26, 0, 8, 7, 3, 9, 0, 0, 0, 0, LittlerootTown_MaysHouse_1F_EventScript_001F04A6, 0x0311
	object_event 5, 129, 0, 5, 6, 3, 10, 1, 1, 0, 0, 0x00000000, 0x02DE
	object_event 6, 5, 0, 9, 5, 3, 5, 1, 1, 0, 0, LittlerootTown_MaysHouse_1F_EventScript_001F04F0, 0x02E0
	object_event 7, 105, 0, 2, 8, 3, 7, 1, 1, 0, 0, 0x00000000, 0x02EA
	.globl LITTLEROOT_TOWN_MAYS_HOUSE_1F_EventWarps
LITTLEROOT_TOWN_MAYS_HOUSE_1F_EventWarps: @ 0x08505B40
	warp_def 1, 8, 0, 0, MAP_LITTLEROOT_TOWN
	warp_def 2, 8, 0, 0, MAP_LITTLEROOT_TOWN
	warp_def 2, 2, 0, 0, MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	.globl LITTLEROOT_TOWN_MAYS_HOUSE_1F_EventCoordEvents
LITTLEROOT_TOWN_MAYS_HOUSE_1F_EventCoordEvents: @ 0x08505B58
	coord_event 2, 8, 0, 16530, 4, LittlerootTown_MaysHouse_1F_EventScript_001F04FF
	coord_event 1, 3, 0, 16525, 2, LittlerootTown_MaysHouse_1F_EventScript_001F051A
	coord_event 2, 4, 0, 16525, 2, LittlerootTown_MaysHouse_1F_EventScript_001F0526
	coord_event 3, 3, 0, 16525, 2, LittlerootTown_MaysHouse_1F_EventScript_001F0532
	.globl gMapEvents_LITTLEROOT_TOWN_MAYS_HOUSE_1F
gMapEvents_LITTLEROOT_TOWN_MAYS_HOUSE_1F: @ 0x08505B98
	map_events LITTLEROOT_TOWN_MAYS_HOUSE_1F_EventObjects, LITTLEROOT_TOWN_MAYS_HOUSE_1F_EventWarps, LITTLEROOT_TOWN_MAYS_HOUSE_1F_EventCoordEvents, 0
	.globl LITTLEROOT_TOWN_MAYS_HOUSE_2F_EventObjects
LITTLEROOT_TOWN_MAYS_HOUSE_2F_EventObjects: @ 0x08505BAC
	object_event 1, 105, 0, 1, 1, 0, 8, 1, 0, 0, 0, LittlerootTown_MaysHouse_2F_EventScript_001F0D0D, 0x02D2
	object_event 2, 240, 0, 0, 6, 0, 1, 0, 0, 0, 0, 0x00000000, 0x00AE
	object_event 3, 241, 0, 1, 6, 3, 1, 0, 0, 0, 0, 0x00000000, 0x00AF
	object_event 4, 242, 0, 2, 6, 0, 1, 0, 0, 0, 0, 0x00000000, 0x00B0
	object_event 5, 243, 0, 3, 6, 3, 1, 0, 0, 0, 0, 0x00000000, 0x00B1
	object_event 6, 244, 0, 4, 6, 3, 1, 0, 0, 0, 0, 0x00000000, 0x00B2
	object_event 7, 245, 0, 5, 6, 3, 1, 0, 0, 0, 0, 0x00000000, 0x00B3
	object_event 8, 246, 0, 0, 7, 3, 1, 0, 0, 0, 0, 0x00000000, 0x00B4
	object_event 9, 247, 0, 1, 7, 3, 1, 0, 0, 0, 0, 0x00000000, 0x00B5
	object_event 10, 248, 0, 2, 7, 3, 1, 0, 0, 0, 0, 0x00000000, 0x00B6
	object_event 11, 249, 0, 3, 7, 3, 1, 0, 0, 0, 0, 0x00000000, 0x00B7
	object_event 12, 250, 0, 4, 7, 3, 1, 0, 0, 0, 0, 0x00000000, 0x00B8
	object_event 13, 251, 0, 5, 7, 3, 1, 0, 0, 0, 0, 0x00000000, 0x00B9
	object_event 14, 215, 0, 1, 1, 3, 8, 1, 0, 0, 0, 0x00000000, 0x02F5
	object_event 15, 142, 0, 3, 4, 4, 8, 1, 1, 0, 0, 0x00000000, 0x0351
	object_event 16, 59, 0, 5, 4, 0, 1, 1, 1, 0, 0, LittlerootTown_MaysHouse_2F_EventScript_001F0B80, 0x0332
	.globl LITTLEROOT_TOWN_MAYS_HOUSE_2F_EventWarps
LITTLEROOT_TOWN_MAYS_HOUSE_2F_EventWarps: @ 0x08505D2C
	warp_def 1, 1, 0, 2, MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F
	.globl LITTLEROOT_TOWN_MAYS_HOUSE_2F_EventBgEvents
LITTLEROOT_TOWN_MAYS_HOUSE_2F_EventBgEvents: @ 0x08505D34
	bg_event 5, 1, 0, 0, LittlerootTown_BrendansHouse_2F_EventScript_001F020E, 0, 0
	bg_event 7, 1, 0, 0, LittlerootTown_BrendansHouse_2F_EventScript_001F0205, 0, 0
	bg_event 3, 1, 0, 0, 0x08257F77, 0, 0
	bg_event 8, 1, 0, 0, LittlerootTown_MaysHouse_2F_EventScript_001F0D9F, 0, 0
	.globl gMapEvents_LITTLEROOT_TOWN_MAYS_HOUSE_2F
gMapEvents_LITTLEROOT_TOWN_MAYS_HOUSE_2F: @ 0x08505D64
	map_events LITTLEROOT_TOWN_MAYS_HOUSE_2F_EventObjects, LITTLEROOT_TOWN_MAYS_HOUSE_2F_EventWarps, 0, LITTLEROOT_TOWN_MAYS_HOUSE_2F_EventBgEvents
	.globl LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_EventObjects
LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_EventObjects: @ 0x08505D78
	object_event 1, 46, 0, 9, 8, 3, 2, 1, 1, 0, 0, LittlerootTown_ProfessorBirchsLab_EventScript_001F151F, 0x0000
	object_event 2, 64, 0, 6, 4, 3, 8, 0, 0, 0, 0, LittlerootTown_ProfessorBirchsLab_EventScript_001F17F5, 0x02D1
	object_event 3, 240, 0, 7, 4, 3, 8, 1, 1, 0, 0, LittlerootTown_ProfessorBirchsLab_EventScript_001F1987, 0x0379
	object_event 4, 59, 0, 6, 8, 3, 8, 1, 1, 0, 0, LittlerootTown_ProfessorBirchsLab_EventScript_001F1556, 0x032B
	object_event 5, 59, 0, 6, 8, 3, 8, 1, 1, 0, 0, LittlerootTown_ProfessorBirchsLab_EventScript_001F158A, 0x032C
	object_event 6, 59, 0, 6, 8, 3, 8, 1, 1, 0, 0, LittlerootTown_ProfessorBirchsLab_EventScript_001F15BE, 0x0346
	.globl LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_EventWarps
LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_EventWarps: @ 0x08505E08
	warp_def 6, 12, 0, 2, MAP_LITTLEROOT_TOWN
	warp_def 7, 12, 0, 2, MAP_LITTLEROOT_TOWN
	.globl LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_EventBgEvents
LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_EventBgEvents: @ 0x08505E18
	bg_event 10, 7, 0, 1, LittlerootTown_ProfessorBirchsLab_EventScript_001F197E, 0, 0
	bg_event 11, 7, 0, 1, LittlerootTown_ProfessorBirchsLab_EventScript_001F197E, 0, 0
	bg_event 7, 1, 0, 0, LittlerootTown_ProfessorBirchsLab_EventScript_001F1A68, 0, 0
	bg_event 8, 1, 0, 0, LittlerootTown_ProfessorBirchsLab_EventScript_001F1A68, 0, 0
	bg_event 1, 1, 0, 0, LittlerootTown_ProfessorBirchsLab_EventScript_001F1A5F, 0, 0
	bg_event 0, 7, 0, 0, LittlerootTown_ProfessorBirchsLab_EventScript_001F1A5F, 0, 0
	bg_event 1, 7, 0, 0, LittlerootTown_ProfessorBirchsLab_EventScript_001F1A5F, 0, 0
	bg_event 2, 7, 0, 0, LittlerootTown_ProfessorBirchsLab_EventScript_001F1A5F, 0, 0
	bg_event 3, 7, 0, 0, LittlerootTown_ProfessorBirchsLab_EventScript_001F1A5F, 0, 0
	bg_event 4, 1, 0, 0, LittlerootTown_ProfessorBirchsLab_EventScript_001F1A56, 0, 0
	bg_event 3, 1, 0, 0, LittlerootTown_ProfessorBirchsLab_EventScript_001F1A56, 0, 0
	bg_event 1, 10, 0, 0, LittlerootTown_ProfessorBirchsLab_EventScript_001F1A56, 0, 0
	bg_event 1, 9, 0, 0, LittlerootTown_ProfessorBirchsLab_EventScript_001F1A56, 0, 0
	bg_event 11, 10, 0, 0, LittlerootTown_ProfessorBirchsLab_EventScript_001F1A56, 0, 0
	bg_event 11, 9, 0, 0, LittlerootTown_ProfessorBirchsLab_EventScript_001F1A56, 0, 0
	.globl gMapEvents_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB
gMapEvents_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB: @ 0x08505ECC
	map_events LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_EventObjects, LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_EventWarps, 0, LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_EventBgEvents
	.globl OLDALE_TOWN_HOUSE1_EventObjects
OLDALE_TOWN_HOUSE1_EventObjects: @ 0x08505EE0
	object_event 1, 20, 0, 6, 4, 3, 2, 1, 1, 0, 0, 0x081F28D4, 0x0000
	.globl OLDALE_TOWN_HOUSE1_EventWarps
OLDALE_TOWN_HOUSE1_EventWarps: @ 0x08505EF8
	warp_def 3, 8, 0, 0, MAP_OLDALE_TOWN
	warp_def 4, 8, 0, 0, MAP_OLDALE_TOWN
	.globl gMapEvents_OLDALE_TOWN_HOUSE1
gMapEvents_OLDALE_TOWN_HOUSE1: @ 0x08505F08
	map_events OLDALE_TOWN_HOUSE1_EventObjects, OLDALE_TOWN_HOUSE1_EventWarps, 0, 0
	.globl OLDALE_TOWN_HOUSE2_EventObjects
OLDALE_TOWN_HOUSE2_EventObjects: @ 0x08505F1C
	object_event 1, 18, 0, 4, 4, 3, 10, 0, 0, 0, 0, 0x081F294A, 0x0000
	object_event 2, 38, 0, 7, 4, 3, 9, 0, 0, 0, 0, 0x081F2953, 0x0000
	.globl OLDALE_TOWN_HOUSE2_EventWarps
OLDALE_TOWN_HOUSE2_EventWarps: @ 0x08505F4C
	warp_def 3, 7, 0, 1, MAP_OLDALE_TOWN
	warp_def 4, 7, 0, 1, MAP_OLDALE_TOWN
	.globl gMapEvents_OLDALE_TOWN_HOUSE2
gMapEvents_OLDALE_TOWN_HOUSE2: @ 0x08505F5C
	map_events OLDALE_TOWN_HOUSE2_EventObjects, OLDALE_TOWN_HOUSE2_EventWarps, 0, 0
	.globl OLDALE_TOWN_POKEMON_CENTER_1F_EventObjects
OLDALE_TOWN_POKEMON_CENTER_1F_EventObjects: @ 0x08505F70
	object_event 1, 58, 0, 7, 2, 3, 8, 0, 0, 0, 0, OldaleTown_PokemonCenter_1F_EventScript_001F29B6, 0x0000
	object_event 2, 48, 0, 4, 4, 3, 8, 0, 0, 0, 0, OldaleTown_PokemonCenter_1F_EventScript_001F29C4, 0x0000
	object_event 3, 7, 0, 10, 6, 3, 10, 0, 0, 0, 0, OldaleTown_PokemonCenter_1F_EventScript_001F29CD, 0x0000
	object_event 4, 14, 0, 3, 7, 3, 10, 1, 1, 0, 0, OldaleTown_PokemonCenter_1F_EventScript_001F29D6, 0x0000
	.globl OLDALE_TOWN_POKEMON_CENTER_1F_EventWarps
OLDALE_TOWN_POKEMON_CENTER_1F_EventWarps: @ 0x08505FD0
	warp_def 7, 8, 3, 2, MAP_OLDALE_TOWN
	warp_def 6, 8, 3, 2, MAP_OLDALE_TOWN
	warp_def 1, 6, 4, 0, MAP_OLDALE_TOWN_POKEMON_CENTER_2F
	.globl gMapEvents_OLDALE_TOWN_POKEMON_CENTER_1F
gMapEvents_OLDALE_TOWN_POKEMON_CENTER_1F: @ 0x08505FE8
	map_events OLDALE_TOWN_POKEMON_CENTER_1F_EventObjects, OLDALE_TOWN_POKEMON_CENTER_1F_EventWarps, 0, 0
	.globl OLDALE_TOWN_POKEMON_CENTER_2F_EventObjects
OLDALE_TOWN_POKEMON_CENTER_2F_EventObjects: @ 0x08505FFC
	object_event 1, 85, 0, 6, 2, 3, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 3, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 3, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	.globl OLDALE_TOWN_POKEMON_CENTER_2F_EventWarps
OLDALE_TOWN_POKEMON_CENTER_2F_EventWarps: @ 0x0850605C
	warp_def 1, 6, 4, 2, MAP_OLDALE_TOWN_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_OLDALE_TOWN_POKEMON_CENTER_2F
gMapEvents_OLDALE_TOWN_POKEMON_CENTER_2F: @ 0x08506074
	map_events OLDALE_TOWN_POKEMON_CENTER_2F_EventObjects, OLDALE_TOWN_POKEMON_CENTER_2F_EventWarps, 0, 0
	.globl OLDALE_TOWN_MART_EventObjects
OLDALE_TOWN_MART_EventObjects: @ 0x08506088
	object_event 1, 83, 0, 1, 3, 3, 10, 0, 0, 0, 0, 0x081F2B0C, 0x0000
	object_event 2, 34, 0, 5, 5, 3, 10, 0, 0, 0, 0, 0x081F2B56, 0x0000
	object_event 3, 7, 0, 9, 4, 3, 3, 0, 1, 0, 0, 0x081F2B75, 0x0000
	.globl OLDALE_TOWN_MART_EventWarps
OLDALE_TOWN_MART_EventWarps: @ 0x085060D0
	warp_def 3, 7, 0, 3, MAP_OLDALE_TOWN
	warp_def 4, 7, 0, 3, MAP_OLDALE_TOWN
	.globl gMapEvents_OLDALE_TOWN_MART
gMapEvents_OLDALE_TOWN_MART: @ 0x085060E0
	map_events OLDALE_TOWN_MART_EventObjects, OLDALE_TOWN_MART_EventWarps, 0, 0
	.globl DEWFORD_TOWN_HOUSE1_EventObjects
DEWFORD_TOWN_HOUSE1_EventObjects: @ 0x085060F4
	object_event 1, 24, 0, 6, 3, 3, 9, 0, 0, 0, 0, 0x081F2C1A, 0x0000
	object_event 2, 19, 0, 3, 3, 3, 10, 0, 0, 0, 0, 0x081F2C11, 0x0000
	object_event 3, 208, 0, 4, 2, 3, 8, 3, 1, 0, 0, 0x081F2C23, 0x0000
	.globl DEWFORD_TOWN_HOUSE1_EventWarps
DEWFORD_TOWN_HOUSE1_EventWarps: @ 0x0850613C
	warp_def 3, 7, 0, 3, MAP_DEWFORD_TOWN
	warp_def 4, 7, 0, 3, MAP_DEWFORD_TOWN
	.globl gMapEvents_DEWFORD_TOWN_HOUSE1
gMapEvents_DEWFORD_TOWN_HOUSE1: @ 0x0850614C
	map_events DEWFORD_TOWN_HOUSE1_EventObjects, DEWFORD_TOWN_HOUSE1_EventWarps, 0, 0
	.globl DEWFORD_TOWN_POKEMON_CENTER_1F_EventObjects
DEWFORD_TOWN_POKEMON_CENTER_1F_EventObjects: @ 0x08506160
	object_event 1, 58, 0, 7, 2, 3, 8, 0, 0, 0, 0, DewfordTown_PokemonCenter_1F_EventScript_001F2CE3, 0x0000
	object_event 2, 18, 0, 10, 6, 3, 10, 0, 0, 0, 0, DewfordTown_PokemonCenter_1F_EventScript_001F2CF1, 0x0000
	object_event 3, 33, 0, 5, 5, 0, 5, 2, 1, 0, 0, DewfordTown_PokemonCenter_1F_EventScript_001F2CFA, 0x0000
	.globl DEWFORD_TOWN_POKEMON_CENTER_1F_EventWarps
DEWFORD_TOWN_POKEMON_CENTER_1F_EventWarps: @ 0x085061A8
	warp_def 7, 8, 3, 1, MAP_DEWFORD_TOWN
	warp_def 6, 8, 3, 1, MAP_DEWFORD_TOWN
	warp_def 1, 6, 4, 0, MAP_DEWFORD_TOWN_POKEMON_CENTER_2F
	.globl gMapEvents_DEWFORD_TOWN_POKEMON_CENTER_1F
gMapEvents_DEWFORD_TOWN_POKEMON_CENTER_1F: @ 0x085061C0
	map_events DEWFORD_TOWN_POKEMON_CENTER_1F_EventObjects, DEWFORD_TOWN_POKEMON_CENTER_1F_EventWarps, 0, 0
	.globl DEWFORD_TOWN_POKEMON_CENTER_2F_EventObjects
DEWFORD_TOWN_POKEMON_CENTER_2F_EventObjects: @ 0x085061D4
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 3, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	.globl DEWFORD_TOWN_POKEMON_CENTER_2F_EventWarps
DEWFORD_TOWN_POKEMON_CENTER_2F_EventWarps: @ 0x08506234
	warp_def 1, 6, 4, 2, MAP_DEWFORD_TOWN_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_DEWFORD_TOWN_POKEMON_CENTER_2F
gMapEvents_DEWFORD_TOWN_POKEMON_CENTER_2F: @ 0x0850624C
	map_events DEWFORD_TOWN_POKEMON_CENTER_2F_EventObjects, DEWFORD_TOWN_POKEMON_CENTER_2F_EventWarps, 0, 0
	.globl DEWFORD_TOWN_GYM_EventObjects
DEWFORD_TOWN_GYM_EventObjects: @ 0x08506260
	object_event 1, 126, 0, 4, 3, 0, 8, 0, 0, 0, 0, 0x081F2F0D, 0x0000
	object_event 2, 44, 0, 2, 18, 0, 7, 0, 0, 1, 3, 0x081F3002, 0x0000
	object_event 3, 14, 0, 15, 3, 3, 8, 0, 0, 1, 3, 0x081F3024, 0x0000
	object_event 4, 14, 0, 12, 25, 3, 7, 0, 0, 1, 2, 0x081F3046, 0x0000
	object_event 5, 23, 0, 5, 24, 3, 8, 0, 0, 0, 0, DewfordTown_Gym_EventScript_001F30CE, 0x0000
	object_event 6, 44, 0, 7, 8, 1, 10, 1, 1, 1, 3, 0x081F308A, 0x0000
	object_event 7, 14, 0, 16, 9, 3, 8, 1, 1, 1, 3, 0x081F30AC, 0x0000
	object_event 8, 49, 0, 14, 12, 1, 10, 1, 1, 1, 2, 0x081F3068, 0x0000
	.globl DEWFORD_TOWN_GYM_EventWarps
DEWFORD_TOWN_GYM_EventWarps: @ 0x08506320
	warp_def 5, 27, 0, 2, MAP_DEWFORD_TOWN
	warp_def 6, 27, 0, 2, MAP_DEWFORD_TOWN
	.globl DEWFORD_TOWN_GYM_EventBgEvents
DEWFORD_TOWN_GYM_EventBgEvents: @ 0x08506330
	bg_event 4, 23, 3, 1, DewfordTown_Gym_EventScript_001F30ED, 0, 0
	bg_event 7, 23, 3, 1, DewfordTown_Gym_EventScript_001F30FD, 0, 0
	bg_event 4, 24, 0, 1, DewfordTown_Gym_EventScript_001F30ED, 0, 0
	bg_event 7, 24, 0, 1, DewfordTown_Gym_EventScript_001F30FD, 0, 0
	.globl gMapEvents_DEWFORD_TOWN_GYM
gMapEvents_DEWFORD_TOWN_GYM: @ 0x08506360
	map_events DEWFORD_TOWN_GYM_EventObjects, DEWFORD_TOWN_GYM_EventWarps, 0, DEWFORD_TOWN_GYM_EventBgEvents
	.globl DEWFORD_TOWN_HALL_EventObjects
DEWFORD_TOWN_HALL_EventObjects: @ 0x08506374
	object_event 1, 10, 0, 4, 6, 0, 7, 0, 0, 0, 0, 0x081F3789, 0x0000
	object_event 2, 20, 0, 1, 5, 0, 10, 0, 0, 0, 0, 0x081F37B2, 0x0000
	object_event 3, 19, 0, 5, 4, 0, 9, 0, 0, 0, 0, 0x081F37C3, 0x0000
	object_event 4, 21, 0, 9, 3, 0, 7, 0, 0, 0, 0, 0x081F3800, 0x0000
	object_event 5, 6, 0, 5, 2, 3, 7, 0, 0, 0, 0, 0x081F381C, 0x0000
	object_event 6, 11, 0, 14, 7, 0, 5, 1, 0, 0, 0, 0x081F3838, 0x0000
	object_event 7, 38, 0, 12, 3, 3, 10, 0, 0, 0, 0, 0x081F38E8, 0x0000
	object_event 8, 37, 0, 15, 3, 3, 9, 0, 0, 0, 0, 0x081F38F4, 0x0000
	object_event 9, 39, 0, 8, 6, 3, 5, 1, 0, 0, 0, 0x081F3A93, 0x03AC
	.globl DEWFORD_TOWN_HALL_EventWarps
DEWFORD_TOWN_HALL_EventWarps: @ 0x0850644C
	warp_def 5, 8, 0, 0, MAP_DEWFORD_TOWN
	warp_def 6, 8, 0, 0, MAP_DEWFORD_TOWN
	.globl DEWFORD_TOWN_HALL_EventBgEvents
DEWFORD_TOWN_HALL_EventBgEvents: @ 0x0850645C
	bg_event 0, 1, 3, 0, 0x081F3849, 0, 0
	bg_event 7, 1, 3, 0, 0x081F3859, 0, 0
	.globl gMapEvents_DEWFORD_TOWN_HALL
gMapEvents_DEWFORD_TOWN_HALL: @ 0x08506474
	map_events DEWFORD_TOWN_HALL_EventObjects, DEWFORD_TOWN_HALL_EventWarps, 0, DEWFORD_TOWN_HALL_EventBgEvents
	.globl DEWFORD_TOWN_HOUSE2_EventObjects
DEWFORD_TOWN_HOUSE2_EventObjects: @ 0x08506488
	object_event 1, 33, 0, 6, 5, 3, 10, 0, 0, 0, 0, 0x081F4009, 0x0000
	object_event 2, 9, 0, 2, 3, 3, 1, 0, 0, 0, 0, 0x081F404C, 0x0000
	.globl DEWFORD_TOWN_HOUSE2_EventWarps
DEWFORD_TOWN_HOUSE2_EventWarps: @ 0x085064B8
	warp_def 3, 8, 0, 4, MAP_DEWFORD_TOWN
	warp_def 4, 8, 0, 4, MAP_DEWFORD_TOWN
	.globl gMapEvents_DEWFORD_TOWN_HOUSE2
gMapEvents_DEWFORD_TOWN_HOUSE2: @ 0x085064C8
	map_events DEWFORD_TOWN_HOUSE2_EventObjects, DEWFORD_TOWN_HOUSE2_EventWarps, 0, 0
	.globl LAVARIDGE_TOWN_HERB_SHOP_EventObjects
LAVARIDGE_TOWN_HERB_SHOP_EventObjects: @ 0x085064DC
	object_event 1, 20, 0, 3, 2, 3, 8, 0, 0, 0, 0, 0x081F4186, 0x0000
	object_event 2, 29, 0, 7, 5, 3, 1, 1, 1, 0, 0, 0x081F41B5, 0x0000
	object_event 3, 21, 0, 9, 3, 3, 5, 1, 1, 0, 0, 0x081F41AC, 0x0000
	.globl LAVARIDGE_TOWN_HERB_SHOP_EventWarps
LAVARIDGE_TOWN_HERB_SHOP_EventWarps: @ 0x08506524
	warp_def 3, 7, 0, 0, MAP_LAVARIDGE_TOWN
	warp_def 4, 7, 0, 0, MAP_LAVARIDGE_TOWN
	.globl gMapEvents_LAVARIDGE_TOWN_HERB_SHOP
gMapEvents_LAVARIDGE_TOWN_HERB_SHOP: @ 0x08506534
	map_events LAVARIDGE_TOWN_HERB_SHOP_EventObjects, LAVARIDGE_TOWN_HERB_SHOP_EventWarps, 0, 0
	.globl LAVARIDGE_TOWN_GYM_1F_EventObjects
LAVARIDGE_TOWN_GYM_1F_EventObjects: @ 0x08506548
	object_event 1, 128, 0, 13, 9, 3, 8, 0, 0, 0, 0, 0x081F435F, 0x0000
	object_event 2, 66, 0, 3, 14, 3, 8, 0, 0, 3, 1, 0x081F4452, 0x0000
	object_event 3, 33, 0, 2, 15, 3, 8, 0, 0, 3, 1, 0x081F44D3, 0x0000
	object_event 4, 66, 0, 3, 10, 3, 8, 0, 0, 3, 1, 0x081F4482, 0x0000
	object_event 5, 14, 0, 5, 2, 3, 8, 0, 0, 3, 1, 0x081F44B8, 0x0000
	object_event 6, 23, 0, 12, 16, 3, 10, 0, 0, 0, 0, LavaridgeTown_Gym_1F_EventScript_001F453F, 0x0000
	.globl LAVARIDGE_TOWN_GYM_1F_EventWarps
LAVARIDGE_TOWN_GYM_1F_EventWarps: @ 0x085065D8
	warp_def 13, 18, 3, 1, MAP_LAVARIDGE_TOWN
	warp_def 14, 18, 3, 1, MAP_LAVARIDGE_TOWN
	warp_def 10, 18, 3, 0, MAP_LAVARIDGE_TOWN_GYM_B1F
	warp_def 8, 9, 3, 2, MAP_LAVARIDGE_TOWN_GYM_B1F
	warp_def 4, 18, 3, 4, MAP_LAVARIDGE_TOWN_GYM_B1F
	warp_def 5, 14, 3, 3, MAP_LAVARIDGE_TOWN_GYM_B1F
	warp_def 0, 17, 3, 1, MAP_LAVARIDGE_TOWN_GYM_B1F
	warp_def 5, 9, 3, 5, MAP_LAVARIDGE_TOWN_GYM_B1F
	warp_def 2, 15, 3, 6, MAP_LAVARIDGE_TOWN_GYM_B1F
	warp_def 3, 14, 3, 7, MAP_LAVARIDGE_TOWN_GYM_B1F
	warp_def 1, 14, 3, 8, MAP_LAVARIDGE_TOWN_GYM_B1F
	warp_def 0, 10, 3, 9, MAP_LAVARIDGE_TOWN_GYM_B1F
	warp_def 3, 10, 3, 10, MAP_LAVARIDGE_TOWN_GYM_B1F
	warp_def 0, 6, 3, 11, MAP_LAVARIDGE_TOWN_GYM_B1F
	warp_def 3, 6, 3, 12, MAP_LAVARIDGE_TOWN_GYM_B1F
	warp_def 5, 6, 3, 13, MAP_LAVARIDGE_TOWN_GYM_B1F
	warp_def 2, 3, 3, 14, MAP_LAVARIDGE_TOWN_GYM_B1F
	warp_def 5, 2, 3, 15, MAP_LAVARIDGE_TOWN_GYM_B1F
	warp_def 7, 2, 3, 16, MAP_LAVARIDGE_TOWN_GYM_B1F
	warp_def 8, 6, 3, 17, MAP_LAVARIDGE_TOWN_GYM_B1F
	warp_def 10, 6, 3, 18, MAP_LAVARIDGE_TOWN_GYM_B1F
	warp_def 4, 16, 0, 20, MAP_LAVARIDGE_TOWN_GYM_B1F
	warp_def 12, 3, 3, 19, MAP_LAVARIDGE_TOWN_GYM_B1F
	warp_def 14, 6, 3, 21, MAP_LAVARIDGE_TOWN_GYM_B1F
	warp_def 13, 17, 3, 22, MAP_LAVARIDGE_TOWN_GYM_B1F
	warp_def 12, 12, 3, 23, MAP_LAVARIDGE_TOWN_GYM_B1F
	.globl LAVARIDGE_TOWN_GYM_1F_EventBgEvents
LAVARIDGE_TOWN_GYM_1F_EventBgEvents: @ 0x085066A8
	bg_event 10, 15, 0, 1, LavaridgeTown_Gym_1F_EventScript_001F455E, 0, 0
	bg_event 16, 15, 0, 1, LavaridgeTown_Gym_1F_EventScript_001F456E, 0, 0
	.globl gMapEvents_LAVARIDGE_TOWN_GYM_1F
gMapEvents_LAVARIDGE_TOWN_GYM_1F: @ 0x085066C0
	map_events LAVARIDGE_TOWN_GYM_1F_EventObjects, LAVARIDGE_TOWN_GYM_1F_EventWarps, 0, LAVARIDGE_TOWN_GYM_1F_EventBgEvents
	.globl LAVARIDGE_TOWN_GYM_B1F_EventObjects
LAVARIDGE_TOWN_GYM_B1F_EventObjects: @ 0x085066D4
	object_event 1, 66, 0, 4, 18, 3, 8, 1, 1, 3, 1, 0x081F44EE, 0x0000
	object_event 2, 66, 0, 3, 6, 0, 8, 1, 1, 3, 1, 0x081F449D, 0x0000
	object_event 3, 66, 0, 13, 17, 0, 8, 1, 1, 3, 1, 0x081F4509, 0x0000
	object_event 4, 55, 0, 4, 16, 3, 8, 1, 1, 3, 1, 0x081F4524, 0x0000
	.globl LAVARIDGE_TOWN_GYM_B1F_EventWarps
LAVARIDGE_TOWN_GYM_B1F_EventWarps: @ 0x08506734
	warp_def 10, 18, 3, 2, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 0, 17, 3, 6, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 8, 9, 3, 3, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 5, 14, 3, 5, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 4, 18, 3, 4, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 5, 9, 3, 7, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 2, 15, 3, 8, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 3, 14, 3, 9, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 1, 14, 3, 10, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 0, 10, 3, 11, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 3, 10, 3, 12, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 0, 6, 3, 13, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 3, 6, 3, 14, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 5, 6, 3, 15, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 2, 3, 3, 16, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 5, 2, 3, 17, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 7, 2, 3, 18, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 8, 6, 3, 19, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 10, 6, 3, 20, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 12, 3, 3, 22, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 4, 16, 3, 21, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 14, 6, 3, 23, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 13, 17, 3, 24, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 12, 12, 3, 25, MAP_LAVARIDGE_TOWN_GYM_1F
	.globl gMapEvents_LAVARIDGE_TOWN_GYM_B1F
gMapEvents_LAVARIDGE_TOWN_GYM_B1F: @ 0x085067F4
	map_events LAVARIDGE_TOWN_GYM_B1F_EventObjects, LAVARIDGE_TOWN_GYM_B1F_EventWarps, 0, 0
	.globl LAVARIDGE_TOWN_HOUSE_EventObjects
LAVARIDGE_TOWN_HOUSE_EventObjects: @ 0x08506808
	object_event 1, 29, 0, 2, 3, 3, 1, 1, 1, 0, 0, 0x081F4E4E, 0x0000
	object_event 2, 208, 0, 6, 6, 3, 1, 1, 1, 0, 0, 0x081F4E57, 0x0000
	object_event 3, 5, 0, 8, 4, 3, 2, 1, 1, 0, 0, 0x0827696A, 0x0000
	.globl LAVARIDGE_TOWN_HOUSE_EventWarps
LAVARIDGE_TOWN_HOUSE_EventWarps: @ 0x08506850
	warp_def 3, 7, 0, 4, MAP_LAVARIDGE_TOWN
	warp_def 4, 7, 0, 4, MAP_LAVARIDGE_TOWN
	.globl gMapEvents_LAVARIDGE_TOWN_HOUSE
gMapEvents_LAVARIDGE_TOWN_HOUSE: @ 0x08506860
	map_events LAVARIDGE_TOWN_HOUSE_EventObjects, LAVARIDGE_TOWN_HOUSE_EventWarps, 0, 0
	.globl LAVARIDGE_TOWN_MART_EventObjects
LAVARIDGE_TOWN_MART_EventObjects: @ 0x08506874
	object_event 1, 83, 0, 1, 3, 3, 10, 0, 0, 0, 0, 0x081F4ECD, 0x0000
	object_event 2, 21, 0, 4, 2, 3, 8, 0, 0, 0, 0, 0x081F4EFA, 0x0000
	object_event 3, 30, 0, 9, 5, 3, 10, 0, 0, 0, 0, 0x081F4F03, 0x0000
	.globl LAVARIDGE_TOWN_MART_EventWarps
LAVARIDGE_TOWN_MART_EventWarps: @ 0x085068BC
	warp_def 3, 7, 0, 2, MAP_LAVARIDGE_TOWN
	warp_def 4, 7, 0, 2, MAP_LAVARIDGE_TOWN
	.globl gMapEvents_LAVARIDGE_TOWN_MART
gMapEvents_LAVARIDGE_TOWN_MART: @ 0x085068CC
	map_events LAVARIDGE_TOWN_MART_EventObjects, LAVARIDGE_TOWN_MART_EventWarps, 0, 0
	.globl LAVARIDGE_TOWN_POKEMON_CENTER_1F_EventObjects
LAVARIDGE_TOWN_POKEMON_CENTER_1F_EventObjects: @ 0x085068E0
	object_event 1, 58, 0, 7, 2, 3, 8, 0, 0, 0, 0, LavaridgeTown_PokemonCenter_1F_EventScript_001F4F99, 0x0000
	object_event 2, 35, 0, 11, 8, 3, 7, 0, 0, 0, 0, LavaridgeTown_PokemonCenter_1F_EventScript_001F4FA7, 0x0000
	object_event 3, 24, 0, 10, 6, 0, 9, 0, 0, 0, 0, LavaridgeTown_PokemonCenter_1F_EventScript_001F4FB0, 0x0000
	object_event 4, 48, 0, 1, 3, 3, 10, 0, 0, 0, 0, LavaridgeTown_PokemonCenter_1F_EventScript_001F4FB9, 0x0000
	.globl LAVARIDGE_TOWN_POKEMON_CENTER_1F_EventWarps
LAVARIDGE_TOWN_POKEMON_CENTER_1F_EventWarps: @ 0x08506940
	warp_def 7, 8, 3, 3, MAP_LAVARIDGE_TOWN
	warp_def 6, 8, 3, 3, MAP_LAVARIDGE_TOWN
	warp_def 1, 6, 4, 0, MAP_LAVARIDGE_TOWN_POKEMON_CENTER_2F
	warp_def 2, 1, 0, 5, MAP_LAVARIDGE_TOWN
	.globl gMapEvents_LAVARIDGE_TOWN_POKEMON_CENTER_1F
gMapEvents_LAVARIDGE_TOWN_POKEMON_CENTER_1F: @ 0x08506960
	map_events LAVARIDGE_TOWN_POKEMON_CENTER_1F_EventObjects, LAVARIDGE_TOWN_POKEMON_CENTER_1F_EventWarps, 0, 0
	.globl LAVARIDGE_TOWN_POKEMON_CENTER_2F_EventObjects
LAVARIDGE_TOWN_POKEMON_CENTER_2F_EventObjects: @ 0x08506974
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 3, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	.globl LAVARIDGE_TOWN_POKEMON_CENTER_2F_EventWarps
LAVARIDGE_TOWN_POKEMON_CENTER_2F_EventWarps: @ 0x085069D4
	warp_def 1, 6, 4, 2, MAP_LAVARIDGE_TOWN_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_LAVARIDGE_TOWN_POKEMON_CENTER_2F
gMapEvents_LAVARIDGE_TOWN_POKEMON_CENTER_2F: @ 0x085069EC
	map_events LAVARIDGE_TOWN_POKEMON_CENTER_2F_EventObjects, LAVARIDGE_TOWN_POKEMON_CENTER_2F_EventWarps, 0, 0
	.globl FALLARBOR_TOWN_MART_EventObjects
FALLARBOR_TOWN_MART_EventObjects: @ 0x08506A00
	object_event 1, 83, 0, 1, 3, 3, 10, 0, 0, 0, 0, 0x081F5099, 0x0000
	object_event 2, 20, 0, 5, 3, 3, 2, 1, 1, 0, 0, 0x081F50CC, 0x0000
	object_event 3, 25, 0, 9, 6, 3, 8, 0, 0, 0, 0, 0x081F50D5, 0x0000
	object_event 4, 203, 0, 2, 5, 3, 1, 1, 1, 0, 0, 0x081F50DE, 0x0000
	object_event 5, 10, 0, 7, 2, 3, 7, 0, 0, 0, 0, 0x082769D2, 0x0000
	.globl FALLARBOR_TOWN_MART_EventWarps
FALLARBOR_TOWN_MART_EventWarps: @ 0x08506A78
	warp_def 3, 7, 0, 0, MAP_FALLARBOR_TOWN
	warp_def 4, 7, 0, 0, MAP_FALLARBOR_TOWN
	.globl gMapEvents_FALLARBOR_TOWN_MART
gMapEvents_FALLARBOR_TOWN_MART: @ 0x08506A88
	map_events FALLARBOR_TOWN_MART_EventObjects, FALLARBOR_TOWN_MART_EventWarps, 0, 0
	.globl FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventObjects
FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventObjects: @ 0x08506A9C
	object_event 1, 44, 0, 6, 5, 3, 8, 1, 1, 0, 0, FallarborTown_BattleTentLobby_EventScript_001F5320, 0x0000
	object_event 2, 55, 0, 1, 5, 3, 5, 1, 1, 0, 0, FallarborTown_BattleTentLobby_EventScript_001F552C, 0x0000
	object_event 3, 11, 0, 12, 6, 3, 3, 1, 1, 0, 0, FallarborTown_BattleTentLobby_EventScript_001F5535, 0x0000
	object_event 4, 47, 0, 10, 9, 3, 8, 1, 1, 0, 0, FallarborTown_BattleTentLobby_EventScript_001F553E, 0x0000
	object_event 5, 219, 0, 0, 7, 3, 10, 1, 1, 0, 0, FallarborTown_BattleTentLobby_EventScript_001F5547, 0x02FF
	.globl FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventWarps
FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventWarps: @ 0x08506B14
	warp_def 6, 9, 0, 1, MAP_FALLARBOR_TOWN
	warp_def 7, 9, 0, 1, MAP_FALLARBOR_TOWN
	.globl FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventBgEvents
FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventBgEvents: @ 0x08506B24
	bg_event 4, 5, 0, 0, FallarborTown_BattleTentLobby_EventScript_001F556E, 0, 0
	.globl gMapEvents_FALLARBOR_TOWN_BATTLE_TENT_LOBBY
gMapEvents_FALLARBOR_TOWN_BATTLE_TENT_LOBBY: @ 0x08506B30
	map_events FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventObjects, FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventWarps, 0, FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventBgEvents
	.globl FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR_EventObjects
FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR_EventObjects: @ 0x08506B44
	object_event 1, 44, 0, 2, 6, 3, 7, 1, 1, 0, 0, 0x00000000, 0x0000
	.globl gMapEvents_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR
gMapEvents_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR: @ 0x08506B5C
	map_events FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR_EventObjects, 0, 0, 0
	.globl FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM_EventObjects
FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM_EventObjects: @ 0x08506B70
	object_event 1, 241, 0, 4, 8, 3, 7, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 2, 44, 0, 3, 2, 0, 8, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 3, 240, 0, 5, 1, 3, 8, 1, 1, 0, 0, 0x00000000, 0x0000
	.globl gMapEvents_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM
gMapEvents_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM: @ 0x08506BB8
	map_events FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM_EventObjects, 0, 0, 0
	.globl FALLARBOR_TOWN_POKEMON_CENTER_1F_EventObjects
FALLARBOR_TOWN_POKEMON_CENTER_1F_EventObjects: @ 0x08506BCC
	object_event 1, 58, 0, 7, 2, 3, 8, 0, 0, 0, 0, FallarborTown_PokemonCenter_1F_EventScript_001F5C62, 0x0000
	object_event 2, 14, 0, 10, 6, 3, 10, 0, 0, 0, 0, FallarborTown_PokemonCenter_1F_EventScript_001F5C70, 0x0000
	object_event 3, 21, 0, 2, 3, 3, 8, 0, 0, 0, 0, FallarborTown_PokemonCenter_1F_EventScript_001F5C79, 0x0000
	object_event 4, 20, 0, 10, 2, 3, 7, 0, 0, 0, 0, FallarborTown_PokemonCenter_1F_EventScript_001F5C82, 0x0367
	.globl FALLARBOR_TOWN_POKEMON_CENTER_1F_EventWarps
FALLARBOR_TOWN_POKEMON_CENTER_1F_EventWarps: @ 0x08506C2C
	warp_def 7, 8, 3, 2, MAP_FALLARBOR_TOWN
	warp_def 6, 8, 3, 2, MAP_FALLARBOR_TOWN
	warp_def 1, 6, 4, 0, MAP_FALLARBOR_TOWN_POKEMON_CENTER_2F
	.globl gMapEvents_FALLARBOR_TOWN_POKEMON_CENTER_1F
gMapEvents_FALLARBOR_TOWN_POKEMON_CENTER_1F: @ 0x08506C44
	map_events FALLARBOR_TOWN_POKEMON_CENTER_1F_EventObjects, FALLARBOR_TOWN_POKEMON_CENTER_1F_EventWarps, 0, 0
	.globl FALLARBOR_TOWN_POKEMON_CENTER_2F_EventObjects
FALLARBOR_TOWN_POKEMON_CENTER_2F_EventObjects: @ 0x08506C58
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 3, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	.globl FALLARBOR_TOWN_POKEMON_CENTER_2F_EventWarps
FALLARBOR_TOWN_POKEMON_CENTER_2F_EventWarps: @ 0x08506CB8
	warp_def 1, 6, 4, 2, MAP_FALLARBOR_TOWN_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_FALLARBOR_TOWN_POKEMON_CENTER_2F
gMapEvents_FALLARBOR_TOWN_POKEMON_CENTER_2F: @ 0x08506CD0
	map_events FALLARBOR_TOWN_POKEMON_CENTER_2F_EventObjects, FALLARBOR_TOWN_POKEMON_CENTER_2F_EventWarps, 0, 0
	.globl FALLARBOR_TOWN_COZMOS_HOUSE_EventObjects
FALLARBOR_TOWN_COZMOS_HOUSE_EventObjects: @ 0x08506CE4
	object_event 1, 46, 0, 6, 4, 3, 2, 1, 1, 0, 0, 0x081F5E79, 0x03A0
	object_event 2, 20, 0, 5, 6, 3, 5, 1, 0, 0, 0, 0x081F5F22, 0x0000
	.globl FALLARBOR_TOWN_COZMOS_HOUSE_EventWarps
FALLARBOR_TOWN_COZMOS_HOUSE_EventWarps: @ 0x08506D14
	warp_def 3, 8, 0, 3, MAP_FALLARBOR_TOWN
	warp_def 4, 8, 0, 3, MAP_FALLARBOR_TOWN
	.globl gMapEvents_FALLARBOR_TOWN_COZMOS_HOUSE
gMapEvents_FALLARBOR_TOWN_COZMOS_HOUSE: @ 0x08506D24
	map_events FALLARBOR_TOWN_COZMOS_HOUSE_EventObjects, FALLARBOR_TOWN_COZMOS_HOUSE_EventWarps, 0, 0
	.globl FALLARBOR_TOWN_MOVE_RELEARNERS_HOUSE_EventObjects
FALLARBOR_TOWN_MOVE_RELEARNERS_HOUSE_EventObjects: @ 0x08506D38
	object_event 1, 17, 0, 4, 4, 3, 8, 0, 0, 0, 0, 0x081F6156, 0x0000
	.globl FALLARBOR_TOWN_MOVE_RELEARNERS_HOUSE_EventWarps
FALLARBOR_TOWN_MOVE_RELEARNERS_HOUSE_EventWarps: @ 0x08506D50
	warp_def 3, 7, 0, 4, MAP_FALLARBOR_TOWN
	warp_def 4, 7, 0, 4, MAP_FALLARBOR_TOWN
	.globl gMapEvents_FALLARBOR_TOWN_MOVE_RELEARNERS_HOUSE
gMapEvents_FALLARBOR_TOWN_MOVE_RELEARNERS_HOUSE: @ 0x08506D60
	map_events FALLARBOR_TOWN_MOVE_RELEARNERS_HOUSE_EventObjects, FALLARBOR_TOWN_MOVE_RELEARNERS_HOUSE_EventWarps, 0, 0
	.globl VERDANTURF_TOWN_BATTLE_TENT_LOBBY_EventObjects
VERDANTURF_TOWN_BATTLE_TENT_LOBBY_EventObjects: @ 0x08506D74
	object_event 1, 21, 0, 6, 5, 3, 8, 1, 1, 0, 0, VerdanturfTown_BattleTentLobby_EventScript_001F6508, 0x0000
	object_event 2, 8, 0, 0, 5, 3, 2, 1, 1, 0, 0, VerdanturfTown_BattleTentLobby_EventScript_001F6710, 0x0000
	object_event 3, 13, 0, 9, 7, 3, 2, 1, 1, 0, 0, VerdanturfTown_BattleTentLobby_EventScript_001F6751, 0x0000
	object_event 4, 9, 0, 1, 8, 3, 10, 1, 1, 0, 0, VerdanturfTown_BattleTentLobby_EventScript_001F675A, 0x0000
	object_event 5, 219, 0, 12, 6, 3, 9, 1, 1, 0, 0, VerdanturfTown_BattleTentLobby_EventScript_001F6765, 0x02FE
	object_event 6, 11, 0, 2, 8, 3, 9, 1, 1, 0, 0, VerdanturfTown_BattleTentLobby_EventScript_001F678C, 0x0000
	.globl VERDANTURF_TOWN_BATTLE_TENT_LOBBY_EventWarps
VERDANTURF_TOWN_BATTLE_TENT_LOBBY_EventWarps: @ 0x08506E04
	warp_def 6, 9, 0, 0, MAP_VERDANTURF_TOWN
	warp_def 7, 9, 0, 0, MAP_VERDANTURF_TOWN
	.globl VERDANTURF_TOWN_BATTLE_TENT_LOBBY_EventBgEvents
VERDANTURF_TOWN_BATTLE_TENT_LOBBY_EventBgEvents: @ 0x08506E14
	bg_event 4, 5, 0, 0, VerdanturfTown_BattleTentLobby_EventScript_001F6797, 0, 0
	.globl gMapEvents_VERDANTURF_TOWN_BATTLE_TENT_LOBBY
gMapEvents_VERDANTURF_TOWN_BATTLE_TENT_LOBBY: @ 0x08506E20
	map_events VERDANTURF_TOWN_BATTLE_TENT_LOBBY_EventObjects, VERDANTURF_TOWN_BATTLE_TENT_LOBBY_EventWarps, 0, VERDANTURF_TOWN_BATTLE_TENT_LOBBY_EventBgEvents
	.globl VERDANTURF_TOWN_BATTLE_TENT_CORRIDOR_EventObjects
VERDANTURF_TOWN_BATTLE_TENT_CORRIDOR_EventObjects: @ 0x08506E34
	object_event 1, 21, 0, 2, 6, 3, 7, 1, 1, 0, 0, 0x00000000, 0x0000
	.globl gMapEvents_VERDANTURF_TOWN_BATTLE_TENT_CORRIDOR
gMapEvents_VERDANTURF_TOWN_BATTLE_TENT_CORRIDOR: @ 0x08506E4C
	map_events VERDANTURF_TOWN_BATTLE_TENT_CORRIDOR_EventObjects, 0, 0, 0
	.globl VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM_EventObjects
VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM_EventObjects: @ 0x08506E60
	object_event 1, 241, 0, 2, 8, 3, 7, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 2, 240, 0, 11, 1, 3, 8, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 3, 21, 0, 2, 4, 0, 10, 1, 1, 0, 0, 0x00000000, 0x0000
	.globl gMapEvents_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM
gMapEvents_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM: @ 0x08506EA8
	map_events VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM_EventObjects, 0, 0, 0
	.globl VERDANTURF_TOWN_MART_EventObjects
VERDANTURF_TOWN_MART_EventObjects: @ 0x08506EBC
	object_event 1, 83, 0, 1, 3, 3, 10, 0, 0, 0, 0, 0x081F6F28, 0x0000
	object_event 2, 9, 0, 5, 4, 3, 10, 0, 0, 0, 0, 0x081F6F5A, 0x0000
	object_event 3, 22, 0, 8, 5, 3, 9, 0, 0, 0, 0, 0x081F6F63, 0x0000
	object_event 4, 47, 0, 3, 2, 3, 9, 1, 1, 0, 0, 0x081F6F6C, 0x0000
	.globl VERDANTURF_TOWN_MART_EventWarps
VERDANTURF_TOWN_MART_EventWarps: @ 0x08506F1C
	warp_def 3, 7, 0, 1, MAP_VERDANTURF_TOWN
	warp_def 4, 7, 0, 1, MAP_VERDANTURF_TOWN
	.globl gMapEvents_VERDANTURF_TOWN_MART
gMapEvents_VERDANTURF_TOWN_MART: @ 0x08506F2C
	map_events VERDANTURF_TOWN_MART_EventObjects, VERDANTURF_TOWN_MART_EventWarps, 0, 0
	.globl VERDANTURF_TOWN_POKEMON_CENTER_1F_EventObjects
VERDANTURF_TOWN_POKEMON_CENTER_1F_EventObjects: @ 0x08506F40
	object_event 1, 58, 0, 7, 2, 3, 8, 0, 0, 0, 0, VerdanturfTown_PokemonCenter_1F_EventScript_001F7035, 0x0000
	object_event 2, 48, 0, 4, 5, 3, 5, 1, 0, 0, 0, VerdanturfTown_PokemonCenter_1F_EventScript_001F7043, 0x0000
	object_event 3, 21, 0, 12, 2, 3, 7, 0, 0, 0, 0, VerdanturfTown_PokemonCenter_1F_EventScript_001F704C, 0x0000
	object_event 4, 11, 0, 10, 6, 3, 9, 1, 0, 0, 0, 0x08276902, 0x0000
	.globl VERDANTURF_TOWN_POKEMON_CENTER_1F_EventWarps
VERDANTURF_TOWN_POKEMON_CENTER_1F_EventWarps: @ 0x08506FA0
	warp_def 7, 8, 3, 2, MAP_VERDANTURF_TOWN
	warp_def 6, 8, 3, 2, MAP_VERDANTURF_TOWN
	warp_def 1, 6, 4, 0, MAP_VERDANTURF_TOWN_POKEMON_CENTER_2F
	.globl gMapEvents_VERDANTURF_TOWN_POKEMON_CENTER_1F
gMapEvents_VERDANTURF_TOWN_POKEMON_CENTER_1F: @ 0x08506FB8
	map_events VERDANTURF_TOWN_POKEMON_CENTER_1F_EventObjects, VERDANTURF_TOWN_POKEMON_CENTER_1F_EventWarps, 0, 0
	.globl VERDANTURF_TOWN_POKEMON_CENTER_2F_EventObjects
VERDANTURF_TOWN_POKEMON_CENTER_2F_EventObjects: @ 0x08506FCC
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 3, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	.globl VERDANTURF_TOWN_POKEMON_CENTER_2F_EventWarps
VERDANTURF_TOWN_POKEMON_CENTER_2F_EventWarps: @ 0x0850702C
	warp_def 1, 6, 4, 2, MAP_VERDANTURF_TOWN_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_VERDANTURF_TOWN_POKEMON_CENTER_2F
gMapEvents_VERDANTURF_TOWN_POKEMON_CENTER_2F: @ 0x08507044
	map_events VERDANTURF_TOWN_POKEMON_CENTER_2F_EventObjects, VERDANTURF_TOWN_POKEMON_CENTER_2F_EventWarps, 0, 0
	.globl VERDANTURF_TOWN_WANDAS_HOUSE_EventObjects
VERDANTURF_TOWN_WANDAS_HOUSE_EventObjects: @ 0x08507058
	object_event 1, 135, 0, 14, 5, 3, 2, 1, 1, 0, 0, 0x081F7106, 0x0326
	object_event 2, 44, 0, 5, 4, 3, 8, 0, 0, 0, 0, 0x081F715A, 0x0328
	object_event 3, 25, 0, 7, 2, 3, 8, 0, 0, 0, 0, 0x081F7128, 0x0329
	object_event 4, 18, 0, 2, 4, 3, 10, 0, 0, 0, 0, 0x081F7195, 0x0000
	object_event 5, 20, 0, 5, 5, 3, 9, 0, 0, 0, 0, 0x081F7163, 0x03D8
	.globl VERDANTURF_TOWN_WANDAS_HOUSE_EventWarps
VERDANTURF_TOWN_WANDAS_HOUSE_EventWarps: @ 0x085070D0
	warp_def 7, 7, 0, 3, MAP_VERDANTURF_TOWN
	warp_def 8, 7, 0, 3, MAP_VERDANTURF_TOWN
	.globl gMapEvents_VERDANTURF_TOWN_WANDAS_HOUSE
gMapEvents_VERDANTURF_TOWN_WANDAS_HOUSE: @ 0x085070E0
	map_events VERDANTURF_TOWN_WANDAS_HOUSE_EventObjects, VERDANTURF_TOWN_WANDAS_HOUSE_EventWarps, 0, 0
	.globl VERDANTURF_TOWN_FRIENDSHIP_RATERS_HOUSE_EventObjects
VERDANTURF_TOWN_FRIENDSHIP_RATERS_HOUSE_EventObjects: @ 0x085070F4
	object_event 1, 20, 0, 3, 4, 3, 8, 0, 0, 0, 0, 0x081F7557, 0x0000
	object_event 2, 209, 0, 4, 4, 3, 8, 0, 0, 0, 0, 0x081F7600, 0x0000
	.globl VERDANTURF_TOWN_FRIENDSHIP_RATERS_HOUSE_EventWarps
VERDANTURF_TOWN_FRIENDSHIP_RATERS_HOUSE_EventWarps: @ 0x08507124
	warp_def 3, 7, 0, 5, MAP_VERDANTURF_TOWN
	warp_def 4, 7, 0, 5, MAP_VERDANTURF_TOWN
	.globl gMapEvents_VERDANTURF_TOWN_FRIENDSHIP_RATERS_HOUSE
gMapEvents_VERDANTURF_TOWN_FRIENDSHIP_RATERS_HOUSE: @ 0x08507134
	map_events VERDANTURF_TOWN_FRIENDSHIP_RATERS_HOUSE_EventObjects, VERDANTURF_TOWN_FRIENDSHIP_RATERS_HOUSE_EventWarps, 0, 0
	.globl VERDANTURF_TOWN_HOUSE_EventObjects
VERDANTURF_TOWN_HOUSE_EventObjects: @ 0x08507148
	object_event 1, 34, 0, 4, 5, 3, 7, 0, 0, 0, 0, 0x081F7780, 0x0000
	object_event 2, 34, 0, 4, 4, 3, 8, 0, 0, 0, 0, 0x081F7789, 0x0000
	.globl VERDANTURF_TOWN_HOUSE_EventWarps
VERDANTURF_TOWN_HOUSE_EventWarps: @ 0x08507178
	warp_def 3, 8, 0, 6, MAP_VERDANTURF_TOWN
	warp_def 4, 8, 0, 6, MAP_VERDANTURF_TOWN
	.globl gMapEvents_VERDANTURF_TOWN_HOUSE
gMapEvents_VERDANTURF_TOWN_HOUSE: @ 0x08507188
	map_events VERDANTURF_TOWN_HOUSE_EventObjects, VERDANTURF_TOWN_HOUSE_EventWarps, 0, 0
	.globl PACIFIDLOG_TOWN_POKEMON_CENTER_1F_EventObjects
PACIFIDLOG_TOWN_POKEMON_CENTER_1F_EventObjects: @ 0x0850719C
	object_event 1, 58, 0, 7, 2, 3, 8, 0, 0, 0, 0, PacifidlogTown_PokemonCenter_1F_EventScript_001F7839, 0x0000
	object_event 2, 29, 0, 10, 6, 3, 9, 0, 0, 0, 0, PacifidlogTown_PokemonCenter_1F_EventScript_001F7859, 0x0000
	object_event 3, 10, 0, 2, 2, 3, 7, 0, 0, 0, 0, PacifidlogTown_PokemonCenter_1F_EventScript_001F7847, 0x0000
	object_event 4, 16, 0, 4, 5, 3, 1, 1, 1, 0, 0, PacifidlogTown_PokemonCenter_1F_EventScript_001F7850, 0x0000
	object_event 5, 66, 0, 12, 8, 3, 7, 0, 0, 0, 0, 0x08276BDA, 0x0000
	.globl PACIFIDLOG_TOWN_POKEMON_CENTER_1F_EventWarps
PACIFIDLOG_TOWN_POKEMON_CENTER_1F_EventWarps: @ 0x08507214
	warp_def 7, 8, 3, 0, MAP_PACIFIDLOG_TOWN
	warp_def 6, 8, 3, 0, MAP_PACIFIDLOG_TOWN
	warp_def 1, 6, 4, 0, MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_2F
	.globl gMapEvents_PACIFIDLOG_TOWN_POKEMON_CENTER_1F
gMapEvents_PACIFIDLOG_TOWN_POKEMON_CENTER_1F: @ 0x0850722C
	map_events PACIFIDLOG_TOWN_POKEMON_CENTER_1F_EventObjects, PACIFIDLOG_TOWN_POKEMON_CENTER_1F_EventWarps, 0, 0
	.globl PACIFIDLOG_TOWN_POKEMON_CENTER_2F_EventObjects
PACIFIDLOG_TOWN_POKEMON_CENTER_2F_EventObjects: @ 0x08507240
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 3, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	.globl PACIFIDLOG_TOWN_POKEMON_CENTER_2F_EventWarps
PACIFIDLOG_TOWN_POKEMON_CENTER_2F_EventWarps: @ 0x085072A0
	warp_def 1, 6, 4, 2, MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_PACIFIDLOG_TOWN_POKEMON_CENTER_2F
gMapEvents_PACIFIDLOG_TOWN_POKEMON_CENTER_2F: @ 0x085072B8
	map_events PACIFIDLOG_TOWN_POKEMON_CENTER_2F_EventObjects, PACIFIDLOG_TOWN_POKEMON_CENTER_2F_EventWarps, 0, 0
	.globl PACIFIDLOG_TOWN_HOUSE1_EventObjects
PACIFIDLOG_TOWN_HOUSE1_EventObjects: @ 0x085072CC
	object_event 1, 66, 0, 3, 5, 3, 8, 0, 0, 0, 0, 0x081F793F, 0x0000
	object_event 2, 26, 0, 6, 4, 3, 9, 0, 0, 0, 0, 0x081F7948, 0x0000
	.globl PACIFIDLOG_TOWN_HOUSE1_EventWarps
PACIFIDLOG_TOWN_HOUSE1_EventWarps: @ 0x085072FC
	warp_def 4, 8, 0, 1, MAP_PACIFIDLOG_TOWN
	warp_def 5, 8, 0, 1, MAP_PACIFIDLOG_TOWN
	.globl gMapEvents_PACIFIDLOG_TOWN_HOUSE1
gMapEvents_PACIFIDLOG_TOWN_HOUSE1: @ 0x0850730C
	map_events PACIFIDLOG_TOWN_HOUSE1_EventObjects, PACIFIDLOG_TOWN_HOUSE1_EventWarps, 0, 0
	.globl PACIFIDLOG_TOWN_HOUSE2_EventObjects
PACIFIDLOG_TOWN_HOUSE2_EventObjects: @ 0x08507320
	object_event 1, 48, 0, 3, 5, 3, 8, 1, 1, 0, 0, 0x081F7A00, 0x0000
	object_event 2, 214, 0, 8, 6, 3, 1, 1, 1, 0, 0, 0x081F7AFF, 0x0000
	object_event 3, 214, 0, 1, 7, 3, 1, 1, 1, 0, 0, 0x081F7B1A, 0x0000
	.globl PACIFIDLOG_TOWN_HOUSE2_EventWarps
PACIFIDLOG_TOWN_HOUSE2_EventWarps: @ 0x08507368
	warp_def 4, 8, 0, 2, MAP_PACIFIDLOG_TOWN
	warp_def 5, 8, 0, 2, MAP_PACIFIDLOG_TOWN
	.globl gMapEvents_PACIFIDLOG_TOWN_HOUSE2
gMapEvents_PACIFIDLOG_TOWN_HOUSE2: @ 0x08507378
	map_events PACIFIDLOG_TOWN_HOUSE2_EventObjects, PACIFIDLOG_TOWN_HOUSE2_EventWarps, 0, 0
	.globl PACIFIDLOG_TOWN_HOUSE3_EventObjects
PACIFIDLOG_TOWN_HOUSE3_EventObjects: @ 0x0850738C
	object_event 1, 10, 0, 3, 5, 3, 18, 0, 0, 0, 0, 0x081F7DBF, 0x0000
	object_event 2, 33, 0, 4, 2, 3, 10, 1, 1, 0, 0, 0x081F7D1B, 0x0000
	.globl PACIFIDLOG_TOWN_HOUSE3_EventWarps
PACIFIDLOG_TOWN_HOUSE3_EventWarps: @ 0x085073BC
	warp_def 4, 8, 0, 3, MAP_PACIFIDLOG_TOWN
	warp_def 5, 8, 0, 3, MAP_PACIFIDLOG_TOWN
	.globl gMapEvents_PACIFIDLOG_TOWN_HOUSE3
gMapEvents_PACIFIDLOG_TOWN_HOUSE3: @ 0x085073CC
	map_events PACIFIDLOG_TOWN_HOUSE3_EventObjects, PACIFIDLOG_TOWN_HOUSE3_EventWarps, 0, 0
	.globl PACIFIDLOG_TOWN_HOUSE4_EventObjects
PACIFIDLOG_TOWN_HOUSE4_EventObjects: @ 0x085073E0
	object_event 1, 20, 0, 3, 4, 3, 8, 0, 0, 0, 0, 0x081F7F47, 0x0000
	object_event 2, 12, 0, 7, 5, 3, 2, 1, 1, 0, 0, 0x081F7F3E, 0x0000
	object_event 3, 7, 0, 7, 4, 3, 2, 1, 1, 0, 0, 0x081F7F50, 0x0000
	.globl PACIFIDLOG_TOWN_HOUSE4_EventWarps
PACIFIDLOG_TOWN_HOUSE4_EventWarps: @ 0x08507428
	warp_def 4, 8, 0, 4, MAP_PACIFIDLOG_TOWN
	warp_def 5, 8, 0, 4, MAP_PACIFIDLOG_TOWN
	.globl gMapEvents_PACIFIDLOG_TOWN_HOUSE4
gMapEvents_PACIFIDLOG_TOWN_HOUSE4: @ 0x08507438
	map_events PACIFIDLOG_TOWN_HOUSE4_EventObjects, PACIFIDLOG_TOWN_HOUSE4_EventWarps, 0, 0
	.globl PACIFIDLOG_TOWN_HOUSE5_EventObjects
PACIFIDLOG_TOWN_HOUSE5_EventObjects: @ 0x0850744C
	object_event 1, 21, 0, 9, 4, 3, 10, 0, 0, 0, 0, 0x081F8056, 0x0000
	object_event 2, 48, 0, 3, 4, 3, 10, 0, 0, 0, 0, 0x081F807C, 0x0000
	.globl PACIFIDLOG_TOWN_HOUSE5_EventWarps
PACIFIDLOG_TOWN_HOUSE5_EventWarps: @ 0x0850747C
	warp_def 4, 8, 0, 5, MAP_PACIFIDLOG_TOWN
	warp_def 5, 8, 0, 5, MAP_PACIFIDLOG_TOWN
	.globl gMapEvents_PACIFIDLOG_TOWN_HOUSE5
gMapEvents_PACIFIDLOG_TOWN_HOUSE5: @ 0x0850748C
	map_events PACIFIDLOG_TOWN_HOUSE5_EventObjects, PACIFIDLOG_TOWN_HOUSE5_EventWarps, 0, 0
	.globl PETALBURG_CITY_WALLYS_HOUSE_EventObjects
PETALBURG_CITY_WALLYS_HOUSE_EventObjects: @ 0x085074A0
	object_event 1, 25, 0, 3, 4, 3, 10, 0, 0, 0, 0, PetalburgCity_WallysHouse_EventScript_001F815A, 0x0000
	object_event 2, 26, 0, 7, 5, 3, 9, 0, 0, 0, 0, PetalburgCity_WallysHouse_EventScript_001F81A2, 0x0000
	.globl PETALBURG_CITY_WALLYS_HOUSE_EventWarps
PETALBURG_CITY_WALLYS_HOUSE_EventWarps: @ 0x085074D0
	warp_def 3, 7, 0, 1, MAP_PETALBURG_CITY
	warp_def 4, 7, 0, 1, MAP_PETALBURG_CITY
	.globl gMapEvents_PETALBURG_CITY_WALLYS_HOUSE
gMapEvents_PETALBURG_CITY_WALLYS_HOUSE: @ 0x085074E0
	map_events PETALBURG_CITY_WALLYS_HOUSE_EventObjects, PETALBURG_CITY_WALLYS_HOUSE_EventWarps, 0, 0
	.globl PETALBURG_CITY_GYM_EventObjects
PETALBURG_CITY_GYM_EventObjects: @ 0x085074F4
	object_event 1, 129, 0, 4, 2, 0, 8, 0, 0, 0, 0, PetalburgCity_Gym_EventScript_001F8688, 0x0304
	object_event 2, 34, 0, 4, 94, 3, 8, 0, 0, 1, 0, 0x081F9141, 0x0000
	object_event 3, 33, 0, 4, 81, 3, 8, 0, 0, 1, 0, 0x081F9051, 0x0000
	object_event 4, 33, 0, 4, 42, 3, 8, 0, 0, 1, 0, 0x081F908D, 0x0000
	object_event 5, 34, 0, 4, 55, 3, 8, 0, 0, 1, 0, 0x081F917D, 0x0000
	object_event 6, 33, 0, 4, 68, 3, 8, 0, 0, 1, 0, 0x081F90C9, 0x0000
	object_event 7, 34, 0, 4, 16, 3, 8, 0, 0, 1, 0, 0x081F91B9, 0x0000
	object_event 8, 33, 0, 4, 29, 3, 8, 0, 0, 1, 0, 0x081F9105, 0x0000
	object_event 9, 23, 0, 3, 109, 3, 8, 0, 0, 0, 0, PetalburgCity_Gym_EventScript_001F93E6, 0x030D
	object_event 10, 135, 0, 4, 111, 3, 7, 0, 0, 0, 0, 0x00000000, 0x0362
	object_event 11, 25, 0, 1, 7, 3, 7, 1, 1, 0, 0, 0x00000000, 0x0338
	.globl PETALBURG_CITY_GYM_EventWarps
PETALBURG_CITY_GYM_EventWarps: @ 0x085075FC
	warp_def 4, 111, 3, 2, MAP_PETALBURG_CITY
	warp_def 5, 111, 3, 2, MAP_PETALBURG_CITY
	warp_def 1, 105, 3, 3, MAP_PETALBURG_CITY_GYM
	warp_def 7, 85, 3, 2, MAP_PETALBURG_CITY_GYM
	warp_def 6, 85, 3, 2, MAP_PETALBURG_CITY_GYM
	warp_def 7, 105, 3, 6, MAP_PETALBURG_CITY_GYM
	warp_def 1, 98, 3, 5, MAP_PETALBURG_CITY_GYM
	warp_def 2, 98, 3, 5, MAP_PETALBURG_CITY_GYM
	warp_def 1, 79, 3, 10, MAP_PETALBURG_CITY_GYM
	warp_def 7, 79, 3, 12, MAP_PETALBURG_CITY_GYM
	warp_def 7, 46, 3, 8, MAP_PETALBURG_CITY_GYM
	warp_def 6, 46, 3, 8, MAP_PETALBURG_CITY_GYM
	warp_def 1, 59, 3, 9, MAP_PETALBURG_CITY_GYM
	warp_def 2, 59, 3, 9, MAP_PETALBURG_CITY_GYM
	warp_def 1, 92, 3, 16, MAP_PETALBURG_CITY_GYM
	warp_def 7, 92, 3, 18, MAP_PETALBURG_CITY_GYM
	warp_def 7, 59, 3, 14, MAP_PETALBURG_CITY_GYM
	warp_def 6, 59, 3, 14, MAP_PETALBURG_CITY_GYM
	warp_def 1, 72, 3, 15, MAP_PETALBURG_CITY_GYM
	warp_def 2, 72, 3, 15, MAP_PETALBURG_CITY_GYM
	warp_def 7, 40, 3, 24, MAP_PETALBURG_CITY_GYM
	warp_def 1, 53, 3, 26, MAP_PETALBURG_CITY_GYM
	warp_def 7, 53, 3, 28, MAP_PETALBURG_CITY_GYM
	warp_def 1, 66, 3, 30, MAP_PETALBURG_CITY_GYM
	warp_def 1, 20, 3, 20, MAP_PETALBURG_CITY_GYM
	warp_def 2, 20, 3, 20, MAP_PETALBURG_CITY_GYM
	warp_def 7, 20, 3, 21, MAP_PETALBURG_CITY_GYM
	warp_def 6, 20, 3, 21, MAP_PETALBURG_CITY_GYM
	warp_def 1, 33, 3, 22, MAP_PETALBURG_CITY_GYM
	warp_def 2, 33, 3, 22, MAP_PETALBURG_CITY_GYM
	warp_def 7, 33, 3, 23, MAP_PETALBURG_CITY_GYM
	warp_def 6, 33, 3, 23, MAP_PETALBURG_CITY_GYM
	warp_def 7, 14, 3, 34, MAP_PETALBURG_CITY_GYM
	warp_def 1, 27, 3, 36, MAP_PETALBURG_CITY_GYM
	warp_def 1, 7, 3, 32, MAP_PETALBURG_CITY_GYM
	warp_def 2, 7, 3, 32, MAP_PETALBURG_CITY_GYM
	warp_def 7, 7, 3, 33, MAP_PETALBURG_CITY_GYM
	warp_def 6, 7, 3, 33, MAP_PETALBURG_CITY_GYM
	.globl PETALBURG_CITY_GYM_EventBgEvents
PETALBURG_CITY_GYM_EventBgEvents: @ 0x0850772C
	bg_event 1, 105, 3, 0, PetalburgCity_Gym_EventScript_001F8DCE, 0, 0
	bg_event 7, 105, 3, 0, PetalburgCity_Gym_EventScript_001F8E1E, 0, 0
	bg_event 1, 79, 3, 0, PetalburgCity_Gym_EventScript_001F8E53, 0, 0
	bg_event 7, 79, 3, 0, PetalburgCity_Gym_EventScript_001F8E86, 0, 0
	bg_event 1, 92, 3, 0, PetalburgCity_Gym_EventScript_001F8EB9, 0, 0
	bg_event 7, 92, 3, 0, PetalburgCity_Gym_EventScript_001F8EEC, 0, 0
	bg_event 7, 40, 3, 0, PetalburgCity_Gym_EventScript_001F8F1F, 0, 0
	bg_event 1, 53, 3, 0, PetalburgCity_Gym_EventScript_001F8F52, 0, 0
	bg_event 7, 53, 3, 0, PetalburgCity_Gym_EventScript_001F8F85, 0, 0
	bg_event 1, 66, 3, 0, PetalburgCity_Gym_EventScript_001F8FB8, 0, 0
	bg_event 7, 14, 3, 0, PetalburgCity_Gym_EventScript_001F8FEB, 0, 0
	bg_event 1, 27, 3, 0, PetalburgCity_Gym_EventScript_001F901E, 0, 0
	bg_event 1, 110, 3, 1, PetalburgCity_Gym_EventScript_001F9405, 0, 0
	bg_event 7, 110, 3, 1, PetalburgCity_Gym_EventScript_001F9415, 0, 0
	.globl gMapEvents_PETALBURG_CITY_GYM
gMapEvents_PETALBURG_CITY_GYM: @ 0x085077D4
	map_events PETALBURG_CITY_GYM_EventObjects, PETALBURG_CITY_GYM_EventWarps, 0, PETALBURG_CITY_GYM_EventBgEvents
	.globl PETALBURG_CITY_HOUSE1_EventObjects
PETALBURG_CITY_HOUSE1_EventObjects: @ 0x085077E8
	object_event 1, 8, 0, 7, 4, 3, 2, 2, 2, 0, 0, 0x081FA647, 0x0000
	object_event 2, 21, 0, 4, 4, 3, 8, 0, 0, 0, 0, 0x081FA63E, 0x0000
	.globl PETALBURG_CITY_HOUSE1_EventWarps
PETALBURG_CITY_HOUSE1_EventWarps: @ 0x08507818
	warp_def 3, 8, 0, 0, MAP_PETALBURG_CITY
	warp_def 4, 8, 0, 0, MAP_PETALBURG_CITY
	.globl gMapEvents_PETALBURG_CITY_HOUSE1
gMapEvents_PETALBURG_CITY_HOUSE1: @ 0x08507828
	map_events PETALBURG_CITY_HOUSE1_EventObjects, PETALBURG_CITY_HOUSE1_EventWarps, 0, 0
	.globl PETALBURG_CITY_HOUSE2_EventObjects
PETALBURG_CITY_HOUSE2_EventObjects: @ 0x0850783C
	object_event 1, 18, 0, 2, 5, 3, 2, 1, 1, 0, 0, 0x081FA721, 0x0000
	object_event 2, 38, 0, 7, 5, 3, 8, 0, 0, 0, 0, 0x081FA72A, 0x0000
	.globl PETALBURG_CITY_HOUSE2_EventWarps
PETALBURG_CITY_HOUSE2_EventWarps: @ 0x0850786C
	warp_def 3, 7, 0, 4, MAP_PETALBURG_CITY
	warp_def 4, 7, 0, 4, MAP_PETALBURG_CITY
	.globl gMapEvents_PETALBURG_CITY_HOUSE2
gMapEvents_PETALBURG_CITY_HOUSE2: @ 0x0850787C
	map_events PETALBURG_CITY_HOUSE2_EventObjects, PETALBURG_CITY_HOUSE2_EventWarps, 0, 0
	.globl PETALBURG_CITY_POKEMON_CENTER_1F_EventObjects
PETALBURG_CITY_POKEMON_CENTER_1F_EventObjects: @ 0x08507890
	object_event 1, 58, 0, 7, 2, 3, 8, 0, 0, 0, 0, PetalburgCity_PokemonCenter_1F_EventScript_001FA7E1, 0x0000
	object_event 2, 65, 0, 11, 2, 3, 8, 0, 0, 0, 0, 0x08257290, 0x0000
	object_event 3, 17, 0, 2, 3, 3, 8, 0, 0, 0, 0, PetalburgCity_PokemonCenter_1F_EventScript_001FA7EF, 0x0000
	object_event 4, 35, 0, 9, 6, 3, 2, 1, 1, 0, 0, PetalburgCity_PokemonCenter_1F_EventScript_001FA7F8, 0x0000
	object_event 5, 34, 0, 5, 4, 3, 1, 1, 1, 0, 0, PetalburgCity_PokemonCenter_1F_EventScript_001FA801, 0x0000
	.globl PETALBURG_CITY_POKEMON_CENTER_1F_EventWarps
PETALBURG_CITY_POKEMON_CENTER_1F_EventWarps: @ 0x08507908
	warp_def 7, 8, 3, 3, MAP_PETALBURG_CITY
	warp_def 6, 8, 3, 3, MAP_PETALBURG_CITY
	warp_def 1, 6, 4, 0, MAP_PETALBURG_CITY_POKEMON_CENTER_2F
	.globl gMapEvents_PETALBURG_CITY_POKEMON_CENTER_1F
gMapEvents_PETALBURG_CITY_POKEMON_CENTER_1F: @ 0x08507920
	map_events PETALBURG_CITY_POKEMON_CENTER_1F_EventObjects, PETALBURG_CITY_POKEMON_CENTER_1F_EventWarps, 0, 0
	.globl PETALBURG_CITY_POKEMON_CENTER_2F_EventObjects
PETALBURG_CITY_POKEMON_CENTER_2F_EventObjects: @ 0x08507934
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 3, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	.globl PETALBURG_CITY_POKEMON_CENTER_2F_EventWarps
PETALBURG_CITY_POKEMON_CENTER_2F_EventWarps: @ 0x08507994
	warp_def 1, 6, 4, 2, MAP_PETALBURG_CITY_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_PETALBURG_CITY_POKEMON_CENTER_2F
gMapEvents_PETALBURG_CITY_POKEMON_CENTER_2F: @ 0x085079AC
	map_events PETALBURG_CITY_POKEMON_CENTER_2F_EventObjects, PETALBURG_CITY_POKEMON_CENTER_2F_EventWarps, 0, 0
	.globl PETALBURG_CITY_MART_EventObjects
PETALBURG_CITY_MART_EventObjects: @ 0x085079C0
	object_event 1, 83, 0, 1, 3, 3, 10, 0, 0, 0, 0, 0x081FA9EA, 0x0000
	object_event 2, 19, 0, 9, 4, 3, 10, 0, 0, 0, 0, 0x081FAA68, 0x0000
	object_event 3, 7, 0, 6, 3, 3, 8, 0, 0, 0, 0, 0x081FAA5F, 0x0000
	object_event 4, 20, 0, 5, 5, 3, 10, 0, 0, 0, 0, 0x081FAA56, 0x0000
	.globl PETALBURG_CITY_MART_EventWarps
PETALBURG_CITY_MART_EventWarps: @ 0x08507A20
	warp_def 3, 7, 0, 5, MAP_PETALBURG_CITY
	warp_def 4, 7, 0, 5, MAP_PETALBURG_CITY
	.globl gMapEvents_PETALBURG_CITY_MART
gMapEvents_PETALBURG_CITY_MART: @ 0x08507A30
	map_events PETALBURG_CITY_MART_EventObjects, PETALBURG_CITY_MART_EventWarps, 0, 0
	.globl SLATEPORT_CITY_STERNS_SHIPYARD_1F_EventObjects
SLATEPORT_CITY_STERNS_SHIPYARD_1F_EventObjects: @ 0x08507A44
	object_event 1, 19, 0, 5, 5, 3, 8, 0, 0, 0, 0, 0x081FAB29, 0x0000
	object_event 2, 46, 0, 10, 7, 3, 7, 0, 0, 0, 0, 0x081FABD6, 0x0000
	object_event 3, 46, 0, 18, 8, 3, 5, 1, 0, 0, 0, 0x081FABDF, 0x0000
	object_event 4, 21, 0, 12, 11, 3, 2, 1, 2, 0, 0, 0x081FABE8, 0x0365
	.globl SLATEPORT_CITY_STERNS_SHIPYARD_1F_EventWarps
SLATEPORT_CITY_STERNS_SHIPYARD_1F_EventWarps: @ 0x08507AA4
	warp_def 2, 14, 0, 2, MAP_SLATEPORT_CITY
	warp_def 3, 14, 0, 2, MAP_SLATEPORT_CITY
	warp_def 3, 1, 0, 0, MAP_SLATEPORT_CITY_STERNS_SHIPYARD_2F
	.globl gMapEvents_SLATEPORT_CITY_STERNS_SHIPYARD_1F
gMapEvents_SLATEPORT_CITY_STERNS_SHIPYARD_1F: @ 0x08507ABC
	map_events SLATEPORT_CITY_STERNS_SHIPYARD_1F_EventObjects, SLATEPORT_CITY_STERNS_SHIPYARD_1F_EventWarps, 0, 0
	.globl SLATEPORT_CITY_STERNS_SHIPYARD_2F_EventObjects
SLATEPORT_CITY_STERNS_SHIPYARD_2F_EventObjects: @ 0x08507AD0
	object_event 1, 46, 0, 10, 7, 3, 7, 0, 0, 0, 0, 0x00000000, 0x0000
	object_event 2, 46, 0, 8, 4, 3, 10, 0, 0, 0, 0, 0x081FAFA3, 0x0000
	object_event 3, 46, 0, 0, 9, 3, 7, 0, 0, 0, 0, 0x081FAFAC, 0x0000
	.globl SLATEPORT_CITY_STERNS_SHIPYARD_2F_EventWarps
SLATEPORT_CITY_STERNS_SHIPYARD_2F_EventWarps: @ 0x08507B18
	warp_def 3, 1, 0, 2, MAP_SLATEPORT_CITY_STERNS_SHIPYARD_1F
	.globl gMapEvents_SLATEPORT_CITY_STERNS_SHIPYARD_2F
gMapEvents_SLATEPORT_CITY_STERNS_SHIPYARD_2F: @ 0x08507B20
	map_events SLATEPORT_CITY_STERNS_SHIPYARD_2F_EventObjects, SLATEPORT_CITY_STERNS_SHIPYARD_2F_EventWarps, 0, 0
	.globl SLATEPORT_CITY_BATTLE_TENT_LOBBY_EventObjects
SLATEPORT_CITY_BATTLE_TENT_LOBBY_EventObjects: @ 0x08507B34
	object_event 1, 46, 0, 6, 5, 3, 8, 1, 1, 0, 0, SlateportCity_BattleTentLobby_EventScript_001FB1AD, 0x0000
	object_event 2, 49, 0, 1, 5, 3, 2, 1, 1, 0, 0, SlateportCity_BattleTentLobby_EventScript_001FB340, 0x0000
	object_event 3, 33, 0, 3, 7, 3, 7, 1, 1, 0, 0, SlateportCity_BattleTentLobby_EventScript_001FB381, 0x0000
	object_event 4, 8, 0, 1, 8, 3, 1, 1, 1, 0, 0, SlateportCity_BattleTentLobby_EventScript_001FB38A, 0x0000
	object_event 5, 20, 0, 11, 8, 3, 9, 1, 1, 0, 0, SlateportCity_BattleTentLobby_EventScript_001FB393, 0x0000
	.globl SLATEPORT_CITY_BATTLE_TENT_LOBBY_EventWarps
SLATEPORT_CITY_BATTLE_TENT_LOBBY_EventWarps: @ 0x08507BAC
	warp_def 6, 9, 0, 3, MAP_SLATEPORT_CITY
	warp_def 7, 9, 0, 3, MAP_SLATEPORT_CITY
	.globl SLATEPORT_CITY_BATTLE_TENT_LOBBY_EventBgEvents
SLATEPORT_CITY_BATTLE_TENT_LOBBY_EventBgEvents: @ 0x08507BBC
	bg_event 4, 5, 0, 0, SlateportCity_BattleTentLobby_EventScript_001FB39C, 0, 0
	.globl gMapEvents_SLATEPORT_CITY_BATTLE_TENT_LOBBY
gMapEvents_SLATEPORT_CITY_BATTLE_TENT_LOBBY: @ 0x08507BC8
	map_events SLATEPORT_CITY_BATTLE_TENT_LOBBY_EventObjects, SLATEPORT_CITY_BATTLE_TENT_LOBBY_EventWarps, 0, SLATEPORT_CITY_BATTLE_TENT_LOBBY_EventBgEvents
	.globl SLATEPORT_CITY_BATTLE_TENT_CORRIDOR_EventObjects
SLATEPORT_CITY_BATTLE_TENT_CORRIDOR_EventObjects: @ 0x08507BDC
	object_event 1, 46, 0, 2, 6, 3, 7, 1, 1, 0, 0, 0x00000000, 0x0000
	.globl gMapEvents_SLATEPORT_CITY_BATTLE_TENT_CORRIDOR
gMapEvents_SLATEPORT_CITY_BATTLE_TENT_CORRIDOR: @ 0x08507BF4
	map_events SLATEPORT_CITY_BATTLE_TENT_CORRIDOR_EventObjects, 0, 0, 0
	.globl SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM_EventObjects
SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM_EventObjects: @ 0x08507C08
	object_event 1, 46, 0, 1, 4, 0, 10, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 2, 240, 0, 5, 1, 3, 8, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 3, 241, 0, 4, 8, 3, 7, 1, 1, 0, 0, 0x00000000, 0x0000
	.globl gMapEvents_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM
gMapEvents_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM: @ 0x08507C50
	map_events SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM_EventObjects, 0, 0, 0
	.globl SLATEPORT_CITY_NAME_RATERS_HOUSE_EventObjects
SLATEPORT_CITY_NAME_RATERS_HOUSE_EventObjects: @ 0x08507C64
	object_event 1, 21, 0, 7, 5, 3, 8, 0, 0, 0, 0, 0x081FBD9E, 0x0000
	.globl SLATEPORT_CITY_NAME_RATERS_HOUSE_EventWarps
SLATEPORT_CITY_NAME_RATERS_HOUSE_EventWarps: @ 0x08507C7C
	warp_def 3, 7, 0, 6, MAP_SLATEPORT_CITY
	warp_def 4, 7, 0, 6, MAP_SLATEPORT_CITY
	.globl gMapEvents_SLATEPORT_CITY_NAME_RATERS_HOUSE
gMapEvents_SLATEPORT_CITY_NAME_RATERS_HOUSE: @ 0x08507C8C
	map_events SLATEPORT_CITY_NAME_RATERS_HOUSE_EventObjects, SLATEPORT_CITY_NAME_RATERS_HOUSE_EventWarps, 0, 0
	.globl SLATEPORT_CITY_POKEMON_FAN_CLUB_EventObjects
SLATEPORT_CITY_POKEMON_FAN_CLUB_EventObjects: @ 0x08507CA0
	object_event 1, 19, 0, 11, 4, 0, 8, 0, 0, 0, 0, 0x081FC37A, 0x0000
	object_event 2, 6, 0, 1, 5, 0, 3, 0, 1, 0, 0, 0x081FC383, 0x0000
	object_event 3, 68, 0, 11, 5, 0, 7, 0, 0, 0, 0, 0x08253D5B, 0x0000
	object_event 4, 26, 0, 6, 2, 3, 1, 0, 0, 0, 0, 0x081FC310, 0x0000
	object_event 5, 48, 0, 6, 5, 4, 8, 0, 0, 0, 0, 0x081FC028, 0x0000
	object_event 6, 208, 0, 3, 9, 3, 1, 1, 1, 0, 0, 0x081FC39F, 0x0000
	object_event 7, 203, 0, 8, 3, 3, 1, 1, 1, 0, 0, 0x081FC38C, 0x0000
	object_event 8, 210, 0, 10, 8, 3, 1, 1, 1, 0, 0, 0x081FC3B2, 0x0000
	object_event 9, 65, 0, 11, 8, 0, 9, 0, 1, 0, 0, 0x08276832, 0x0000
	.globl SLATEPORT_CITY_POKEMON_FAN_CLUB_EventWarps
SLATEPORT_CITY_POKEMON_FAN_CLUB_EventWarps: @ 0x08507D78
	warp_def 6, 10, 0, 4, MAP_SLATEPORT_CITY
	warp_def 7, 10, 0, 4, MAP_SLATEPORT_CITY
	.globl gMapEvents_SLATEPORT_CITY_POKEMON_FAN_CLUB
gMapEvents_SLATEPORT_CITY_POKEMON_FAN_CLUB: @ 0x08507D88
	map_events SLATEPORT_CITY_POKEMON_FAN_CLUB_EventObjects, SLATEPORT_CITY_POKEMON_FAN_CLUB_EventWarps, 0, 0
	.globl SLATEPORT_CITY_OCEANIC_MUSEUM_1F_EventObjects
SLATEPORT_CITY_OCEANIC_MUSEUM_1F_EventObjects: @ 0x08507D9C
	object_event 1, 45, 0, 7, 7, 3, 10, 0, 0, 0, 0, 0x081FCA3F, 0x0000
	object_event 2, 117, 0, 18, 5, 3, 7, 0, 0, 0, 0, 0x081FCB08, 0x0373
	object_event 3, 117, 0, 12, 2, 3, 7, 0, 0, 0, 0, 0x081FCB11, 0x0373
	object_event 4, 117, 0, 2, 8, 3, 7, 0, 0, 0, 0, 0x081FCAFF, 0x0373
	object_event 5, 118, 0, 3, 4, 3, 9, 0, 0, 0, 0, 0x081FCAF6, 0x0373
	object_event 6, 117, 0, 14, 4, 3, 10, 0, 0, 0, 0, 0x081FCB1A, 0x0373
	object_event 7, 45, 0, 12, 7, 3, 9, 0, 0, 0, 0, 0x081FCA3F, 0x0000
	object_event 8, 117, 0, 8, 3, 3, 8, 0, 0, 0, 0, 0x081FCB23, 0x0373
	object_event 9, 34, 0, 4, 2, 3, 1, 1, 1, 0, 0, 0x081FCB7D, 0x03C1
	object_event 10, 39, 0, 10, 2, 3, 7, 1, 1, 0, 0, 0x081FCB86, 0x03C1
	object_event 11, 25, 0, 17, 7, 3, 10, 1, 1, 0, 0, 0x081FCB8F, 0x03C1
	object_event 12, 12, 0, 18, 8, 3, 7, 1, 1, 0, 0, 0x081FCB98, 0x03C1
	object_event 13, 117, 0, 9, 4, 3, 21, 1, 1, 0, 0, 0x081FCBA1, 0x03C5
	object_event 14, 67, 0, 7, 4, 3, 1, 1, 1, 0, 0, 0x08253C9B, 0x03C1
	.globl SLATEPORT_CITY_OCEANIC_MUSEUM_1F_EventWarps
SLATEPORT_CITY_OCEANIC_MUSEUM_1F_EventWarps: @ 0x08507EEC
	warp_def 9, 8, 0, 5, MAP_SLATEPORT_CITY
	warp_def 10, 8, 0, 7, MAP_SLATEPORT_CITY
	warp_def 6, 1, 0, 0, MAP_SLATEPORT_CITY_OCEANIC_MUSEUM_2F
	.globl SLATEPORT_CITY_OCEANIC_MUSEUM_1F_EventCoordEvents
SLATEPORT_CITY_OCEANIC_MUSEUM_1F_EventCoordEvents: @ 0x08507F04
	coord_event 9, 7, 3, 16554, 0, 0x081FCA48
	coord_event 10, 7, 3, 16554, 0, 0x081FCA59
	.globl SLATEPORT_CITY_OCEANIC_MUSEUM_1F_EventBgEvents
SLATEPORT_CITY_OCEANIC_MUSEUM_1F_EventBgEvents: @ 0x08507F24
	bg_event 2, 7, 0, 0, 0x081FCB2C, 0, 0
	bg_event 2, 4, 0, 0, 0x081FCB35, 0, 0
	bg_event 9, 1, 0, 0, 0x081FCB3E, 0, 0
	bg_event 12, 1, 0, 0, 0x081FCB47, 0, 0
	bg_event 10, 1, 0, 0, 0x081FCB3E, 0, 0
	bg_event 13, 1, 0, 0, 0x081FCB47, 0, 0
	bg_event 15, 4, 0, 0, 0x081FCB50, 0, 0
	bg_event 18, 4, 0, 0, 0x081FCB59, 0, 0
	bg_event 18, 7, 0, 0, 0x081FCB62, 0, 0
	bg_event 2, 1, 0, 0, 0x081FCB6B, 0, 0
	bg_event 3, 1, 0, 0, 0x081FCB6B, 0, 0
	bg_event 16, 1, 0, 0, 0x081FCB74, 0, 0
	bg_event 17, 1, 0, 0, 0x081FCB74, 0, 0
	.globl gMapEvents_SLATEPORT_CITY_OCEANIC_MUSEUM_1F
gMapEvents_SLATEPORT_CITY_OCEANIC_MUSEUM_1F: @ 0x08507FC0
	map_events SLATEPORT_CITY_OCEANIC_MUSEUM_1F_EventObjects, SLATEPORT_CITY_OCEANIC_MUSEUM_1F_EventWarps, SLATEPORT_CITY_OCEANIC_MUSEUM_1F_EventCoordEvents, SLATEPORT_CITY_OCEANIC_MUSEUM_1F_EventBgEvents
	.globl SLATEPORT_CITY_OCEANIC_MUSEUM_2F_EventObjects
SLATEPORT_CITY_OCEANIC_MUSEUM_2F_EventObjects: @ 0x08507FD4
	object_event 1, 46, 0, 13, 6, 3, 8, 0, 0, 0, 0, 0x081FD30A, 0x0377
	object_event 2, 195, 0, 6, 1, 3, 8, 0, 0, 0, 0, 0x00000000, 0x0376
	object_event 3, 117, 0, 6, 1, 3, 8, 0, 0, 0, 0, 0x00000000, 0x0374
	object_event 4, 117, 0, 6, 1, 3, 8, 0, 0, 0, 0, 0x00000000, 0x0375
	object_event 5, 29, 0, 12, 7, 3, 10, 1, 1, 0, 0, 0x081FD56E, 0x03C1
	object_event 6, 18, 0, 9, 6, 3, 1, 1, 1, 0, 0, 0x081FD577, 0x03C1
	object_event 7, 5, 0, 1, 3, 3, 10, 1, 1, 0, 0, 0x081FD580, 0x03C1
	.globl SLATEPORT_CITY_OCEANIC_MUSEUM_2F_EventWarps
SLATEPORT_CITY_OCEANIC_MUSEUM_2F_EventWarps: @ 0x0850807C
	warp_def 6, 1, 0, 2, MAP_SLATEPORT_CITY_OCEANIC_MUSEUM_1F
	.globl SLATEPORT_CITY_OCEANIC_MUSEUM_2F_EventBgEvents
SLATEPORT_CITY_OCEANIC_MUSEUM_2F_EventBgEvents: @ 0x08508084
	bg_event 18, 4, 0, 0, 0x081FD514, 0, 0
	bg_event 18, 7, 0, 0, 0x081FD51D, 0, 0
	bg_event 4, 3, 0, 0, 0x081FD55C, 0, 0
	bg_event 4, 4, 0, 0, 0x081FD55C, 0, 0
	bg_event 3, 3, 0, 0, 0x081FD553, 0, 0
	bg_event 2, 3, 0, 0, 0x081FD553, 0, 0
	bg_event 3, 4, 0, 0, 0x081FD553, 0, 0
	bg_event 3, 6, 0, 0, 0x081FD54A, 0, 0
	bg_event 4, 6, 0, 0, 0x081FD54A, 0, 0
	bg_event 13, 7, 0, 0, 0x081FD565, 0, 0
	bg_event 14, 7, 3, 0, 0x081FD565, 0, 0
	bg_event 18, 1, 0, 0, 0x081FD541, 0, 0
	bg_event 19, 1, 0, 0, 0x081FD541, 0, 0
	bg_event 15, 1, 0, 0, 0x081FD538, 0, 0
	bg_event 16, 1, 0, 0, 0x081FD538, 0, 0
	bg_event 8, 1, 0, 0, 0x081FD52F, 0, 0
	bg_event 9, 1, 0, 0, 0x081FD52F, 0, 0
	bg_event 12, 1, 0, 0, 0x081FD526, 0, 0
	bg_event 13, 1, 0, 0, 0x081FD526, 0, 0
	bg_event 3, 7, 0, 0, 0x081FD54A, 0, 0
	bg_event 4, 7, 0, 0, 0x081FD54A, 0, 0
	.globl gMapEvents_SLATEPORT_CITY_OCEANIC_MUSEUM_2F
gMapEvents_SLATEPORT_CITY_OCEANIC_MUSEUM_2F: @ 0x08508180
	map_events SLATEPORT_CITY_OCEANIC_MUSEUM_2F_EventObjects, SLATEPORT_CITY_OCEANIC_MUSEUM_2F_EventWarps, 0, SLATEPORT_CITY_OCEANIC_MUSEUM_2F_EventBgEvents
	.globl SLATEPORT_CITY_HARBOR_EventObjects
SLATEPORT_CITY_HARBOR_EventObjects: @ 0x08508194
	object_event 1, 45, 0, 8, 10, 3, 8, 0, 0, 0, 0, SlateportCity_Harbor_EventScript_001FDDE2, 0x0389
	object_event 2, 49, 0, 4, 12, 3, 9, 0, 0, 0, 0, SlateportCity_Harbor_EventScript_001FDF43, 0x0389
	object_event 3, 17, 0, 1, 12, 3, 10, 0, 0, 0, 0, SlateportCity_Harbor_EventScript_001FDF8A, 0x0389
	object_event 4, 46, 0, 6, 13, 3, 1, 0, 0, 0, 0, SlateportCity_Harbor_EventScript_001FDF93, 0x0349
	object_event 5, 140, 0, 8, 9, 1, 10, 0, 0, 0, 0, 0x00000000, 0x035C
	object_event 6, 117, 0, 7, 10, 3, 10, 0, 0, 0, 0, 0x00000000, 0x034D
	object_event 7, 195, 0, 8, 10, 3, 9, 0, 0, 0, 0, 0x00000000, 0x034E
	object_event 8, 141, 0, 7, 9, 1, 10, 0, 0, 0, 0, 0x00000000, 0x0350
	.globl SLATEPORT_CITY_HARBOR_EventWarps
SLATEPORT_CITY_HARBOR_EventWarps: @ 0x08508254
	warp_def 11, 14, 0, 8, MAP_SLATEPORT_CITY
	warp_def 12, 14, 0, 8, MAP_SLATEPORT_CITY
	warp_def 19, 15, 0, 9, MAP_SLATEPORT_CITY
	warp_def 20, 15, 0, 9, MAP_SLATEPORT_CITY
	.globl SLATEPORT_CITY_HARBOR_EventCoordEvents
SLATEPORT_CITY_HARBOR_EventCoordEvents: @ 0x08508274
	coord_event 8, 11, 3, 16544, 1, SlateportCity_Harbor_EventScript_001FDCAC
	coord_event 8, 12, 3, 16544, 1, SlateportCity_Harbor_EventScript_001FDCB8
	coord_event 8, 13, 3, 16544, 1, SlateportCity_Harbor_EventScript_001FDCC4
	coord_event 8, 14, 3, 16544, 1, SlateportCity_Harbor_EventScript_001FDCD0
	.globl gMapEvents_SLATEPORT_CITY_HARBOR
gMapEvents_SLATEPORT_CITY_HARBOR: @ 0x085082B4
	map_events SLATEPORT_CITY_HARBOR_EventObjects, SLATEPORT_CITY_HARBOR_EventWarps, SLATEPORT_CITY_HARBOR_EventCoordEvents, 0
	.globl SLATEPORT_CITY_HOUSE_EventObjects
SLATEPORT_CITY_HOUSE_EventObjects: @ 0x085082C8
	object_event 1, 25, 0, 4, 4, 3, 10, 0, 0, 0, 0, 0x081FE773, 0x0000
	object_event 2, 14, 0, 7, 4, 3, 9, 0, 0, 0, 0, 0x081FE77C, 0x0000
	.globl SLATEPORT_CITY_HOUSE_EventWarps
SLATEPORT_CITY_HOUSE_EventWarps: @ 0x085082F8
	warp_def 3, 7, 0, 10, MAP_SLATEPORT_CITY
	warp_def 4, 7, 0, 10, MAP_SLATEPORT_CITY
	.globl gMapEvents_SLATEPORT_CITY_HOUSE
gMapEvents_SLATEPORT_CITY_HOUSE: @ 0x08508308
	map_events SLATEPORT_CITY_HOUSE_EventObjects, SLATEPORT_CITY_HOUSE_EventWarps, 0, 0
	.globl SLATEPORT_CITY_POKEMON_CENTER_1F_EventObjects
SLATEPORT_CITY_POKEMON_CENTER_1F_EventObjects: @ 0x0850831C
	object_event 1, 58, 0, 7, 2, 3, 8, 0, 0, 0, 0, SlateportCity_PokemonCenter_1F_EventScript_001FE81D, 0x0000
	object_event 2, 49, 0, 2, 3, 3, 8, 0, 0, 0, 0, SlateportCity_PokemonCenter_1F_EventScript_001FE82B, 0x0000
	object_event 3, 34, 0, 10, 7, 3, 10, 0, 0, 0, 0, SlateportCity_PokemonCenter_1F_EventScript_001FE834, 0x0000
	.globl SLATEPORT_CITY_POKEMON_CENTER_1F_EventWarps
SLATEPORT_CITY_POKEMON_CENTER_1F_EventWarps: @ 0x08508364
	warp_def 7, 8, 3, 0, MAP_SLATEPORT_CITY
	warp_def 6, 8, 3, 0, MAP_SLATEPORT_CITY
	warp_def 1, 6, 4, 0, MAP_SLATEPORT_CITY_POKEMON_CENTER_2F
	.globl gMapEvents_SLATEPORT_CITY_POKEMON_CENTER_1F
gMapEvents_SLATEPORT_CITY_POKEMON_CENTER_1F: @ 0x0850837C
	map_events SLATEPORT_CITY_POKEMON_CENTER_1F_EventObjects, SLATEPORT_CITY_POKEMON_CENTER_1F_EventWarps, 0, 0
	.globl SLATEPORT_CITY_POKEMON_CENTER_2F_EventObjects
SLATEPORT_CITY_POKEMON_CENTER_2F_EventObjects: @ 0x08508390
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 3, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	.globl SLATEPORT_CITY_POKEMON_CENTER_2F_EventWarps
SLATEPORT_CITY_POKEMON_CENTER_2F_EventWarps: @ 0x085083F0
	warp_def 1, 6, 4, 2, MAP_SLATEPORT_CITY_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_SLATEPORT_CITY_POKEMON_CENTER_2F
gMapEvents_SLATEPORT_CITY_POKEMON_CENTER_2F: @ 0x08508408
	map_events SLATEPORT_CITY_POKEMON_CENTER_2F_EventObjects, SLATEPORT_CITY_POKEMON_CENTER_2F_EventWarps, 0, 0
	.globl SLATEPORT_CITY_MART_EventObjects
SLATEPORT_CITY_MART_EventObjects: @ 0x0850841C
	object_event 1, 83, 0, 1, 3, 3, 10, 0, 0, 0, 0, 0x081FE8FA, 0x0000
	object_event 2, 44, 0, 4, 2, 3, 7, 0, 0, 0, 0, 0x081FE92A, 0x0000
	object_event 3, 33, 0, 5, 5, 3, 1, 0, 0, 0, 0, 0x081FE933, 0x0000
	.globl SLATEPORT_CITY_MART_EventWarps
SLATEPORT_CITY_MART_EventWarps: @ 0x08508464
	warp_def 3, 7, 0, 1, MAP_SLATEPORT_CITY
	warp_def 4, 7, 0, 1, MAP_SLATEPORT_CITY
	.globl gMapEvents_SLATEPORT_CITY_MART
gMapEvents_SLATEPORT_CITY_MART: @ 0x08508474
	map_events SLATEPORT_CITY_MART_EventObjects, SLATEPORT_CITY_MART_EventWarps, 0, 0
	.globl MAUVILLE_CITY_GYM_EventObjects
MAUVILLE_CITY_GYM_EventObjects: @ 0x08508488
	object_event 1, 127, 0, 5, 2, 0, 8, 0, 0, 0, 0, 0x081FEB31, 0x0391
	object_event 2, 66, 0, 7, 8, 3, 8, 0, 0, 1, 1, 0x081FED16, 0x0000
	object_event 3, 14, 0, 1, 16, 0, 7, 0, 0, 1, 2, 0x081FED44, 0x0000
	object_event 4, 35, 0, 5, 10, 0, 9, 0, 0, 1, 2, 0x081FED2D, 0x0000
	object_event 5, 66, 0, 1, 13, 0, 8, 0, 0, 1, 2, 0x081FECFF, 0x0000
	object_event 6, 23, 0, 7, 20, 0, 9, 0, 0, 0, 0, MauvilleCity_Gym_EventScript_001FED72, 0x0000
	object_event 7, 39, 0, 7, 10, 3, 7, 1, 1, 1, 1, 0x081FED5B, 0x0000
	.globl MAUVILLE_CITY_GYM_EventWarps
MAUVILLE_CITY_GYM_EventWarps: @ 0x08508530
	warp_def 4, 20, 0, 0, MAP_MAUVILLE_CITY
	warp_def 5, 20, 0, 0, MAP_MAUVILLE_CITY
	.globl MAUVILLE_CITY_GYM_EventCoordEvents
MAUVILLE_CITY_GYM_EventCoordEvents: @ 0x08508540
	coord_event 4, 12, 3, 16384, 0, MauvilleCity_Gym_EventScript_001FEC64
	coord_event 3, 9, 3, 16384, 0, MauvilleCity_Gym_EventScript_001FEC89
	coord_event 0, 15, 3, 16384, 0, MauvilleCity_Gym_EventScript_001FEC3F
	coord_event 8, 9, 3, 16384, 0, MauvilleCity_Gym_EventScript_001FECAE
	.globl MAUVILLE_CITY_GYM_EventBgEvents
MAUVILLE_CITY_GYM_EventBgEvents: @ 0x08508580
	bg_event 3, 18, 0, 1, MauvilleCity_Gym_EventScript_001FED91, 0, 0
	bg_event 6, 18, 0, 1, MauvilleCity_Gym_EventScript_001FEDA1, 0, 0
	.globl gMapEvents_MAUVILLE_CITY_GYM
gMapEvents_MAUVILLE_CITY_GYM: @ 0x08508598
	map_events MAUVILLE_CITY_GYM_EventObjects, MAUVILLE_CITY_GYM_EventWarps, MAUVILLE_CITY_GYM_EventCoordEvents, MAUVILLE_CITY_GYM_EventBgEvents
	.globl MAUVILLE_CITY_BIKE_SHOP_EventObjects
MAUVILLE_CITY_BIKE_SHOP_EventObjects: @ 0x085085AC
	object_event 1, 23, 0, 2, 5, 3, 9, 0, 0, 0, 0, 0x081FF3EC, 0x0000
	object_event 2, 66, 0, 7, 6, 3, 2, 1, 1, 0, 0, 0x081FF561, 0x0000
	.globl MAUVILLE_CITY_BIKE_SHOP_EventWarps
MAUVILLE_CITY_BIKE_SHOP_EventWarps: @ 0x085085DC
	warp_def 3, 8, 0, 2, MAP_MAUVILLE_CITY
	warp_def 4, 8, 0, 2, MAP_MAUVILLE_CITY
	.globl MAUVILLE_CITY_BIKE_SHOP_EventBgEvents
MAUVILLE_CITY_BIKE_SHOP_EventBgEvents: @ 0x085085EC
	bg_event 8, 1, 0, 0, 0x081FF56A, 0, 0
	bg_event 11, 1, 0, 0, 0x081FF5DE, 0, 0
	.globl gMapEvents_MAUVILLE_CITY_BIKE_SHOP
gMapEvents_MAUVILLE_CITY_BIKE_SHOP: @ 0x08508604
	map_events MAUVILLE_CITY_BIKE_SHOP_EventObjects, MAUVILLE_CITY_BIKE_SHOP_EventWarps, 0, MAUVILLE_CITY_BIKE_SHOP_EventBgEvents
	.globl MAUVILLE_CITY_HOUSE1_EventObjects
MAUVILLE_CITY_HOUSE1_EventObjects: @ 0x08508618
	object_event 1, 46, 0, 4, 4, 3, 10, 0, 0, 0, 0, 0x081FFD78, 0x0000
	.globl MAUVILLE_CITY_HOUSE1_EventWarps
MAUVILLE_CITY_HOUSE1_EventWarps: @ 0x08508630
	warp_def 3, 7, 0, 4, MAP_MAUVILLE_CITY
	warp_def 4, 7, 0, 4, MAP_MAUVILLE_CITY
	.globl gMapEvents_MAUVILLE_CITY_HOUSE1
gMapEvents_MAUVILLE_CITY_HOUSE1: @ 0x08508640
	map_events MAUVILLE_CITY_HOUSE1_EventObjects, MAUVILLE_CITY_HOUSE1_EventWarps, 0, 0
	.globl MAUVILLE_CITY_GAME_CORNER_EventObjects
MAUVILLE_CITY_GAME_CORNER_EventObjects: @ 0x08508654
	object_event 1, 20, 0, 12, 7, 3, 8, 0, 0, 0, 0, 0x08200454, 0x0000
	object_event 2, 48, 0, 16, 5, 3, 8, 0, 0, 0, 0, 0x0820045D, 0x0000
	object_event 3, 45, 0, 11, 2, 3, 8, 0, 0, 0, 0, 0x081FFEE8, 0x0000
	object_event 4, 45, 0, 14, 2, 3, 8, 0, 0, 0, 0, 0x08200020, 0x0000
	object_event 5, 10, 0, 7, 3, 3, 8, 0, 0, 0, 0, 0x08200466, 0x0000
	object_event 6, 25, 0, 19, 4, 3, 8, 0, 0, 0, 0, 0x0820054C, 0x0000
	object_event 7, 29, 0, 20, 8, 3, 9, 0, 0, 0, 0, 0x082005A8, 0x0000
	object_event 8, 27, 0, 6, 8, 3, 10, 0, 0, 0, 0, 0x082005B8, 0x0000
	object_event 9, 45, 0, 13, 2, 3, 8, 1, 1, 0, 0, 0x082001CE, 0x0000
	object_event 10, 33, 0, 1, 7, 3, 10, 1, 1, 0, 0, 0x082005C8, 0x0000
	object_event 11, 39, 0, 9, 8, 3, 9, 1, 1, 0, 0, 0x082005E5, 0x0000
	object_event 12, 34, 0, 4, 6, 3, 9, 1, 1, 0, 0, 0x082005F5, 0x0000
	.globl MAUVILLE_CITY_GAME_CORNER_EventWarps
MAUVILLE_CITY_GAME_CORNER_EventWarps: @ 0x08508774
	warp_def 11, 10, 3, 5, MAP_MAUVILLE_CITY
	warp_def 12, 10, 3, 5, MAP_MAUVILLE_CITY
	.globl MAUVILLE_CITY_GAME_CORNER_EventBgEvents
MAUVILLE_CITY_GAME_CORNER_EventBgEvents: @ 0x08508784
	bg_event 2, 6, 0, 3, 0x08200605, 0, 0
	bg_event 2, 8, 0, 3, 0x08200625, 0, 0
	bg_event 2, 9, 0, 3, 0x08200645, 0, 0
	bg_event 3, 7, 0, 4, 0x08200665, 0, 0
	bg_event 3, 8, 0, 4, 0x08200685, 0, 0
	bg_event 3, 9, 0, 4, 0x082006A5, 0, 0
	bg_event 7, 6, 0, 3, 0x082006C5, 0, 0
	bg_event 7, 7, 0, 3, 0x082006E5, 0, 0
	bg_event 7, 9, 0, 3, 0x08200705, 0, 0
	bg_event 8, 6, 0, 4, 0x08200725, 0, 0
	bg_event 8, 7, 0, 4, 0x08200745, 0, 0
	bg_event 8, 9, 0, 4, 0x08200765, 0, 0
	bg_event 14, 6, 0, 0, 0x08262C92, 0, 0
	bg_event 15, 6, 0, 0, 0x08262C92, 0, 0
	bg_event 14, 7, 0, 0, 0x08262C92, 0, 0
	bg_event 15, 7, 0, 0, 0x08262C92, 0, 0
	bg_event 14, 8, 0, 0, 0x08262C92, 0, 0
	bg_event 15, 8, 0, 0, 0x08262C92, 0, 0
	bg_event 18, 6, 0, 0, 0x08262CC0, 0, 0
	bg_event 19, 6, 0, 0, 0x08262CC0, 0, 0
	bg_event 18, 7, 0, 0, 0x08262CC0, 0, 0
	bg_event 19, 7, 0, 0, 0x08262CC0, 0, 0
	bg_event 18, 8, 0, 0, 0x08262CC0, 0, 0
	bg_event 19, 8, 0, 0, 0x08262CC0, 0, 0
	.globl gMapEvents_MAUVILLE_CITY_GAME_CORNER
gMapEvents_MAUVILLE_CITY_GAME_CORNER: @ 0x085088A4
	map_events MAUVILLE_CITY_GAME_CORNER_EventObjects, MAUVILLE_CITY_GAME_CORNER_EventWarps, 0, MAUVILLE_CITY_GAME_CORNER_EventBgEvents
	.globl MAUVILLE_CITY_HOUSE2_EventObjects
MAUVILLE_CITY_HOUSE2_EventObjects: @ 0x085088B8
	object_event 1, 24, 0, 4, 5, 3, 9, 0, 0, 0, 0, 0x08200C5B, 0x0000
	.globl MAUVILLE_CITY_HOUSE2_EventWarps
MAUVILLE_CITY_HOUSE2_EventWarps: @ 0x085088D0
	warp_def 3, 8, 0, 6, MAP_MAUVILLE_CITY
	warp_def 4, 8, 0, 6, MAP_MAUVILLE_CITY
	.globl gMapEvents_MAUVILLE_CITY_HOUSE2
gMapEvents_MAUVILLE_CITY_HOUSE2: @ 0x085088E0
	map_events MAUVILLE_CITY_HOUSE2_EventObjects, MAUVILLE_CITY_HOUSE2_EventWarps, 0, 0
	.globl MAUVILLE_CITY_POKEMON_CENTER_1F_EventObjects
MAUVILLE_CITY_POKEMON_CENTER_1F_EventObjects: @ 0x085088F4
	object_event 1, 58, 0, 7, 2, 3, 8, 0, 0, 0, 0, MauvilleCity_PokemonCenter_1F_EventScript_00200DF1, 0x0000
	object_event 2, 240, 0, 2, 3, 3, 9, 1, 0, 0, 0, 0x08254D6B, 0x0000
	object_event 3, 16, 0, 8, 6, 3, 1, 0, 0, 0, 0, MauvilleCity_PokemonCenter_1F_EventScript_00200DFF, 0x0000
	object_event 4, 34, 0, 11, 4, 3, 3, 0, 1, 0, 0, MauvilleCity_PokemonCenter_1F_EventScript_00200E08, 0x0000
	object_event 5, 35, 0, 2, 8, 3, 1, 1, 1, 0, 0, MauvilleCity_PokemonCenter_1F_EventScript_00200E11, 0x0000
	.globl MAUVILLE_CITY_POKEMON_CENTER_1F_EventWarps
MAUVILLE_CITY_POKEMON_CENTER_1F_EventWarps: @ 0x0850896C
	warp_def 7, 8, 3, 1, MAP_MAUVILLE_CITY
	warp_def 6, 8, 3, 1, MAP_MAUVILLE_CITY
	warp_def 1, 6, 4, 0, MAP_MAUVILLE_CITY_POKEMON_CENTER_2F
	.globl gMapEvents_MAUVILLE_CITY_POKEMON_CENTER_1F
gMapEvents_MAUVILLE_CITY_POKEMON_CENTER_1F: @ 0x08508984
	map_events MAUVILLE_CITY_POKEMON_CENTER_1F_EventObjects, MAUVILLE_CITY_POKEMON_CENTER_1F_EventWarps, 0, 0
	.globl MAUVILLE_CITY_POKEMON_CENTER_2F_EventObjects
MAUVILLE_CITY_POKEMON_CENTER_2F_EventObjects: @ 0x08508998
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 3, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	object_event 5, 35, 0, 8, 8, 3, 7, 1, 1, 0, 0, MauvilleCity_PokemonCenter_2F_EventScript_00200EF6, 0x0000
	.globl MAUVILLE_CITY_POKEMON_CENTER_2F_EventWarps
MAUVILLE_CITY_POKEMON_CENTER_2F_EventWarps: @ 0x08508A10
	warp_def 1, 6, 4, 2, MAP_MAUVILLE_CITY_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_MAUVILLE_CITY_POKEMON_CENTER_2F
gMapEvents_MAUVILLE_CITY_POKEMON_CENTER_2F: @ 0x08508A28
	map_events MAUVILLE_CITY_POKEMON_CENTER_2F_EventObjects, MAUVILLE_CITY_POKEMON_CENTER_2F_EventWarps, 0, 0
	.globl MAUVILLE_CITY_MART_EventObjects
MAUVILLE_CITY_MART_EventObjects: @ 0x08508A3C
	object_event 1, 83, 0, 1, 3, 3, 10, 0, 0, 0, 0, 0x08200F50, 0x0000
	object_event 2, 21, 0, 5, 4, 3, 10, 0, 0, 0, 0, 0x08200F84, 0x0000
	object_event 3, 33, 0, 5, 5, 3, 10, 0, 0, 0, 0, 0x08200F8D, 0x0000
	.globl MAUVILLE_CITY_MART_EventWarps
MAUVILLE_CITY_MART_EventWarps: @ 0x08508A84
	warp_def 3, 7, 0, 3, MAP_MAUVILLE_CITY
	warp_def 4, 7, 0, 3, MAP_MAUVILLE_CITY
	.globl gMapEvents_MAUVILLE_CITY_MART
gMapEvents_MAUVILLE_CITY_MART: @ 0x08508A94
	map_events MAUVILLE_CITY_MART_EventObjects, MAUVILLE_CITY_MART_EventWarps, 0, 0
	.globl RUSTBORO_CITY_DEVON_CORP_1F_EventObjects
RUSTBORO_CITY_DEVON_CORP_1F_EventObjects: @ 0x08508AA8
	object_event 1, 116, 0, 2, 6, 3, 2, 1, 1, 0, 0, RustboroCity_DevonCorp_1F_EventScript_0020104C, 0x0000
	object_event 2, 116, 0, 15, 5, 3, 2, 2, 1, 0, 0, RustboroCity_DevonCorp_1F_EventScript_0020107E, 0x0000
	object_event 3, 24, 0, 5, 3, 3, 8, 0, 0, 0, 0, RustboroCity_DevonCorp_1F_EventScript_002010B9, 0x0000
	.globl RUSTBORO_CITY_DEVON_CORP_1F_EventWarps
RUSTBORO_CITY_DEVON_CORP_1F_EventWarps: @ 0x08508AF0
	warp_def 5, 8, 0, 5, MAP_RUSTBORO_CITY
	warp_def 6, 8, 0, 6, MAP_RUSTBORO_CITY
	warp_def 14, 1, 0, 0, MAP_RUSTBORO_CITY_DEVON_CORP_2F
	.globl RUSTBORO_CITY_DEVON_CORP_1F_EventBgEvents
RUSTBORO_CITY_DEVON_CORP_1F_EventBgEvents: @ 0x08508B08
	bg_event 3, 2, 0, 0, RustboroCity_DevonCorp_1F_EventScript_002010FD, 0, 0
	bg_event 8, 2, 0, 0, RustboroCity_DevonCorp_1F_EventScript_002010F4, 0, 0
	.globl gMapEvents_RUSTBORO_CITY_DEVON_CORP_1F
gMapEvents_RUSTBORO_CITY_DEVON_CORP_1F: @ 0x08508B20
	map_events RUSTBORO_CITY_DEVON_CORP_1F_EventObjects, RUSTBORO_CITY_DEVON_CORP_1F_EventWarps, 0, RUSTBORO_CITY_DEVON_CORP_1F_EventBgEvents
	.globl RUSTBORO_CITY_DEVON_CORP_2F_EventObjects
RUSTBORO_CITY_DEVON_CORP_2F_EventObjects: @ 0x08508B34
	object_event 1, 46, 0, 6, 5, 3, 7, 0, 0, 0, 0, RustboroCity_DevonCorp_2F_EventScript_00201441, 0x0000
	object_event 2, 46, 0, 1, 5, 3, 10, 0, 0, 0, 0, RustboroCity_DevonCorp_2F_EventScript_00201458, 0x0000
	object_event 3, 46, 0, 2, 6, 3, 15, 0, 0, 0, 0, RustboroCity_DevonCorp_2F_EventScript_00201482, 0x0000
	object_event 4, 46, 0, 10, 5, 3, 7, 0, 10, 0, 0, RustboroCity_DevonCorp_2F_EventScript_002014AC, 0x0000
	object_event 5, 46, 0, 14, 8, 3, 7, 1, 1, 0, 0, RustboroCity_DevonCorp_2F_EventScript_002014C3, 0x0000
	object_event 6, 46, 0, 14, 5, 3, 7, 1, 1, 0, 0, RustboroCity_DevonCorp_2F_EventScript_002017A1, 0x0000
	.globl RUSTBORO_CITY_DEVON_CORP_2F_EventWarps
RUSTBORO_CITY_DEVON_CORP_2F_EventWarps: @ 0x08508BC4
	warp_def 14, 1, 0, 2, MAP_RUSTBORO_CITY_DEVON_CORP_1F
	warp_def 2, 1, 0, 0, MAP_RUSTBORO_CITY_DEVON_CORP_3F
	.globl gMapEvents_RUSTBORO_CITY_DEVON_CORP_2F
gMapEvents_RUSTBORO_CITY_DEVON_CORP_2F: @ 0x08508BD4
	map_events RUSTBORO_CITY_DEVON_CORP_2F_EventObjects, RUSTBORO_CITY_DEVON_CORP_2F_EventWarps, 0, 0
	.globl RUSTBORO_CITY_DEVON_CORP_3F_EventObjects
RUSTBORO_CITY_DEVON_CORP_3F_EventObjects: @ 0x08508BE8
	object_event 1, 48, 0, 17, 5, 3, 9, 0, 0, 0, 0, RustboroCity_DevonCorp_3F_EventScript_00201D68, 0x0000
	object_event 2, 23, 0, 3, 5, 3, 10, 0, 0, 0, 0, RustboroCity_DevonCorp_3F_EventScript_00201DDD, 0x03B5
	object_event 3, 48, 0, 15, 5, 3, 76, 1, 1, 0, 0, RustboroCity_DevonCorp_3F_EventScript_00201D68, 0x0000
	.globl RUSTBORO_CITY_DEVON_CORP_3F_EventWarps
RUSTBORO_CITY_DEVON_CORP_3F_EventWarps: @ 0x08508C30
	warp_def 2, 1, 0, 1, MAP_RUSTBORO_CITY_DEVON_CORP_2F
	.globl RUSTBORO_CITY_DEVON_CORP_3F_EventBgEvents
RUSTBORO_CITY_DEVON_CORP_3F_EventBgEvents: @ 0x08508C38
	bg_event 1, 5, 3, 0, RustboroCity_DevonCorp_3F_EventScript_00201DFC, 0, 0
	bg_event 1, 7, 3, 0, RustboroCity_DevonCorp_3F_EventScript_00201DFC, 0, 0
	.globl gMapEvents_RUSTBORO_CITY_DEVON_CORP_3F
gMapEvents_RUSTBORO_CITY_DEVON_CORP_3F: @ 0x08508C50
	map_events RUSTBORO_CITY_DEVON_CORP_3F_EventObjects, RUSTBORO_CITY_DEVON_CORP_3F_EventWarps, 0, RUSTBORO_CITY_DEVON_CORP_3F_EventBgEvents
	.globl RUSTBORO_CITY_GYM_EventObjects
RUSTBORO_CITY_GYM_EventObjects: @ 0x08508C64
	object_event 1, 125, 0, 5, 2, 3, 8, 0, 0, 0, 0, 0x082022C6, 0x0000
	object_event 2, 35, 0, 5, 13, 3, 8, 0, 0, 1, 2, 0x08202378, 0x0000
	object_event 3, 35, 0, 3, 9, 3, 9, 0, 0, 1, 3, 0x0820238F, 0x0000
	object_event 4, 23, 0, 3, 18, 3, 8, 0, 0, 0, 0, 0x082023BD, 0x0000
	object_event 5, 55, 0, 1, 6, 3, 8, 1, 1, 1, 3, 0x082023A6, 0x0000
	.globl RUSTBORO_CITY_GYM_EventWarps
RUSTBORO_CITY_GYM_EventWarps: @ 0x08508CDC
	warp_def 5, 19, 0, 0, MAP_RUSTBORO_CITY
	warp_def 6, 19, 0, 0, MAP_RUSTBORO_CITY
	.globl RUSTBORO_CITY_GYM_EventBgEvents
RUSTBORO_CITY_GYM_EventBgEvents: @ 0x08508CEC
	bg_event 2, 18, 0, 1, 0x082023DC, 0, 0
	bg_event 8, 18, 0, 1, 0x082023EC, 0, 0
	.globl gMapEvents_RUSTBORO_CITY_GYM
gMapEvents_RUSTBORO_CITY_GYM: @ 0x08508D04
	map_events RUSTBORO_CITY_GYM_EventObjects, RUSTBORO_CITY_GYM_EventWarps, 0, RUSTBORO_CITY_GYM_EventBgEvents
	.globl RUSTBORO_CITY_POKEMON_SCHOOL_EventObjects
RUSTBORO_CITY_POKEMON_SCHOOL_EventObjects: @ 0x08508D18
	object_event 1, 189, 0, 8, 6, 3, 10, 0, 0, 0, 0, 0x08202CD1, 0x0000
	object_event 2, 189, 0, 9, 6, 3, 9, 0, 0, 0, 0, 0x08202CDA, 0x0000
	object_event 3, 15, 0, 3, 8, 3, 7, 0, 0, 0, 0, 0x08202CE3, 0x0000
	object_event 4, 47, 0, 10, 8, 3, 7, 0, 0, 0, 0, 0x08202CEC, 0x0000
	object_event 5, 38, 0, 3, 6, 3, 8, 0, 0, 0, 0, 0x08202CF5, 0x0000
	object_event 6, 48, 0, 5, 3, 3, 8, 1, 1, 0, 0, 0x08202D07, 0x0000
	object_event 7, 219, 0, 0, 10, 0, 7, 1, 1, 0, 0, 0x08202DB2, 0x03E7
	.globl RUSTBORO_CITY_POKEMON_SCHOOL_EventWarps
RUSTBORO_CITY_POKEMON_SCHOOL_EventWarps: @ 0x08508DC0
	warp_def 5, 10, 0, 4, MAP_RUSTBORO_CITY
	warp_def 6, 10, 0, 4, MAP_RUSTBORO_CITY
	.globl RUSTBORO_CITY_POKEMON_SCHOOL_EventBgEvents
RUSTBORO_CITY_POKEMON_SCHOOL_EventBgEvents: @ 0x08508DD0
	bg_event 5, 2, 0, 0, 0x08202C1B, 0, 0
	bg_event 4, 2, 0, 0, 0x08202C1B, 0, 0
	bg_event 6, 2, 0, 0, 0x08202C1B, 0, 0
	bg_event 7, 2, 0, 0, 0x08202C1B, 0, 0
	bg_event 3, 5, 0, 0, 0x08202CFE, 0, 0
	.globl gMapEvents_RUSTBORO_CITY_POKEMON_SCHOOL
gMapEvents_RUSTBORO_CITY_POKEMON_SCHOOL: @ 0x08508E0C
	map_events RUSTBORO_CITY_POKEMON_SCHOOL_EventObjects, RUSTBORO_CITY_POKEMON_SCHOOL_EventWarps, 0, RUSTBORO_CITY_POKEMON_SCHOOL_EventBgEvents
	.globl RUSTBORO_CITY_POKEMON_CENTER_1F_EventObjects
RUSTBORO_CITY_POKEMON_CENTER_1F_EventObjects: @ 0x08508E20
	object_event 1, 58, 0, 7, 2, 3, 8, 0, 0, 0, 0, RustboroCity_PokemonCenter_1F_EventScript_002034C7, 0x0000
	object_event 2, 19, 0, 11, 2, 3, 9, 0, 0, 0, 0, RustboroCity_PokemonCenter_1F_EventScript_002034D5, 0x0000
	object_event 3, 7, 0, 3, 4, 3, 2, 1, 1, 0, 0, RustboroCity_PokemonCenter_1F_EventScript_002034DE, 0x0000
	object_event 4, 14, 0, 10, 6, 3, 10, 0, 0, 0, 0, RustboroCity_PokemonCenter_1F_EventScript_002034E7, 0x0000
	.globl RUSTBORO_CITY_POKEMON_CENTER_1F_EventWarps
RUSTBORO_CITY_POKEMON_CENTER_1F_EventWarps: @ 0x08508E80
	warp_def 7, 8, 3, 3, MAP_RUSTBORO_CITY
	warp_def 6, 8, 3, 3, MAP_RUSTBORO_CITY
	warp_def 1, 6, 4, 0, MAP_RUSTBORO_CITY_POKEMON_CENTER_2F
	.globl gMapEvents_RUSTBORO_CITY_POKEMON_CENTER_1F
gMapEvents_RUSTBORO_CITY_POKEMON_CENTER_1F: @ 0x08508E98
	map_events RUSTBORO_CITY_POKEMON_CENTER_1F_EventObjects, RUSTBORO_CITY_POKEMON_CENTER_1F_EventWarps, 0, 0
	.globl RUSTBORO_CITY_POKEMON_CENTER_2F_EventObjects
RUSTBORO_CITY_POKEMON_CENTER_2F_EventObjects: @ 0x08508EAC
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 3, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	.globl RUSTBORO_CITY_POKEMON_CENTER_2F_EventWarps
RUSTBORO_CITY_POKEMON_CENTER_2F_EventWarps: @ 0x08508F0C
	warp_def 1, 6, 4, 2, MAP_RUSTBORO_CITY_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_RUSTBORO_CITY_POKEMON_CENTER_2F
gMapEvents_RUSTBORO_CITY_POKEMON_CENTER_2F: @ 0x08508F24
	map_events RUSTBORO_CITY_POKEMON_CENTER_2F_EventObjects, RUSTBORO_CITY_POKEMON_CENTER_2F_EventWarps, 0, 0
	.globl RUSTBORO_CITY_MART_EventObjects
RUSTBORO_CITY_MART_EventObjects: @ 0x08508F38
	object_event 1, 83, 0, 1, 3, 3, 10, 0, 0, 0, 0, 0x082035E1, 0x0000
	object_event 2, 7, 0, 2, 5, 3, 7, 0, 0, 0, 0, 0x08203659, 0x0000
	object_event 3, 18, 0, 8, 4, 3, 3, 0, 1, 0, 0, 0x08203650, 0x0000
	object_event 4, 36, 0, 8, 2, 3, 7, 1, 1, 0, 0, 0x08203662, 0x0000
	.globl RUSTBORO_CITY_MART_EventWarps
RUSTBORO_CITY_MART_EventWarps: @ 0x08508F98
	warp_def 3, 7, 0, 2, MAP_RUSTBORO_CITY
	warp_def 4, 7, 0, 2, MAP_RUSTBORO_CITY
	.globl gMapEvents_RUSTBORO_CITY_MART
gMapEvents_RUSTBORO_CITY_MART: @ 0x08508FA8
	map_events RUSTBORO_CITY_MART_EventObjects, RUSTBORO_CITY_MART_EventWarps, 0, 0
	.globl RUSTBORO_CITY_FLAT1_1F_EventObjects
RUSTBORO_CITY_FLAT1_1F_EventObjects: @ 0x08508FBC
	object_event 1, 33, 0, 9, 4, 3, 10, 0, 0, 0, 0, 0x08203715, 0x0000
	object_event 2, 34, 0, 12, 4, 3, 9, 0, 0, 0, 0, 0x0820371E, 0x0000
	.globl RUSTBORO_CITY_FLAT1_1F_EventWarps
RUSTBORO_CITY_FLAT1_1F_EventWarps: @ 0x08508FEC
	warp_def 6, 7, 0, 1, MAP_RUSTBORO_CITY
	warp_def 7, 7, 0, 1, MAP_RUSTBORO_CITY
	warp_def 2, 1, 0, 0, MAP_RUSTBORO_CITY_FLAT1_2F
	.globl gMapEvents_RUSTBORO_CITY_FLAT1_1F
gMapEvents_RUSTBORO_CITY_FLAT1_1F: @ 0x08509004
	map_events RUSTBORO_CITY_FLAT1_1F_EventObjects, RUSTBORO_CITY_FLAT1_1F_EventWarps, 0, 0
	.globl RUSTBORO_CITY_FLAT1_2F_EventObjects
RUSTBORO_CITY_FLAT1_2F_EventObjects: @ 0x08509018
	object_event 1, 18, 0, 4, 6, 3, 5, 3, 1, 0, 0, 0x08203874, 0x0000
	object_event 2, 6, 0, 9, 5, 3, 8, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 3, 162, 0, 9, 4, 3, 1, 1, 1, 0, 0, 0x0820387D, 0x0000
	object_event 4, 154, 0, 10, 5, 3, 1, 1, 1, 0, 0, 0x0820387D, 0x0000
	object_event 5, 155, 0, 10, 6, 3, 1, 1, 1, 0, 0, 0x0820387D, 0x0000
	object_event 6, 19, 0, 8, 5, 3, 10, 1, 1, 0, 0, 0x08203771, 0x0000
	object_event 7, 156, 0, 8, 6, 3, 1, 1, 1, 0, 0, 0x0820387D, 0x0000
	object_event 8, 143, 0, 9, 7, 3, 1, 1, 1, 0, 0, 0x0820387D, 0x0000
	.globl RUSTBORO_CITY_FLAT1_2F_EventWarps
RUSTBORO_CITY_FLAT1_2F_EventWarps: @ 0x085090D8
	warp_def 2, 1, 0, 2, MAP_RUSTBORO_CITY_FLAT1_1F
	.globl gMapEvents_RUSTBORO_CITY_FLAT1_2F
gMapEvents_RUSTBORO_CITY_FLAT1_2F: @ 0x085090E0
	map_events RUSTBORO_CITY_FLAT1_2F_EventObjects, RUSTBORO_CITY_FLAT1_2F_EventWarps, 0, 0
	.globl RUSTBORO_CITY_HOUSE1_EventObjects
RUSTBORO_CITY_HOUSE1_EventObjects: @ 0x085090F4
	object_event 1, 31, 0, 6, 4, 3, 9, 0, 0, 0, 0, 0x08203BC9, 0x0000
	object_event 2, 55, 0, 9, 2, 3, 8, 0, 0, 0, 0, 0x08203C69, 0x0000
	.globl RUSTBORO_CITY_HOUSE1_EventWarps
RUSTBORO_CITY_HOUSE1_EventWarps: @ 0x08509124
	warp_def 5, 7, 0, 7, MAP_RUSTBORO_CITY
	warp_def 6, 7, 0, 7, MAP_RUSTBORO_CITY
	.globl gMapEvents_RUSTBORO_CITY_HOUSE1
gMapEvents_RUSTBORO_CITY_HOUSE1: @ 0x08509134
	map_events RUSTBORO_CITY_HOUSE1_EventObjects, RUSTBORO_CITY_HOUSE1_EventWarps, 0, 0
	.globl RUSTBORO_CITY_CUTTERS_HOUSE_EventObjects
RUSTBORO_CITY_CUTTERS_HOUSE_EventObjects: @ 0x08509148
	object_event 1, 25, 0, 7, 5, 3, 10, 0, 0, 0, 0, 0x08203D7D, 0x0000
	object_event 2, 47, 0, 9, 2, 3, 5, 1, 0, 0, 0, 0x08203DB3, 0x0000
	.globl RUSTBORO_CITY_CUTTERS_HOUSE_EventWarps
RUSTBORO_CITY_CUTTERS_HOUSE_EventWarps: @ 0x08509178
	warp_def 5, 8, 0, 8, MAP_RUSTBORO_CITY
	warp_def 6, 8, 0, 8, MAP_RUSTBORO_CITY
	.globl gMapEvents_RUSTBORO_CITY_CUTTERS_HOUSE
gMapEvents_RUSTBORO_CITY_CUTTERS_HOUSE: @ 0x08509188
	map_events RUSTBORO_CITY_CUTTERS_HOUSE_EventObjects, RUSTBORO_CITY_CUTTERS_HOUSE_EventWarps, 0, 0
	.globl RUSTBORO_CITY_HOUSE2_EventObjects
RUSTBORO_CITY_HOUSE2_EventObjects: @ 0x0850919C
	object_event 1, 18, 0, 4, 4, 3, 8, 0, 0, 0, 0, 0x08203F16, 0x0000
	object_event 2, 12, 0, 4, 5, 3, 7, 0, 0, 0, 0, 0x08203F1F, 0x0000
	.globl RUSTBORO_CITY_HOUSE2_EventWarps
RUSTBORO_CITY_HOUSE2_EventWarps: @ 0x085091CC
	warp_def 5, 8, 0, 9, MAP_RUSTBORO_CITY
	warp_def 6, 8, 0, 9, MAP_RUSTBORO_CITY
	.globl gMapEvents_RUSTBORO_CITY_HOUSE2
gMapEvents_RUSTBORO_CITY_HOUSE2: @ 0x085091DC
	map_events RUSTBORO_CITY_HOUSE2_EventObjects, RUSTBORO_CITY_HOUSE2_EventWarps, 0, 0
	.globl RUSTBORO_CITY_FLAT2_1F_EventObjects
RUSTBORO_CITY_FLAT2_1F_EventObjects: @ 0x085091F0
	object_event 1, 203, 0, 11, 4, 3, 9, 0, 0, 0, 0, 0x08203FA3, 0x0000
	object_event 2, 30, 0, 8, 4, 3, 10, 0, 0, 0, 0, 0x08203F9A, 0x0000
	.globl RUSTBORO_CITY_FLAT2_1F_EventWarps
RUSTBORO_CITY_FLAT2_1F_EventWarps: @ 0x08509220
	warp_def 2, 8, 0, 10, MAP_RUSTBORO_CITY
	warp_def 3, 8, 0, 10, MAP_RUSTBORO_CITY
	warp_def 3, 1, 0, 0, MAP_RUSTBORO_CITY_FLAT2_2F
	.globl gMapEvents_RUSTBORO_CITY_FLAT2_1F
gMapEvents_RUSTBORO_CITY_FLAT2_1F: @ 0x08509238
	map_events RUSTBORO_CITY_FLAT2_1F_EventObjects, RUSTBORO_CITY_FLAT2_1F_EventWarps, 0, 0
	.globl RUSTBORO_CITY_FLAT2_2F_EventObjects
RUSTBORO_CITY_FLAT2_2F_EventObjects: @ 0x0850924C
	object_event 1, 29, 0, 11, 4, 3, 10, 0, 0, 0, 0, 0x08203FE9, 0x0000
	object_event 2, 5, 0, 7, 3, 3, 5, 2, 0, 0, 0, 0x08203FF2, 0x0000
	.globl RUSTBORO_CITY_FLAT2_2F_EventWarps
RUSTBORO_CITY_FLAT2_2F_EventWarps: @ 0x0850927C
	warp_def 3, 1, 0, 2, MAP_RUSTBORO_CITY_FLAT2_1F
	warp_def 1, 1, 0, 0, MAP_RUSTBORO_CITY_FLAT2_3F
	.globl gMapEvents_RUSTBORO_CITY_FLAT2_2F
gMapEvents_RUSTBORO_CITY_FLAT2_2F: @ 0x0850928C
	map_events RUSTBORO_CITY_FLAT2_2F_EventObjects, RUSTBORO_CITY_FLAT2_2F_EventWarps, 0, 0
	.globl RUSTBORO_CITY_FLAT2_3F_EventObjects
RUSTBORO_CITY_FLAT2_3F_EventObjects: @ 0x085092A0
	object_event 1, 116, 0, 7, 3, 3, 5, 2, 0, 0, 0, 0x082040B6, 0x0000
	object_event 2, 16, 0, 12, 2, 3, 8, 0, 0, 0, 0, 0x082040BF, 0x0000
	.globl RUSTBORO_CITY_FLAT2_3F_EventWarps
RUSTBORO_CITY_FLAT2_3F_EventWarps: @ 0x085092D0
	warp_def 1, 1, 0, 1, MAP_RUSTBORO_CITY_FLAT2_2F
	.globl gMapEvents_RUSTBORO_CITY_FLAT2_3F
gMapEvents_RUSTBORO_CITY_FLAT2_3F: @ 0x085092D8
	map_events RUSTBORO_CITY_FLAT2_3F_EventObjects, RUSTBORO_CITY_FLAT2_3F_EventWarps, 0, 0
	.globl RUSTBORO_CITY_HOUSE3_EventObjects
RUSTBORO_CITY_HOUSE3_EventObjects: @ 0x085092EC
	object_event 1, 29, 0, 4, 5, 3, 10, 0, 0, 0, 0, 0x08204118, 0x0000
	object_event 2, 30, 0, 7, 5, 3, 9, 0, 0, 0, 0, 0x08204121, 0x0000
	object_event 3, 209, 0, 4, 4, 3, 8, 0, 0, 0, 0, 0x0820412A, 0x0000
	.globl RUSTBORO_CITY_HOUSE3_EventWarps
RUSTBORO_CITY_HOUSE3_EventWarps: @ 0x08509334
	warp_def 5, 8, 0, 11, MAP_RUSTBORO_CITY
	warp_def 6, 8, 0, 11, MAP_RUSTBORO_CITY
	.globl gMapEvents_RUSTBORO_CITY_HOUSE3
gMapEvents_RUSTBORO_CITY_HOUSE3: @ 0x08509344
	map_events RUSTBORO_CITY_HOUSE3_EventObjects, RUSTBORO_CITY_HOUSE3_EventWarps, 0, 0
	.globl FORTREE_CITY_HOUSE1_EventObjects
FORTREE_CITY_HOUSE1_EventObjects: @ 0x08509358
	object_event 1, 5, 0, 1, 3, 3, 10, 0, 0, 0, 0, 0x082041CB, 0x0000
	object_event 2, 208, 0, 2, 3, 3, 9, 0, 0, 0, 0, 0x08204278, 0x0000
	object_event 3, 22, 0, 7, 4, 3, 1, 1, 1, 0, 0, 0x0820426F, 0x0000
	.globl FORTREE_CITY_HOUSE1_EventWarps
FORTREE_CITY_HOUSE1_EventWarps: @ 0x085093A0
	warp_def 3, 5, 0, 1, MAP_FORTREE_CITY
	warp_def 4, 5, 0, 1, MAP_FORTREE_CITY
	.globl gMapEvents_FORTREE_CITY_HOUSE1
gMapEvents_FORTREE_CITY_HOUSE1: @ 0x085093B0
	map_events FORTREE_CITY_HOUSE1_EventObjects, FORTREE_CITY_HOUSE1_EventWarps, 0, 0
	.globl FORTREE_CITY_GYM_EventObjects
FORTREE_CITY_GYM_EventObjects: @ 0x085093C4
	object_event 1, 130, 0, 15, 2, 3, 8, 0, 0, 0, 0, 0x082043BB, 0x0000
	object_event 2, 66, 0, 4, 14, 3, 8, 0, 0, 1, 3, 0x0820449B, 0x0000
	object_event 3, 31, 0, 10, 10, 3, 9, 0, 0, 1, 2, 0x082044C9, 0x0000
	object_event 4, 32, 0, 5, 17, 3, 9, 0, 0, 1, 1, 0x082044E0, 0x0000
	object_event 5, 66, 0, 9, 8, 3, 8, 0, 0, 1, 2, 0x082044B2, 0x0000
	object_event 6, 23, 0, 15, 21, 3, 8, 0, 0, 0, 0, FortreeCity_Gym_EventScript_00204525, 0x0000
	object_event 7, 66, 0, 4, 23, 3, 10, 1, 1, 1, 1, 0x082044F7, 0x0000
	object_event 8, 66, 0, 1, 10, 3, 7, 1, 1, 1, 3, 0x0820450E, 0x0000
	.globl FORTREE_CITY_GYM_EventWarps
FORTREE_CITY_GYM_EventWarps: @ 0x08509484
	warp_def 15, 24, 0, 2, MAP_FORTREE_CITY
	warp_def 16, 24, 0, 2, MAP_FORTREE_CITY
	.globl FORTREE_CITY_GYM_EventBgEvents
FORTREE_CITY_GYM_EventBgEvents: @ 0x08509494
	bg_event 14, 21, 0, 1, FortreeCity_Gym_EventScript_00204544, 0, 0
	bg_event 17, 21, 0, 1, FortreeCity_Gym_EventScript_00204554, 0, 0
	.globl gMapEvents_FORTREE_CITY_GYM
gMapEvents_FORTREE_CITY_GYM: @ 0x085094AC
	map_events FORTREE_CITY_GYM_EventObjects, FORTREE_CITY_GYM_EventWarps, 0, FORTREE_CITY_GYM_EventBgEvents
	.globl FORTREE_CITY_POKEMON_CENTER_1F_EventObjects
FORTREE_CITY_POKEMON_CENTER_1F_EventObjects: @ 0x085094C0
	object_event 1, 58, 0, 7, 2, 3, 8, 0, 0, 0, 0, FortreeCity_PokemonCenter_1F_EventScript_00204C6C, 0x0000
	object_event 2, 48, 0, 4, 7, 3, 1, 0, 0, 0, 0, FortreeCity_PokemonCenter_1F_EventScript_00204C7A, 0x0000
	object_event 3, 33, 0, 8, 5, 3, 1, 0, 0, 0, 0, FortreeCity_PokemonCenter_1F_EventScript_00204C83, 0x0000
	object_event 4, 13, 0, 2, 3, 3, 8, 1, 1, 0, 0, FortreeCity_PokemonCenter_1F_EventScript_00204C8C, 0x0000
	.globl FORTREE_CITY_POKEMON_CENTER_1F_EventWarps
FORTREE_CITY_POKEMON_CENTER_1F_EventWarps: @ 0x08509520
	warp_def 7, 8, 3, 0, MAP_FORTREE_CITY
	warp_def 6, 8, 3, 0, MAP_FORTREE_CITY
	warp_def 1, 6, 4, 0, MAP_FORTREE_CITY_POKEMON_CENTER_2F
	.globl gMapEvents_FORTREE_CITY_POKEMON_CENTER_1F
gMapEvents_FORTREE_CITY_POKEMON_CENTER_1F: @ 0x08509538
	map_events FORTREE_CITY_POKEMON_CENTER_1F_EventObjects, FORTREE_CITY_POKEMON_CENTER_1F_EventWarps, 0, 0
	.globl FORTREE_CITY_POKEMON_CENTER_2F_EventObjects
FORTREE_CITY_POKEMON_CENTER_2F_EventObjects: @ 0x0850954C
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 3, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	.globl FORTREE_CITY_POKEMON_CENTER_2F_EventWarps
FORTREE_CITY_POKEMON_CENTER_2F_EventWarps: @ 0x085095AC
	warp_def 1, 6, 4, 2, MAP_FORTREE_CITY_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_FORTREE_CITY_POKEMON_CENTER_2F
gMapEvents_FORTREE_CITY_POKEMON_CENTER_2F: @ 0x085095C4
	map_events FORTREE_CITY_POKEMON_CENTER_2F_EventObjects, FORTREE_CITY_POKEMON_CENTER_2F_EventWarps, 0, 0
	.globl FORTREE_CITY_MART_EventObjects
FORTREE_CITY_MART_EventObjects: @ 0x085095D8
	object_event 1, 83, 0, 1, 3, 3, 10, 0, 0, 0, 0, 0x08204DBE, 0x0000
	object_event 2, 20, 0, 9, 3, 3, 7, 0, 0, 0, 0, 0x08204DF0, 0x0000
	object_event 3, 14, 0, 8, 5, 3, 2, 1, 1, 0, 0, 0x08204DF9, 0x0000
	object_event 4, 9, 0, 5, 6, 3, 10, 1, 1, 0, 0, 0x08204E02, 0x0000
	.globl FORTREE_CITY_MART_EventWarps
FORTREE_CITY_MART_EventWarps: @ 0x08509638
	warp_def 3, 7, 0, 3, MAP_FORTREE_CITY
	warp_def 4, 7, 0, 3, MAP_FORTREE_CITY
	.globl gMapEvents_FORTREE_CITY_MART
gMapEvents_FORTREE_CITY_MART: @ 0x08509648
	map_events FORTREE_CITY_MART_EventObjects, FORTREE_CITY_MART_EventWarps, 0, 0
	.globl FORTREE_CITY_HOUSE2_EventObjects
FORTREE_CITY_HOUSE2_EventObjects: @ 0x0850965C
	object_event 1, 22, 0, 2, 3, 3, 5, 1, 0, 0, 0, 0x08204E9C, 0x0000
	object_event 2, 21, 0, 6, 3, 3, 9, 1, 0, 0, 0, 0x08276A3A, 0x0000
	.globl FORTREE_CITY_HOUSE2_EventWarps
FORTREE_CITY_HOUSE2_EventWarps: @ 0x0850968C
	warp_def 3, 5, 0, 4, MAP_FORTREE_CITY
	warp_def 4, 5, 0, 4, MAP_FORTREE_CITY
	.globl gMapEvents_FORTREE_CITY_HOUSE2
gMapEvents_FORTREE_CITY_HOUSE2: @ 0x0850969C
	map_events FORTREE_CITY_HOUSE2_EventObjects, FORTREE_CITY_HOUSE2_EventWarps, 0, 0
	.globl FORTREE_CITY_HOUSE3_EventObjects
FORTREE_CITY_HOUSE3_EventObjects: @ 0x085096B0
	object_event 1, 39, 0, 0, 3, 3, 10, 0, 0, 0, 0, 0x082050D1, 0x0000
	object_event 2, 38, 0, 5, 4, 3, 2, 1, 1, 0, 0, 0x082050DA, 0x0000
	.globl FORTREE_CITY_HOUSE3_EventWarps
FORTREE_CITY_HOUSE3_EventWarps: @ 0x085096E0
	warp_def 3, 5, 0, 5, MAP_FORTREE_CITY
	warp_def 4, 5, 0, 5, MAP_FORTREE_CITY
	.globl gMapEvents_FORTREE_CITY_HOUSE3
gMapEvents_FORTREE_CITY_HOUSE3: @ 0x085096F0
	map_events FORTREE_CITY_HOUSE3_EventObjects, FORTREE_CITY_HOUSE3_EventWarps, 0, 0
	.globl FORTREE_CITY_HOUSE4_EventObjects
FORTREE_CITY_HOUSE4_EventObjects: @ 0x08509704
	object_event 1, 26, 0, 6, 4, 3, 2, 1, 1, 0, 0, 0x082051A3, 0x0000
	object_event 2, 13, 0, 1, 3, 3, 8, 0, 0, 0, 0, 0x082051AC, 0x0000
	object_event 3, 211, 0, 2, 3, 3, 8, 0, 0, 0, 0, 0x08205242, 0x03A5
	.globl FORTREE_CITY_HOUSE4_EventWarps
FORTREE_CITY_HOUSE4_EventWarps: @ 0x0850974C
	warp_def 3, 5, 0, 6, MAP_FORTREE_CITY
	warp_def 4, 5, 0, 6, MAP_FORTREE_CITY
	.globl gMapEvents_FORTREE_CITY_HOUSE4
gMapEvents_FORTREE_CITY_HOUSE4: @ 0x0850975C
	map_events FORTREE_CITY_HOUSE4_EventObjects, FORTREE_CITY_HOUSE4_EventWarps, 0, 0
	.globl FORTREE_CITY_HOUSE5_EventObjects
FORTREE_CITY_HOUSE5_EventObjects: @ 0x08509770
	object_event 1, 18, 0, 6, 4, 3, 20, 0, 0, 0, 0, 0x08205344, 0x0000
	object_event 2, 208, 0, 6, 3, 3, 8, 0, 0, 0, 0, 0x08205356, 0x0000
	object_event 3, 19, 0, 2, 4, 3, 10, 0, 0, 0, 0, 0x0820534D, 0x0000
	.globl FORTREE_CITY_HOUSE5_EventWarps
FORTREE_CITY_HOUSE5_EventWarps: @ 0x085097B8
	warp_def 3, 5, 0, 7, MAP_FORTREE_CITY
	warp_def 4, 5, 0, 7, MAP_FORTREE_CITY
	.globl gMapEvents_FORTREE_CITY_HOUSE5
gMapEvents_FORTREE_CITY_HOUSE5: @ 0x085097C8
	map_events FORTREE_CITY_HOUSE5_EventObjects, FORTREE_CITY_HOUSE5_EventWarps, 0, 0
	.globl FORTREE_CITY_DECORATION_SHOP_EventObjects
FORTREE_CITY_DECORATION_SHOP_EventObjects: @ 0x085097DC
	object_event 1, 25, 0, 6, 5, 3, 1, 1, 1, 0, 0, 0x082053F1, 0x0000
	object_event 2, 14, 0, 0, 4, 3, 9, 0, 0, 0, 0, 0x082053FA, 0x0000
	object_event 3, 83, 0, 1, 2, 3, 8, 0, 0, 0, 0, 0x08205403, 0x0000
	object_event 4, 83, 0, 6, 2, 3, 8, 0, 0, 0, 0, 0x08205430, 0x0000
	.globl FORTREE_CITY_DECORATION_SHOP_EventWarps
FORTREE_CITY_DECORATION_SHOP_EventWarps: @ 0x0850983C
	warp_def 3, 5, 0, 8, MAP_FORTREE_CITY
	warp_def 4, 5, 0, 8, MAP_FORTREE_CITY
	.globl gMapEvents_FORTREE_CITY_DECORATION_SHOP
gMapEvents_FORTREE_CITY_DECORATION_SHOP: @ 0x0850984C
	map_events FORTREE_CITY_DECORATION_SHOP_EventObjects, FORTREE_CITY_DECORATION_SHOP_EventWarps, 0, 0
	.globl LILYCOVE_CITY_COVE_LILY_MOTEL_1F_EventObjects
LILYCOVE_CITY_COVE_LILY_MOTEL_1F_EventObjects: @ 0x08509860
	object_event 1, 19, 0, 10, 3, 3, 7, 0, 0, 0, 0, 0x082054FD, 0x0000
	.globl LILYCOVE_CITY_COVE_LILY_MOTEL_1F_EventWarps
LILYCOVE_CITY_COVE_LILY_MOTEL_1F_EventWarps: @ 0x08509878
	warp_def 5, 8, 0, 1, MAP_LILYCOVE_CITY
	warp_def 6, 8, 0, 1, MAP_LILYCOVE_CITY
	warp_def 2, 1, 0, 0, MAP_LILYCOVE_CITY_COVE_LILY_MOTEL_2F
	.globl LILYCOVE_CITY_COVE_LILY_MOTEL_1F_EventCoordEvents
LILYCOVE_CITY_COVE_LILY_MOTEL_1F_EventCoordEvents: @ 0x08509890
	coord_event 10, 2, 3, 16385, 0, 0x08205585
	.globl gMapEvents_LILYCOVE_CITY_COVE_LILY_MOTEL_1F
gMapEvents_LILYCOVE_CITY_COVE_LILY_MOTEL_1F: @ 0x085098A0
	map_events LILYCOVE_CITY_COVE_LILY_MOTEL_1F_EventObjects, LILYCOVE_CITY_COVE_LILY_MOTEL_1F_EventWarps, LILYCOVE_CITY_COVE_LILY_MOTEL_1F_EventCoordEvents, 0
	.globl LILYCOVE_CITY_COVE_LILY_MOTEL_2F_EventObjects
LILYCOVE_CITY_COVE_LILY_MOTEL_2F_EventObjects: @ 0x085098B4
	object_event 1, 33, 0, 4, 6, 3, 9, 0, 0, 0, 0, 0x08205888, 0x039D
	object_event 2, 46, 0, 1, 4, 3, 10, 0, 0, 0, 0, 0x082058DE, 0x039D
	object_event 3, 17, 0, 7, 7, 3, 10, 0, 0, 0, 0, 0x082058E7, 0x039D
	object_event 4, 65, 0, 10, 3, 3, 9, 0, 0, 0, 0, 0x082058D5, 0x039D
	object_event 5, 189, 0, 7, 3, 3, 8, 1, 1, 0, 0, 0x082058F9, 0x039D
	object_event 6, 20, 0, 4, 4, 3, 9, 1, 1, 0, 0, 0x082058F0, 0x039D
	object_event 7, 219, 0, 1, 7, 3, 10, 0, 0, 0, 0, 0x08205902, 0x0313
	.globl LILYCOVE_CITY_COVE_LILY_MOTEL_2F_EventWarps
LILYCOVE_CITY_COVE_LILY_MOTEL_2F_EventWarps: @ 0x0850995C
	warp_def 2, 1, 0, 2, MAP_LILYCOVE_CITY_COVE_LILY_MOTEL_1F
	.globl gMapEvents_LILYCOVE_CITY_COVE_LILY_MOTEL_2F
gMapEvents_LILYCOVE_CITY_COVE_LILY_MOTEL_2F: @ 0x08509964
	map_events LILYCOVE_CITY_COVE_LILY_MOTEL_2F_EventObjects, LILYCOVE_CITY_COVE_LILY_MOTEL_2F_EventWarps, 0, 0
	.globl LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_EventObjects
LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_EventObjects: @ 0x08509978
	object_event 1, 45, 0, 5, 12, 3, 10, 0, 0, 0, 0, 0x08205BE3, 0x0000
	object_event 2, 48, 0, 16, 2, 3, 8, 0, 0, 0, 0, 0x08205BEC, 0x0307
	object_event 3, 38, 0, 13, 7, 3, 10, 0, 0, 0, 0, 0x08205D1F, 0x0000
	object_event 4, 99, 0, 13, 10, 3, 5, 2, 0, 0, 0, 0x08205D28, 0x0000
	object_event 5, 5, 0, 2, 8, 3, 7, 0, 0, 0, 0, 0x08205D31, 0x0000
	object_event 6, 26, 0, 3, 8, 3, 7, 0, 0, 0, 0, 0x08205D3A, 0x0000
	object_event 7, 20, 0, 11, 3, 3, 2, 1, 1, 0, 0, 0x08205D43, 0x0308
	object_event 8, 99, 0, 19, 3, 3, 7, 0, 0, 0, 0, 0x08205D55, 0x030B
	object_event 9, 17, 0, 2, 2, 3, 2, 2, 2, 0, 0, 0x08205D6C, 0x030C
	object_event 10, 37, 0, 6, 2, 3, 2, 1, 1, 0, 0, 0x08205D4C, 0x030A
	.globl LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_EventWarps
LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_EventWarps: @ 0x08509A68
	warp_def 9, 13, 0, 3, MAP_LILYCOVE_CITY
	warp_def 10, 13, 0, 13, MAP_LILYCOVE_CITY
	warp_def 16, 1, 0, 0, MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F
	.globl LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_EventBgEvents
LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_EventBgEvents: @ 0x08509A80
	bg_event 1, 1, 0, 0, 0x08205CD7, 0, 0
	bg_event 2, 1, 0, 0, 0x08205CD7, 0, 0
	bg_event 5, 1, 0, 0, 0x08205CFB, 0, 0
	bg_event 6, 1, 0, 0, 0x08205CFB, 0, 0
	bg_event 9, 1, 0, 0, 0x08205CCE, 0, 0
	bg_event 3, 6, 0, 0, 0x08205CE0, 0, 0
	bg_event 2, 6, 0, 0, 0x08205CE0, 0, 0
	bg_event 15, 12, 0, 0, 0x08205D04, 0, 0
	bg_event 11, 1, 0, 0, 0x08205CCE, 0, 0
	bg_event 6, 6, 0, 0, 0x08205CF2, 0, 0
	bg_event 17, 9, 0, 0, 0x08205D16, 0, 0
	bg_event 19, 1, 0, 0, 0x08205CE9, 0, 0
	bg_event 20, 1, 0, 0, 0x08205CE9, 0, 0
	bg_event 18, 9, 0, 0, 0x08205D16, 0, 0
	bg_event 18, 11, 0, 0, 0x08205D0D, 0, 0
	bg_event 16, 9, 0, 0, 0x08205D16, 0, 0
	.globl gMapEvents_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F
gMapEvents_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F: @ 0x08509B40
	map_events LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_EventObjects, LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_EventWarps, 0, LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_EventBgEvents
	.globl LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_EventObjects
LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_EventObjects: @ 0x08509B54
	object_event 1, 48, 0, 10, 8, 3, 7, 0, 0, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_00206312, 0x0000
	object_event 2, 10, 0, 19, 10, 3, 2, 1, 1, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_00206436, 0x0309
	object_event 3, 21, 0, 7, 3, 3, 2, 1, 1, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_0020643F, 0x030C
	object_event 4, 15, 0, 14, 6, 3, 2, 1, 1, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_00206448, 0x030C
	.globl LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_EventWarps
LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_EventWarps: @ 0x08509BB4
	warp_def 13, 1, 0, 2, MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F
	.globl LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_EventBgEvents
LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_EventBgEvents: @ 0x08509BBC
	bg_event 14, 10, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_002063D7, 0, 0
	bg_event 15, 10, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_002063D7, 0, 0
	bg_event 3, 6, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_002063EA, 0, 0
	bg_event 2, 6, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_002063EA, 0, 0
	bg_event 10, 6, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_002063FD, 0, 0
	bg_event 11, 6, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_002063FD, 0, 0
	bg_event 19, 6, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_00206410, 0, 0
	bg_event 18, 6, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_00206410, 0, 0
	bg_event 6, 10, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_00206423, 0, 0
	bg_event 7, 10, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_00206423, 0, 0
	bg_event 11, 2, 0, 0, 0x08205D04, 0, 0
	bg_event 15, 2, 0, 0, 0x08205D04, 0, 0
	.globl gMapEvents_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F
gMapEvents_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F: @ 0x08509C4C
	map_events LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_EventObjects, LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_EventWarps, 0, LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_EventBgEvents
	.globl LILYCOVE_CITY_CONTEST_LOBBY_EventObjects
LILYCOVE_CITY_CONTEST_LOBBY_EventObjects: @ 0x08509C60
	object_event 1, 85, 0, 14, 2, 3, 8, 1, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206C14, 0x0000
	object_event 2, 85, 0, 15, 2, 3, 8, 1, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206EC6, 0x0000
	object_event 3, 65, 0, 26, 9, 3, 10, 0, 0, 0, 0, 0x082590D2, 0x0000
	object_event 4, 99, 0, 9, 1, 0, 1, 0, 0, 0, 0, 0x00000000, 0x0306
	object_event 5, 44, 0, 18, 8, 3, 2, 1, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206DC8, 0x0000
	object_event 6, 10, 0, 4, 9, 3, 2, 2, 2, 0, 0, LilycoveCity_ContestLobby_EventScript_00206DD1, 0x0000
	object_event 7, 99, 0, 3, 4, 3, 2, 1, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206DDA, 0x0000
	object_event 8, 67, 0, 13, 10, 3, 10, 0, 0, 0, 0, 0x08253E71, 0x0322
	object_event 9, 7, 0, 23, 8, 3, 8, 0, 0, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E28, 0x0000
	object_event 10, 6, 0, 28, 9, 3, 9, 0, 0, 0, 0, 0x082590E4, 0x0000
	object_event 11, 99, 0, 21, 1, 0, 8, 0, 0, 0, 0, 0x00000000, 0x037F
	object_event 12, 50, 0, 5, 6, 3, 2, 1, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206DEC, 0x0000
	object_event 13, 17, 0, 0, 8, 3, 10, 0, 0, 0, 0, LilycoveCity_ContestLobby_EventScript_00206DE3, 0x0000
	object_event 14, 5, 0, 8, 7, 3, 3, 0, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206DF5, 0x0000
	object_event 15, 18, 0, 22, 9, 3, 10, 0, 0, 0, 0, 0x082590DB, 0x0000
	object_event 16, 21, 0, 26, 5, 3, 10, 0, 0, 0, 0, 0x082590ED, 0x0369
	object_event 17, 8, 0, 24, 9, 3, 9, 0, 0, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E31, 0x0000
	object_event 18, 66, 0, 27, 3, 3, 8, 1, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E73, 0x0340
	object_event 19, 31, 0, 28, 3, 3, 8, 1, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E7E, 0x0340
	object_event 20, 12, 0, 28, 7, 3, 7, 1, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E89, 0x0340
	object_event 21, 115, 0, 26, 7, 3, 7, 1, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E99, 0x0340
	object_event 22, 16, 0, 27, 7, 3, 7, 1, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206EA9, 0x0340
	object_event 23, 5, 0, 26, 3, 3, 8, 1, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E68, 0x0340
	object_event 24, 29, 0, 26, 5, 3, 10, 1, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E58, 0x0340
	object_event 25, 12, 0, 9, 10, 3, 10, 2, 2, 0, 0, LilycoveCity_ContestLobby_EventScript_002073B1, 0x0000
	.globl LILYCOVE_CITY_CONTEST_LOBBY_EventWarps
LILYCOVE_CITY_CONTEST_LOBBY_EventWarps: @ 0x08509EB8
	warp_def 14, 11, 0, 4, MAP_LILYCOVE_CITY
	warp_def 15, 11, 0, 4, MAP_LILYCOVE_CITY
	warp_def 9, 1, 0, 0, MAP_LILYCOVE_CITY_CONTEST_HALL
	warp_def 21, 1, 0, 1, MAP_LILYCOVE_CITY_CONTEST_HALL
	.globl LILYCOVE_CITY_CONTEST_LOBBY_EventBgEvents
LILYCOVE_CITY_CONTEST_LOBBY_EventBgEvents: @ 0x08509ED8
	bg_event 23, 5, 0, 0, 0x08259185, 0, 0
	bg_event 23, 9, 0, 0, 0x08258F4E, 0, 0
	bg_event 23, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E13, 0, 0
	bg_event 25, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E1A, 0, 0
	bg_event 27, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E21, 0, 0
	bg_event 30, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E3A, 0, 0
	bg_event 3, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206DFE, 0, 0
	bg_event 5, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E05, 0, 0
	bg_event 7, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E0C, 0, 0
	bg_event 27, 5, 0, 0, 0x08258D6E, 0, 0
	bg_event 27, 9, 0, 0, 0x08258E7D, 0, 0
	bg_event 18, 3, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E44, 0, 0
	.globl gMapEvents_LILYCOVE_CITY_CONTEST_LOBBY
gMapEvents_LILYCOVE_CITY_CONTEST_LOBBY: @ 0x08509F68
	map_events LILYCOVE_CITY_CONTEST_LOBBY_EventObjects, LILYCOVE_CITY_CONTEST_LOBBY_EventWarps, 0, LILYCOVE_CITY_CONTEST_LOBBY_EventBgEvents
	.globl LILYCOVE_CITY_CONTEST_HALL_EventObjects
LILYCOVE_CITY_CONTEST_HALL_EventObjects: @ 0x08509F7C
	object_event 1, 7, 0, 30, 30, 3, 2, 4, 4, 0, 0, 0x082077BA, 0x0000
	object_event 2, 13, 0, 11, 7, 3, 2, 3, 3, 0, 0, 0x082077C3, 0x0000
	object_event 3, 14, 0, 40, 8, 3, 2, 2, 2, 0, 0, 0x082077CC, 0x0000
	object_event 4, 24, 0, 12, 22, 3, 8, 0, 0, 0, 0, 0x082077DE, 0x0000
	object_event 5, 190, 0, 15, 22, 3, 8, 0, 0, 0, 0, 0x082077F5, 0x0000
	object_event 6, 44, 0, 10, 25, 3, 7, 0, 0, 0, 0, 0x0820780C, 0x0000
	object_event 7, 21, 0, 12, 25, 3, 7, 0, 0, 0, 0, 0x08207823, 0x0000
	object_event 8, 39, 0, 14, 25, 3, 7, 0, 0, 0, 0, 0x0820783A, 0x0000
	object_event 9, 28, 0, 16, 25, 3, 7, 0, 0, 0, 0, 0x08207851, 0x0000
	object_event 10, 22, 0, 8, 24, 3, 10, 0, 0, 0, 0, 0x08207868, 0x0000
	object_event 11, 34, 0, 18, 24, 3, 9, 0, 0, 0, 0, 0x0820789F, 0x0000
	object_event 12, 7, 0, 8, 22, 3, 10, 0, 0, 0, 0, 0x08207871, 0x0000
	object_event 13, 24, 0, 24, 10, 3, 8, 0, 0, 0, 0, 0x082078B6, 0x0000
	object_event 14, 190, 0, 27, 10, 3, 8, 0, 0, 0, 0, 0x082078CD, 0x0000
	object_event 15, 26, 0, 22, 13, 3, 7, 0, 0, 0, 0, 0x082078E4, 0x0000
	object_event 16, 6, 0, 24, 13, 3, 7, 0, 0, 0, 0, 0x082078FB, 0x0000
	object_event 17, 37, 0, 26, 13, 3, 7, 0, 0, 0, 0, 0x08207912, 0x0000
	object_event 18, 18, 0, 28, 13, 3, 7, 0, 0, 0, 0, 0x08207929, 0x0000
	object_event 19, 20, 0, 20, 10, 3, 10, 0, 0, 0, 0, 0x08207940, 0x0000
	object_event 20, 16, 0, 30, 11, 3, 9, 0, 0, 0, 0, 0x0820796E, 0x0000
	object_event 21, 19, 0, 26, 8, 3, 8, 0, 0, 0, 0, 0x08207957, 0x0000
	object_event 22, 31, 0, 13, 20, 3, 8, 0, 0, 0, 0, 0x08207888, 0x0000
	object_event 23, 24, 0, 36, 22, 3, 8, 0, 0, 0, 0, 0x08207985, 0x0000
	object_event 24, 190, 0, 39, 22, 3, 8, 0, 0, 0, 0, 0x0820799C, 0x0000
	object_event 25, 9, 0, 34, 25, 3, 7, 0, 0, 0, 0, 0x082079B3, 0x0000
	object_event 26, 10, 0, 36, 25, 3, 7, 0, 0, 0, 0, 0x082079CA, 0x0000
	object_event 27, 13, 0, 38, 25, 3, 7, 0, 0, 0, 0, 0x082079E1, 0x0000
	object_event 28, 22, 0, 40, 25, 3, 7, 0, 0, 0, 0, 0x082079F8, 0x0000
	object_event 29, 20, 0, 32, 23, 3, 10, 0, 0, 0, 0, 0x08207A0F, 0x0000
	object_event 30, 19, 0, 37, 20, 3, 8, 0, 0, 0, 0, 0x08207A51, 0x0000
	object_event 31, 12, 0, 42, 24, 3, 9, 0, 0, 0, 0, 0x08207A3A, 0x0000
	object_event 32, 49, 0, 23, 26, 3, 2, 1, 1, 0, 0, 0x082077D5, 0x0000
	.globl LILYCOVE_CITY_CONTEST_HALL_EventWarps
LILYCOVE_CITY_CONTEST_HALL_EventWarps: @ 0x0850A27C
	warp_def 19, 32, 0, 2, MAP_LILYCOVE_CITY_CONTEST_LOBBY
	warp_def 30, 32, 0, 3, MAP_LILYCOVE_CITY_CONTEST_LOBBY
	warp_def 20, 32, 0, 2, MAP_LILYCOVE_CITY_CONTEST_LOBBY
	warp_def 31, 32, 0, 3, MAP_LILYCOVE_CITY_CONTEST_LOBBY
	.globl LILYCOVE_CITY_CONTEST_HALL_EventBgEvents
LILYCOVE_CITY_CONTEST_HALL_EventBgEvents: @ 0x0850A29C
	bg_event 27, 16, 0, 0, 0x08207A68, 0, 0
	bg_event 39, 28, 0, 0, 0x08207A71, 0, 0
	bg_event 11, 28, 0, 0, 0x08207A7A, 0, 0
	bg_event 15, 28, 0, 0, 0x08207A7A, 0, 0
	bg_event 23, 16, 0, 0, 0x08207A68, 0, 0
	bg_event 35, 28, 0, 0, 0x08207A71, 0, 0
	.globl gMapEvents_LILYCOVE_CITY_CONTEST_HALL
gMapEvents_LILYCOVE_CITY_CONTEST_HALL: @ 0x0850A2E4
	map_events LILYCOVE_CITY_CONTEST_HALL_EventObjects, LILYCOVE_CITY_CONTEST_HALL_EventWarps, 0, LILYCOVE_CITY_CONTEST_HALL_EventBgEvents
	.globl LILYCOVE_CITY_POKEMON_CENTER_1F_EventObjects
LILYCOVE_CITY_POKEMON_CENTER_1F_EventObjects: @ 0x0850A2F8
	object_event 1, 58, 0, 7, 2, 3, 8, 0, 0, 0, 0, LilycoveCity_PokemonCenter_1F_EventScript_00208280, 0x0000
	object_event 2, 7, 0, 10, 7, 3, 10, 0, 0, 0, 0, LilycoveCity_PokemonCenter_1F_EventScript_0020828E, 0x0000
	object_event 3, 39, 0, 11, 8, 3, 7, 0, 0, 0, 0, LilycoveCity_PokemonCenter_1F_EventScript_00208297, 0x0000
	object_event 4, 240, 0, 1, 3, 3, 8, 0, 0, 0, 0, 0x08264373, 0x0000
	object_event 5, 241, 0, 2, 3, 3, 8, 0, 0, 0, 0, 0x082649CF, 0x03E1
	.globl LILYCOVE_CITY_POKEMON_CENTER_1F_EventWarps
LILYCOVE_CITY_POKEMON_CENTER_1F_EventWarps: @ 0x0850A370
	warp_def 7, 8, 3, 2, MAP_LILYCOVE_CITY
	warp_def 6, 8, 3, 2, MAP_LILYCOVE_CITY
	warp_def 1, 6, 4, 0, MAP_LILYCOVE_CITY_POKEMON_CENTER_2F
	.globl gMapEvents_LILYCOVE_CITY_POKEMON_CENTER_1F
gMapEvents_LILYCOVE_CITY_POKEMON_CENTER_1F: @ 0x0850A388
	map_events LILYCOVE_CITY_POKEMON_CENTER_1F_EventObjects, LILYCOVE_CITY_POKEMON_CENTER_1F_EventWarps, 0, 0
	.globl LILYCOVE_CITY_POKEMON_CENTER_2F_EventObjects
LILYCOVE_CITY_POKEMON_CENTER_2F_EventObjects: @ 0x0850A39C
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 3, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	.globl LILYCOVE_CITY_POKEMON_CENTER_2F_EventWarps
LILYCOVE_CITY_POKEMON_CENTER_2F_EventWarps: @ 0x0850A3FC
	warp_def 1, 6, 4, 2, MAP_LILYCOVE_CITY_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_LILYCOVE_CITY_POKEMON_CENTER_2F
gMapEvents_LILYCOVE_CITY_POKEMON_CENTER_2F: @ 0x0850A414
	map_events LILYCOVE_CITY_POKEMON_CENTER_2F_EventObjects, LILYCOVE_CITY_POKEMON_CENTER_2F_EventWarps, 0, 0
	.globl LILYCOVE_CITY_UNUSED_MART_EventObjects
LILYCOVE_CITY_UNUSED_MART_EventObjects: @ 0x00000000
	.globl LILYCOVE_CITY_UNUSED_MART_EventWarps
LILYCOVE_CITY_UNUSED_MART_EventWarps: @ 0x0850A428
	warp_def 3, 7, 0, 0, MAP_LILYCOVE_CITY
	warp_def 4, 7, 0, 0, MAP_LILYCOVE_CITY
	.globl gMapEvents_LILYCOVE_CITY_UNUSED_MART
gMapEvents_LILYCOVE_CITY_UNUSED_MART: @ 0x0850A438
	map_events 0, LILYCOVE_CITY_UNUSED_MART_EventWarps, 0, 0
	.globl LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB_EventObjects
LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB_EventObjects: @ 0x0850A44C
	object_event 1, 47, 0, 3, 11, 3, 7, 0, 0, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_002086A7, 0x0000
	object_event 2, 65, 0, 8, 10, 3, 9, 0, 0, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_00208630, 0x0000
	object_event 3, 25, 0, 6, 11, 3, 7, 0, 0, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_0020871E, 0x0000
	object_event 4, 12, 0, 5, 8, 3, 8, 0, 0, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_00208795, 0x0000
	object_event 5, 5, 0, 7, 11, 3, 7, 0, 0, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_0020880C, 0x0317
	object_event 6, 9, 0, 1, 9, 3, 8, 0, 0, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_0020886E, 0x0316
	object_event 7, 24, 0, 3, 10, 3, 10, 0, 0, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_002088D0, 0x0318
	object_event 8, 22, 0, 10, 10, 3, 9, 0, 0, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_00208932, 0x0315
	object_event 9, 7, 0, 11, 5, 3, 8, 1, 1, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_00208994, 0x02DA
	.globl LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB_EventWarps
LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB_EventWarps: @ 0x0850A524
	warp_def 6, 13, 0, 5, MAP_LILYCOVE_CITY
	warp_def 5, 13, 0, 5, MAP_LILYCOVE_CITY
	.globl gMapEvents_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB
gMapEvents_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB: @ 0x0850A534
	map_events LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB_EventObjects, LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB_EventWarps, 0, 0
	.globl LILYCOVE_CITY_HARBOR_EventObjects
LILYCOVE_CITY_HARBOR_EventObjects: @ 0x0850A548
	object_event 1, 45, 0, 8, 10, 3, 8, 0, 0, 0, 0, LilycoveCity_Harbor_EventScript_002094E3, 0x038C
	object_event 2, 140, 0, 8, 9, 1, 10, 0, 0, 0, 0, 0x00000000, 0x035D
	object_event 3, 49, 0, 3, 13, 3, 2, 1, 1, 0, 0, LilycoveCity_Harbor_EventScript_00209B0B, 0x0000
	object_event 4, 49, 0, 8, 10, 3, 8, 0, 0, 0, 0, 0x00000000, 0x038D
	object_event 5, 21, 0, 8, 10, 3, 8, 1, 1, 0, 0, 0x00000000, 0x02EC
	.globl LILYCOVE_CITY_HARBOR_EventWarps
LILYCOVE_CITY_HARBOR_EventWarps: @ 0x0850A5C0
	warp_def 11, 14, 0, 12, MAP_LILYCOVE_CITY
	warp_def 12, 14, 0, 12, MAP_LILYCOVE_CITY
	.globl gMapEvents_LILYCOVE_CITY_HARBOR
gMapEvents_LILYCOVE_CITY_HARBOR: @ 0x0850A5D0
	map_events LILYCOVE_CITY_HARBOR_EventObjects, LILYCOVE_CITY_HARBOR_EventWarps, 0, 0
	.globl LILYCOVE_CITY_MOVE_DELETERS_HOUSE_EventObjects
LILYCOVE_CITY_MOVE_DELETERS_HOUSE_EventObjects: @ 0x0850A5E4
	object_event 1, 21, 0, 4, 4, 3, 8, 0, 0, 0, 0, 0x08209D71, 0x0000
	.globl LILYCOVE_CITY_MOVE_DELETERS_HOUSE_EventWarps
LILYCOVE_CITY_MOVE_DELETERS_HOUSE_EventWarps: @ 0x0850A5FC
	warp_def 3, 7, 0, 7, MAP_LILYCOVE_CITY
	warp_def 4, 7, 0, 7, MAP_LILYCOVE_CITY
	.globl gMapEvents_LILYCOVE_CITY_MOVE_DELETERS_HOUSE
gMapEvents_LILYCOVE_CITY_MOVE_DELETERS_HOUSE: @ 0x0850A60C
	map_events LILYCOVE_CITY_MOVE_DELETERS_HOUSE_EventObjects, LILYCOVE_CITY_MOVE_DELETERS_HOUSE_EventWarps, 0, 0
	.globl LILYCOVE_CITY_HOUSE1_EventObjects
LILYCOVE_CITY_HOUSE1_EventObjects: @ 0x0850A620
	object_event 1, 21, 0, 4, 5, 3, 9, 1, 1, 0, 0, 0x08209F67, 0x0000
	object_event 2, 204, 0, 4, 4, 3, 8, 0, 0, 0, 0, 0x08209F70, 0x0000
	.globl LILYCOVE_CITY_HOUSE1_EventWarps
LILYCOVE_CITY_HOUSE1_EventWarps: @ 0x0850A650
	warp_def 3, 8, 0, 8, MAP_LILYCOVE_CITY
	warp_def 4, 8, 0, 8, MAP_LILYCOVE_CITY
	.globl gMapEvents_LILYCOVE_CITY_HOUSE1
gMapEvents_LILYCOVE_CITY_HOUSE1: @ 0x0850A660
	map_events LILYCOVE_CITY_HOUSE1_EventObjects, LILYCOVE_CITY_HOUSE1_EventWarps, 0, 0
	.globl LILYCOVE_CITY_HOUSE2_EventObjects
LILYCOVE_CITY_HOUSE2_EventObjects: @ 0x0850A674
	object_event 1, 17, 0, 0, 4, 3, 8, 0, 0, 0, 0, 0x08209FDD, 0x0000
	.globl LILYCOVE_CITY_HOUSE2_EventWarps
LILYCOVE_CITY_HOUSE2_EventWarps: @ 0x0850A68C
	warp_def 2, 7, 0, 9, MAP_LILYCOVE_CITY
	warp_def 3, 7, 0, 9, MAP_LILYCOVE_CITY
	.globl gMapEvents_LILYCOVE_CITY_HOUSE2
gMapEvents_LILYCOVE_CITY_HOUSE2: @ 0x0850A69C
	map_events LILYCOVE_CITY_HOUSE2_EventObjects, LILYCOVE_CITY_HOUSE2_EventWarps, 0, 0
	.globl LILYCOVE_CITY_HOUSE3_EventObjects
LILYCOVE_CITY_HOUSE3_EventObjects: @ 0x0850A6B0
	object_event 1, 189, 0, 3, 4, 3, 8, 1, 1, 0, 0, LilycoveCity_House3_EventScript_0020A166, 0x0000
	object_event 2, 18, 0, 7, 4, 3, 9, 0, 0, 0, 0, LilycoveCity_House3_EventScript_0020A074, 0x0000
	object_event 3, 189, 0, 1, 4, 3, 8, 1, 1, 0, 0, LilycoveCity_House3_EventScript_0020A0FE, 0x0000
	object_event 4, 189, 0, 2, 5, 3, 7, 1, 1, 0, 0, LilycoveCity_House3_EventScript_0020A132, 0x0000
	object_event 5, 189, 0, 2, 3, 3, 8, 1, 1, 0, 0, LilycoveCity_House3_EventScript_0020A0CA, 0x0000
	object_event 6, 19, 0, 7, 5, 3, 9, 1, 1, 0, 0, LilycoveCity_House3_EventScript_0020A0B3, 0x0000
	.globl LILYCOVE_CITY_HOUSE3_EventWarps
LILYCOVE_CITY_HOUSE3_EventWarps: @ 0x0850A740
	warp_def 3, 7, 0, 10, MAP_LILYCOVE_CITY
	warp_def 4, 7, 0, 10, MAP_LILYCOVE_CITY
	.globl gMapEvents_LILYCOVE_CITY_HOUSE3
gMapEvents_LILYCOVE_CITY_HOUSE3: @ 0x0850A750
	map_events LILYCOVE_CITY_HOUSE3_EventObjects, LILYCOVE_CITY_HOUSE3_EventWarps, 0, 0
	.globl LILYCOVE_CITY_HOUSE4_EventObjects
LILYCOVE_CITY_HOUSE4_EventObjects: @ 0x0850A764
	object_event 1, 65, 0, 1, 4, 3, 2, 1, 1, 0, 0, 0x0820A51B, 0x0000
	object_event 2, 19, 0, 7, 4, 3, 2, 1, 1, 0, 0, 0x0820A524, 0x0000
	.globl LILYCOVE_CITY_HOUSE4_EventWarps
LILYCOVE_CITY_HOUSE4_EventWarps: @ 0x0850A794
	warp_def 3, 8, 0, 11, MAP_LILYCOVE_CITY
	warp_def 4, 8, 0, 11, MAP_LILYCOVE_CITY
	.globl gMapEvents_LILYCOVE_CITY_HOUSE4
gMapEvents_LILYCOVE_CITY_HOUSE4: @ 0x0850A7A4
	map_events LILYCOVE_CITY_HOUSE4_EventObjects, LILYCOVE_CITY_HOUSE4_EventWarps, 0, 0
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_1F_EventObjects
LILYCOVE_CITY_DEPARTMENT_STORE_1F_EventObjects: @ 0x0850A7B8
	object_event 1, 45, 0, 8, 2, 3, 8, 0, 0, 0, 0, 0x0820A5B0, 0x0000
	object_event 2, 45, 0, 10, 2, 3, 8, 0, 0, 0, 0, 0x0820A5B9, 0x0000
	object_event 3, 18, 0, 14, 5, 3, 2, 1, 1, 0, 0, 0x0820A74C, 0x0000
	object_event 4, 12, 0, 4, 4, 3, 2, 1, 1, 0, 0, 0x0820A755, 0x0000
	object_event 5, 25, 0, 3, 6, 3, 2, 1, 1, 0, 0, 0x0820A75E, 0x0000
	object_event 6, 210, 0, 2, 6, 3, 1, 1, 1, 0, 0, 0x0820A767, 0x0000
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_1F_EventWarps
LILYCOVE_CITY_DEPARTMENT_STORE_1F_EventWarps: @ 0x0850A848
	warp_def 8, 7, 0, 0, MAP_LILYCOVE_CITY
	warp_def 9, 7, 0, 0, MAP_LILYCOVE_CITY
	warp_def 16, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_2F
	warp_def 2, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_1F_EventBgEvents
LILYCOVE_CITY_DEPARTMENT_STORE_1F_EventBgEvents: @ 0x0850A868
	bg_event 0, 8, 0, 1, 0x0820A77A, 0, 0
	.globl gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_1F
gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_1F: @ 0x0850A874
	map_events LILYCOVE_CITY_DEPARTMENT_STORE_1F_EventObjects, LILYCOVE_CITY_DEPARTMENT_STORE_1F_EventWarps, 0, LILYCOVE_CITY_DEPARTMENT_STORE_1F_EventBgEvents
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_2F_EventObjects
LILYCOVE_CITY_DEPARTMENT_STORE_2F_EventObjects: @ 0x0850A888
	object_event 1, 27, 0, 8, 2, 3, 8, 0, 0, 0, 0, 0x0820A921, 0x0000
	object_event 2, 18, 0, 0, 5, 3, 2, 1, 1, 0, 0, 0x0820A92A, 0x0000
	object_event 3, 49, 0, 13, 5, 3, 2, 1, 1, 0, 0, 0x0820A933, 0x0000
	object_event 4, 24, 0, 10, 6, 3, 7, 0, 0, 0, 0, 0x0820A96E, 0x0000
	object_event 5, 24, 0, 7, 6, 3, 7, 0, 0, 0, 0, 0x0820A93C, 0x0000
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_2F_EventWarps
LILYCOVE_CITY_DEPARTMENT_STORE_2F_EventWarps: @ 0x0850A900
	warp_def 16, 1, 0, 2, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_1F
	warp_def 13, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_3F
	warp_def 2, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR
	.globl gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_2F
gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_2F: @ 0x0850A918
	map_events LILYCOVE_CITY_DEPARTMENT_STORE_2F_EventObjects, LILYCOVE_CITY_DEPARTMENT_STORE_2F_EventWarps, 0, 0
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_3F_EventObjects
LILYCOVE_CITY_DEPARTMENT_STORE_3F_EventObjects: @ 0x0850A92C
	object_event 1, 51, 0, 0, 5, 3, 2, 1, 1, 0, 0, 0x0820AA6E, 0x0000
	object_event 2, 25, 0, 7, 7, 3, 2, 1, 1, 0, 0, 0x0820AA77, 0x0000
	object_event 3, 34, 0, 13, 5, 3, 2, 1, 1, 0, 0, 0x0820AA80, 0x0000
	object_event 4, 24, 0, 8, 2, 3, 8, 0, 0, 0, 0, 0x0820AA1A, 0x0000
	object_event 5, 24, 0, 10, 2, 3, 8, 1, 1, 0, 0, 0x0820AA44, 0x0000
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_3F_EventWarps
LILYCOVE_CITY_DEPARTMENT_STORE_3F_EventWarps: @ 0x0850A9A4
	warp_def 13, 1, 0, 1, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_2F
	warp_def 16, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_4F
	warp_def 2, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR
	.globl gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_3F
gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_3F: @ 0x0850A9BC
	map_events LILYCOVE_CITY_DEPARTMENT_STORE_3F_EventObjects, LILYCOVE_CITY_DEPARTMENT_STORE_3F_EventWarps, 0, 0
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_4F_EventObjects
LILYCOVE_CITY_DEPARTMENT_STORE_4F_EventObjects: @ 0x0850A9D0
	object_event 1, 48, 0, 0, 2, 3, 2, 1, 1, 0, 0, 0x0820AB4F, 0x0000
	object_event 2, 20, 0, 6, 2, 3, 2, 1, 1, 0, 0, 0x0820AB58, 0x0000
	object_event 3, 35, 0, 13, 4, 3, 2, 1, 1, 0, 0, 0x0820AB61, 0x0000
	object_event 4, 24, 0, 7, 6, 3, 7, 0, 0, 0, 0, 0x0820AB6A, 0x0000
	object_event 5, 24, 0, 9, 6, 3, 7, 0, 0, 0, 0, 0x0820AB90, 0x0000
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_4F_EventWarps
LILYCOVE_CITY_DEPARTMENT_STORE_4F_EventWarps: @ 0x0850AA48
	warp_def 16, 1, 0, 1, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_3F
	warp_def 13, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_5F
	warp_def 2, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR
	.globl gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_4F
gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_4F: @ 0x0850AA60
	map_events LILYCOVE_CITY_DEPARTMENT_STORE_4F_EventObjects, LILYCOVE_CITY_DEPARTMENT_STORE_4F_EventWarps, 0, 0
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_5F_EventObjects
LILYCOVE_CITY_DEPARTMENT_STORE_5F_EventObjects: @ 0x0850AA74
	object_event 1, 12, 0, 1, 6, 3, 2, 1, 1, 0, 0, LilycoveCity_DepartmentStore_5F_EventScript_0020AD90, 0x0000
	object_event 2, 18, 0, 7, 7, 3, 17, 1, 1, 0, 0, LilycoveCity_DepartmentStore_5F_EventScript_0020AD40, 0x0000
	object_event 3, 24, 0, 7, 2, 3, 8, 0, 0, 0, 0, LilycoveCity_DepartmentStore_5F_EventScript_0020AC7A, 0x0000
	object_event 4, 24, 0, 9, 2, 3, 8, 0, 0, 0, 0, LilycoveCity_DepartmentStore_5F_EventScript_0020ACB0, 0x0000
	object_event 5, 24, 0, 15, 6, 3, 9, 0, 0, 0, 0, LilycoveCity_DepartmentStore_5F_EventScript_0020ACDE, 0x0000
	object_event 6, 24, 0, 17, 6, 3, 7, 0, 0, 0, 0, LilycoveCity_DepartmentStore_5F_EventScript_0020AD0E, 0x0000
	object_event 7, 20, 0, 9, 5, 3, 10, 1, 1, 0, 0, LilycoveCity_DepartmentStore_5F_EventScript_0020AD49, 0x0000
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_5F_EventWarps
LILYCOVE_CITY_DEPARTMENT_STORE_5F_EventWarps: @ 0x0850AB1C
	warp_def 13, 1, 0, 1, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_4F
	warp_def 2, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR
	warp_def 16, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP
	.globl gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_5F
gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_5F: @ 0x0850AB34
	map_events LILYCOVE_CITY_DEPARTMENT_STORE_5F_EventObjects, LILYCOVE_CITY_DEPARTMENT_STORE_5F_EventWarps, 0, 0
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_EventObjects
LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_EventObjects: @ 0x0850AB48
	object_event 1, 23, 0, 4, 4, 3, 7, 0, 0, 0, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_0020AEB4, 0x0000
	object_event 2, 33, 0, 7, 5, 3, 5, 1, 0, 0, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_0020AED8, 0x0000
	object_event 3, 84, 0, 6, 1, 3, 8, 1, 1, 0, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_0020AE7B, 0x03C2
	object_event 4, 24, 0, 15, 5, 3, 8, 1, 0, 0, 0, 0x08276AA2, 0x0000
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_EventWarps
LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_EventWarps: @ 0x0850ABA8
	warp_def 13, 3, 0, 2, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_5F
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_EventBgEvents
LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_EventBgEvents: @ 0x0850ABB0
	bg_event 9, 1, 0, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_0020AEE1, 0, 0
	bg_event 10, 1, 0, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_0020AEE1, 0, 0
	.globl gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP
gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP: @ 0x0850ABC8
	map_events LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_EventObjects, LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_EventWarps, 0, LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_EventBgEvents
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_EventObjects
LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_EventObjects: @ 0x0850ABDC
	object_event 1, 85, 0, 0, 5, 3, 8, 0, 0, 0, 0, 0x0820B18D, 0x0000
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_EventWarps
LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_EventWarps: @ 0x0850ABF4
	warp_def 1, 5, 3, 127, 0x7F7F
	warp_def 2, 5, 3, 127, 0x7F7F
	.globl gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR
gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR: @ 0x0850AC04
	map_events LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_EventObjects, LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_EventWarps, 0, 0
	.globl MOSSDEEP_CITY_GYM_EventObjects
MOSSDEEP_CITY_GYM_EventObjects: @ 0x0850AC18
	object_event 1, 132, 0, 23, 7, 0, 8, 0, 0, 0, 0, 0x0820B401, 0x0000
	object_event 2, 37, 0, 1, 30, 3, 8, 0, 0, 1, 1, 0x0820B666, 0x0000
	object_event 3, 37, 0, 5, 20, 3, 7, 0, 0, 1, 1, 0x0820B694, 0x0000
	object_event 4, 47, 0, 4, 29, 3, 7, 0, 0, 1, 1, 0x0820B6D9, 0x0000
	object_event 5, 47, 0, 4, 23, 0, 7, 0, 0, 1, 1, 0x0820B6C2, 0x0000
	object_event 6, 37, 0, 6, 9, 3, 8, 0, 0, 1, 1, 0x0820B67D, 0x0000
	object_event 7, 47, 0, 6, 3, 0, 8, 0, 0, 1, 1, 0x0820B6AB, 0x0000
	object_event 8, 23, 0, 5, 33, 0, 8, 0, 0, 0, 0, MossdeepCity_Gym_EventScript_0020B77A, 0x0000
	object_event 9, 131, 0, 24, 7, 0, 8, 0, 0, 0, 0, 0x0820B401, 0x0000
	object_event 10, 224, 0, 2, 30, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 11, 224, 0, 1, 29, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 12, 224, 0, 4, 30, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 13, 224, 0, 5, 29, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 14, 224, 0, 5, 21, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 15, 224, 0, 7, 9, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 16, 224, 0, 10, 8, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 17, 48, 0, 9, 8, 3, 7, 1, 1, 1, 1, 0x0820B707, 0x0000
	object_event 18, 40, 0, 7, 5, 3, 10, 1, 1, 1, 1, 0x0820B6F0, 0x0000
	object_event 19, 224, 0, 6, 6, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 20, 224, 0, 12, 5, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 21, 224, 0, 11, 5, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 22, 224, 0, 11, 34, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 23, 224, 0, 12, 33, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 24, 224, 0, 12, 34, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 25, 48, 0, 22, 25, 3, 7, 1, 1, 1, 1, 0x0820B735, 0x0000
	object_event 26, 224, 0, 23, 26, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 27, 47, 0, 25, 25, 0, 9, 1, 1, 1, 1, 0x0820B71E, 0x0000
	object_event 28, 40, 0, 22, 23, 3, 8, 1, 1, 1, 1, 0x0820B763, 0x0000
	object_event 29, 224, 0, 21, 23, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 30, 224, 0, 21, 22, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 31, 224, 0, 22, 22, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 32, 37, 0, 25, 22, 3, 7, 1, 1, 1, 1, 0x0820B74C, 0x0000
	object_event 33, 224, 0, 24, 22, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 34, 224, 0, 24, 23, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 35, 224, 0, 6, 5, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 36, 224, 0, 23, 25, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	.globl MOSSDEEP_CITY_GYM_EventWarps
MOSSDEEP_CITY_GYM_EventWarps: @ 0x0850AF78
	warp_def 6, 35, 3, 1, MAP_MOSSDEEP_CITY
	warp_def 7, 35, 3, 1, MAP_MOSSDEEP_CITY
	warp_def 3, 28, 0, 3, MAP_MOSSDEEP_CITY_GYM
	warp_def 1, 23, 3, 2, MAP_MOSSDEEP_CITY_GYM
	warp_def 7, 18, 0, 5, MAP_MOSSDEEP_CITY_GYM
	warp_def 8, 12, 0, 4, MAP_MOSSDEEP_CITY_GYM
	warp_def 9, 18, 0, 7, MAP_MOSSDEEP_CITY_GYM
	warp_def 23, 20, 0, 6, MAP_MOSSDEEP_CITY_GYM
	warp_def 1, 33, 3, 9, MAP_MOSSDEEP_CITY_GYM
	warp_def 20, 24, 0, 8, MAP_MOSSDEEP_CITY_GYM
	warp_def 11, 3, 0, 11, MAP_MOSSDEEP_CITY_GYM
	warp_def 11, 35, 3, 10, MAP_MOSSDEEP_CITY_GYM
	warp_def 13, 32, 0, 13, MAP_MOSSDEEP_CITY_GYM
	warp_def 21, 10, 0, 12, MAP_MOSSDEEP_CITY_GYM
	.globl MOSSDEEP_CITY_GYM_EventCoordEvents
MOSSDEEP_CITY_GYM_EventCoordEvents: @ 0x0850AFE8
	coord_event 2, 21, 3, 16385, 0, 0x0820B7D0
	coord_event 8, 10, 3, 16385, 0, 0x0820B7E6
	coord_event 6, 7, 3, 16385, 0, 0x0820B7E6
	coord_event 15, 34, 3, 16385, 0, 0x0820B7FC
	coord_event 23, 24, 3, 16385, 0, 0x0820B812
	coord_event 23, 21, 3, 16385, 0, 0x0820B812
	coord_event 8, 6, 3, 16385, 0, 0x0820B828
	coord_event 21, 6, 0, 16385, 0, 0x0820B65A
	coord_event 3, 30, 3, 16385, 0, 0x0820B7D0
	.globl MOSSDEEP_CITY_GYM_EventBgEvents
MOSSDEEP_CITY_GYM_EventBgEvents: @ 0x0850B078
	bg_event 4, 34, 0, 1, MossdeepCity_Gym_EventScript_0020B79C, 0, 0
	bg_event 8, 34, 0, 1, MossdeepCity_Gym_EventScript_0020B7AC, 0, 0
	.globl gMapEvents_MOSSDEEP_CITY_GYM
gMapEvents_MOSSDEEP_CITY_GYM: @ 0x0850B090
	map_events MOSSDEEP_CITY_GYM_EventObjects, MOSSDEEP_CITY_GYM_EventWarps, MOSSDEEP_CITY_GYM_EventCoordEvents, MOSSDEEP_CITY_GYM_EventBgEvents
	.globl MOSSDEEP_CITY_HOUSE1_EventObjects
MOSSDEEP_CITY_HOUSE1_EventObjects: @ 0x0850B0A4
	object_event 1, 44, 0, 3, 3, 3, 3, 1, 1, 0, 0, 0x0820C333, 0x0000
	object_event 2, 20, 0, 7, 4, 3, 9, 0, 0, 0, 0, 0x0820C363, 0x0000
	.globl MOSSDEEP_CITY_HOUSE1_EventWarps
MOSSDEEP_CITY_HOUSE1_EventWarps: @ 0x0850B0D4
	warp_def 3, 7, 0, 0, MAP_MOSSDEEP_CITY
	warp_def 4, 7, 0, 0, MAP_MOSSDEEP_CITY
	.globl gMapEvents_MOSSDEEP_CITY_HOUSE1
gMapEvents_MOSSDEEP_CITY_HOUSE1: @ 0x0850B0E4
	map_events MOSSDEEP_CITY_HOUSE1_EventObjects, MOSSDEEP_CITY_HOUSE1_EventWarps, 0, 0
	.globl MOSSDEEP_CITY_HOUSE2_EventObjects
MOSSDEEP_CITY_HOUSE2_EventObjects: @ 0x0850B0F8
	object_event 1, 65, 0, 6, 6, 3, 9, 0, 0, 0, 0, 0x0820C3D3, 0x0000
	object_event 2, 6, 0, 4, 4, 3, 8, 0, 0, 0, 0, 0x0820C3DC, 0x0000
	object_event 3, 211, 0, 4, 5, 3, 7, 0, 0, 0, 0, 0x0820C3E5, 0x03A6
	.globl MOSSDEEP_CITY_HOUSE2_EventWarps
MOSSDEEP_CITY_HOUSE2_EventWarps: @ 0x0850B140
	warp_def 3, 8, 0, 3, MAP_MOSSDEEP_CITY
	warp_def 4, 8, 0, 3, MAP_MOSSDEEP_CITY
	.globl gMapEvents_MOSSDEEP_CITY_HOUSE2
gMapEvents_MOSSDEEP_CITY_HOUSE2: @ 0x0850B150
	map_events MOSSDEEP_CITY_HOUSE2_EventObjects, MOSSDEEP_CITY_HOUSE2_EventWarps, 0, 0
	.globl MOSSDEEP_CITY_POKEMON_CENTER_1F_EventObjects
MOSSDEEP_CITY_POKEMON_CENTER_1F_EventObjects: @ 0x0850B164
	object_event 1, 58, 0, 7, 2, 3, 8, 0, 0, 0, 0, MossdeepCity_PokemonCenter_1F_EventScript_0020C4C1, 0x0000
	object_event 2, 20, 0, 8, 4, 3, 7, 0, 0, 0, 0, MossdeepCity_PokemonCenter_1F_EventScript_0020C4CF, 0x0000
	object_event 3, 8, 0, 3, 5, 3, 1, 0, 0, 0, 0, MossdeepCity_PokemonCenter_1F_EventScript_0020C4D8, 0x0000
	.globl MOSSDEEP_CITY_POKEMON_CENTER_1F_EventWarps
MOSSDEEP_CITY_POKEMON_CENTER_1F_EventWarps: @ 0x0850B1AC
	warp_def 7, 8, 3, 2, MAP_MOSSDEEP_CITY
	warp_def 6, 8, 3, 2, MAP_MOSSDEEP_CITY
	warp_def 1, 6, 4, 0, MAP_MOSSDEEP_CITY_POKEMON_CENTER_2F
	.globl gMapEvents_MOSSDEEP_CITY_POKEMON_CENTER_1F
gMapEvents_MOSSDEEP_CITY_POKEMON_CENTER_1F: @ 0x0850B1C4
	map_events MOSSDEEP_CITY_POKEMON_CENTER_1F_EventObjects, MOSSDEEP_CITY_POKEMON_CENTER_1F_EventWarps, 0, 0
	.globl MOSSDEEP_CITY_POKEMON_CENTER_2F_EventObjects
MOSSDEEP_CITY_POKEMON_CENTER_2F_EventObjects: @ 0x0850B1D8
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 3, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	object_event 5, 34, 0, 11, 7, 3, 5, 1, 1, 0, 0, MossdeepCity_PokemonCenter_2F_EventScript_0020C571, 0x0000
	.globl MOSSDEEP_CITY_POKEMON_CENTER_2F_EventWarps
MOSSDEEP_CITY_POKEMON_CENTER_2F_EventWarps: @ 0x0850B250
	warp_def 1, 6, 4, 2, MAP_MOSSDEEP_CITY_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_MOSSDEEP_CITY_POKEMON_CENTER_2F
gMapEvents_MOSSDEEP_CITY_POKEMON_CENTER_2F: @ 0x0850B268
	map_events MOSSDEEP_CITY_POKEMON_CENTER_2F_EventObjects, MOSSDEEP_CITY_POKEMON_CENTER_2F_EventWarps, 0, 0
	.globl MOSSDEEP_CITY_MART_EventObjects
MOSSDEEP_CITY_MART_EventObjects: @ 0x0850B27C
	object_event 1, 83, 0, 1, 3, 3, 10, 0, 0, 0, 0, 0x0820C5B3, 0x0000
	object_event 2, 34, 0, 1, 5, 3, 7, 0, 0, 0, 0, 0x0820C5E2, 0x0000
	object_event 3, 9, 0, 8, 3, 3, 3, 0, 1, 0, 0, 0x0820C5EB, 0x0000
	object_event 4, 49, 0, 5, 3, 3, 2, 1, 1, 0, 0, 0x0820C5F4, 0x0000
	.globl MOSSDEEP_CITY_MART_EventWarps
MOSSDEEP_CITY_MART_EventWarps: @ 0x0850B2DC
	warp_def 3, 7, 0, 4, MAP_MOSSDEEP_CITY
	warp_def 4, 7, 0, 4, MAP_MOSSDEEP_CITY
	.globl gMapEvents_MOSSDEEP_CITY_MART
gMapEvents_MOSSDEEP_CITY_MART: @ 0x0850B2EC
	map_events MOSSDEEP_CITY_MART_EventObjects, MOSSDEEP_CITY_MART_EventWarps, 0, 0
	.globl MOSSDEEP_CITY_HOUSE3_EventObjects
MOSSDEEP_CITY_HOUSE3_EventObjects: @ 0x0850B300
	object_event 1, 50, 0, 4, 4, 3, 10, 0, 0, 0, 0, 0x0820C6FB, 0x0000
	.globl MOSSDEEP_CITY_HOUSE3_EventWarps
MOSSDEEP_CITY_HOUSE3_EventWarps: @ 0x0850B318
	warp_def 3, 7, 0, 5, MAP_MOSSDEEP_CITY
	warp_def 4, 7, 0, 5, MAP_MOSSDEEP_CITY
	.globl gMapEvents_MOSSDEEP_CITY_HOUSE3
gMapEvents_MOSSDEEP_CITY_HOUSE3: @ 0x0850B328
	map_events MOSSDEEP_CITY_HOUSE3_EventObjects, MOSSDEEP_CITY_HOUSE3_EventWarps, 0, 0
	.globl MOSSDEEP_CITY_STEVENS_HOUSE_EventObjects
MOSSDEEP_CITY_STEVENS_HOUSE_EventObjects: @ 0x0850B33C
	object_event 1, 134, 0, 9, 6, 3, 10, 0, 0, 0, 0, MossdeepCity_StevensHouse_EventScript_0020C9A4, 0x03C7
	object_event 2, 59, 0, 4, 3, 3, 1, 1, 1, 0, 0, MossdeepCity_StevensHouse_EventScript_0020C8D3, 0x03C8
	object_event 3, 5, 0, 6, 4, 3, 76, 1, 1, 0, 0, MossdeepCity_StevensHouse_EventScript_0020C9AD, 0x02D7
	.globl MOSSDEEP_CITY_STEVENS_HOUSE_EventWarps
MOSSDEEP_CITY_STEVENS_HOUSE_EventWarps: @ 0x0850B384
	warp_def 3, 7, 0, 6, MAP_MOSSDEEP_CITY
	warp_def 4, 7, 0, 6, MAP_MOSSDEEP_CITY
	.globl MOSSDEEP_CITY_STEVENS_HOUSE_EventBgEvents
MOSSDEEP_CITY_STEVENS_HOUSE_EventBgEvents: @ 0x0850B394
	bg_event 0, 1, 0, 0, MossdeepCity_StevensHouse_EventScript_0020C99B, 0, 0
	bg_event 1, 1, 0, 0, MossdeepCity_StevensHouse_EventScript_0020C99B, 0, 0
	bg_event 10, 4, 3, 0, MossdeepCity_StevensHouse_EventScript_0020C99B, 0, 0
	bg_event 10, 6, 3, 0, MossdeepCity_StevensHouse_EventScript_0020C99B, 0, 0
	.globl gMapEvents_MOSSDEEP_CITY_STEVENS_HOUSE
gMapEvents_MOSSDEEP_CITY_STEVENS_HOUSE: @ 0x0850B3C4
	map_events MOSSDEEP_CITY_STEVENS_HOUSE_EventObjects, MOSSDEEP_CITY_STEVENS_HOUSE_EventWarps, 0, MOSSDEEP_CITY_STEVENS_HOUSE_EventBgEvents
	.globl MOSSDEEP_CITY_HOUSE4_EventObjects
MOSSDEEP_CITY_HOUSE4_EventObjects: @ 0x0850B3D8
	object_event 1, 20, 0, 3, 4, 3, 9, 0, 0, 0, 0, 0x0820CC5C, 0x0000
	object_event 2, 5, 0, 6, 6, 3, 5, 1, 0, 0, 0, 0x0820CC7B, 0x0000
	object_event 3, 203, 0, 2, 4, 3, 1, 1, 1, 0, 0, 0x0820CCA2, 0x0000
	.globl MOSSDEEP_CITY_HOUSE4_EventWarps
MOSSDEEP_CITY_HOUSE4_EventWarps: @ 0x0850B420
	warp_def 4, 7, 0, 7, MAP_MOSSDEEP_CITY
	warp_def 3, 7, 0, 7, MAP_MOSSDEEP_CITY
	.globl gMapEvents_MOSSDEEP_CITY_HOUSE4
gMapEvents_MOSSDEEP_CITY_HOUSE4: @ 0x0850B430
	map_events MOSSDEEP_CITY_HOUSE4_EventObjects, MOSSDEEP_CITY_HOUSE4_EventWarps, 0, 0
	.globl MOSSDEEP_CITY_SPACE_CENTER_1F_EventObjects
MOSSDEEP_CITY_SPACE_CENTER_1F_EventObjects: @ 0x0850B444
	object_event 1, 46, 0, 7, 2, 3, 7, 0, 0, 0, 0, MossdeepCity_SpaceCenter_1F_EventScript_0020CDF4, 0x0000
	object_event 2, 46, 0, 2, 2, 3, 7, 0, 0, 0, 0, MossdeepCity_SpaceCenter_1F_EventScript_0020CE7F, 0x0000
	object_event 3, 49, 0, 6, 6, 3, 9, 0, 0, 0, 0, MossdeepCity_SpaceCenter_1F_EventScript_0020CEAA, 0x0000
	object_event 4, 29, 0, 10, 2, 3, 7, 0, 0, 0, 0, MossdeepCity_SpaceCenter_1F_EventScript_0020CF84, 0x0000
	object_event 5, 26, 0, 14, 7, 3, 3, 1, 1, 0, 0, MossdeepCity_SpaceCenter_1F_EventScript_0020CF49, 0x0000
	object_event 6, 120, 0, 12, 9, 3, 9, 1, 1, 1, 2, 0x0820CFF6, 0x02F4
	object_event 7, 119, 0, 11, 6, 3, 9, 1, 1, 1, 2, 0x0820D00D, 0x02F4
	object_event 8, 119, 0, 10, 2, 3, 8, 1, 1, 1, 2, 0x0820D024, 0x02F4
	object_event 9, 119, 0, 13, 2, 3, 8, 1, 1, 1, 0, 0x0820D03B, 0x02F4
	object_event 10, 5, 0, 2, 5, 0, 76, 1, 1, 0, 0, MossdeepCity_SpaceCenter_1F_EventScript_0020CFEB, 0x02E1
	object_event 11, 134, 0, 1, 4, 3, 8, 1, 1, 0, 0, MossdeepCity_SpaceCenter_1F_EventScript_0020CFD5, 0x02F1
	.globl MOSSDEEP_CITY_SPACE_CENTER_1F_EventWarps
MOSSDEEP_CITY_SPACE_CENTER_1F_EventWarps: @ 0x0850B54C
	warp_def 7, 9, 0, 8, MAP_MOSSDEEP_CITY
	warp_def 8, 9, 0, 8, MAP_MOSSDEEP_CITY
	warp_def 13, 1, 0, 0, MAP_MOSSDEEP_CITY_SPACE_CENTER_2F
	.globl gMapEvents_MOSSDEEP_CITY_SPACE_CENTER_1F
gMapEvents_MOSSDEEP_CITY_SPACE_CENTER_1F: @ 0x0850B564
	map_events MOSSDEEP_CITY_SPACE_CENTER_1F_EventObjects, MOSSDEEP_CITY_SPACE_CENTER_1F_EventWarps, 0, 0
	.globl MOSSDEEP_CITY_SPACE_CENTER_2F_EventObjects
MOSSDEEP_CITY_SPACE_CENTER_2F_EventObjects: @ 0x0850B578
	object_event 1, 15, 0, 6, 2, 3, 7, 0, 0, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_0020D82D, 0x0000
	object_event 2, 48, 0, 11, 8, 3, 7, 0, 0, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_0020D7F2, 0x0000
	object_event 3, 46, 0, 5, 6, 3, 2, 1, 1, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_0020D7B7, 0x0000
	object_event 4, 134, 0, 1, 8, 3, 8, 1, 1, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_0020D8A4, 0x035F
	object_event 5, 119, 0, 12, 2, 3, 10, 1, 1, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_0020D868, 0x035E
	object_event 6, 119, 0, 13, 3, 3, 7, 1, 1, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_0020D87A, 0x035E
	object_event 7, 119, 0, 14, 2, 3, 9, 1, 1, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_0020D871, 0x035E
	object_event 8, 119, 0, 0, 8, 3, 10, 1, 1, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_0020D883, 0x035E
	object_event 9, 196, 0, 1, 9, 3, 7, 1, 1, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_0020D899, 0x035E
	.globl MOSSDEEP_CITY_SPACE_CENTER_2F_EventWarps
MOSSDEEP_CITY_SPACE_CENTER_2F_EventWarps: @ 0x0850B650
	warp_def 13, 1, 0, 2, MAP_MOSSDEEP_CITY_SPACE_CENTER_1F
	.globl gMapEvents_MOSSDEEP_CITY_SPACE_CENTER_2F
gMapEvents_MOSSDEEP_CITY_SPACE_CENTER_2F: @ 0x0850B658
	map_events MOSSDEEP_CITY_SPACE_CENTER_2F_EventObjects, MOSSDEEP_CITY_SPACE_CENTER_2F_EventWarps, 0, 0
	.globl MOSSDEEP_CITY_GAME_CORNER_1F_EventObjects
MOSSDEEP_CITY_GAME_CORNER_1F_EventObjects: @ 0x0850B66C
	object_event 1, 21, 0, 6, 2, 0, 8, 0, 0, 0, 0, MossdeepCity_GameCorner_1F_EventScript_0020E04B, 0x0000
	object_event 2, 65, 0, 4, 2, 0, 8, 0, 0, 0, 0, MossdeepCity_GameCorner_1F_EventScript_0020E042, 0x0000
	.globl MOSSDEEP_CITY_GAME_CORNER_1F_EventWarps
MOSSDEEP_CITY_GAME_CORNER_1F_EventWarps: @ 0x0850B69C
	warp_def 5, 9, 0, 9, MAP_MOSSDEEP_CITY
	warp_def 6, 9, 0, 9, MAP_MOSSDEEP_CITY
	warp_def 2, 0, 0, 0, MAP_MOSSDEEP_CITY_GAME_CORNER_B1F
	.globl MOSSDEEP_CITY_GAME_CORNER_1F_EventBgEvents
MOSSDEEP_CITY_GAME_CORNER_1F_EventBgEvents: @ 0x0850B6B4
	bg_event 3, 0, 0, 0, MossdeepCity_GameCorner_1F_EventScript_0020E054, 0, 0
	bg_event 0, 1, 0, 0, 0x08247B79, 0, 0
	bg_event 1, 1, 0, 0, 0x08247B72, 0, 0
	.globl gMapEvents_MOSSDEEP_CITY_GAME_CORNER_1F
gMapEvents_MOSSDEEP_CITY_GAME_CORNER_1F: @ 0x0850B6D8
	map_events MOSSDEEP_CITY_GAME_CORNER_1F_EventObjects, MOSSDEEP_CITY_GAME_CORNER_1F_EventWarps, 0, MOSSDEEP_CITY_GAME_CORNER_1F_EventBgEvents
	.globl MOSSDEEP_CITY_GAME_CORNER_B1F_EventObjects
MOSSDEEP_CITY_GAME_CORNER_B1F_EventObjects: @ 0x0850B6EC
	object_event 1, 240, 0, 6, 5, 3, 9, 0, 0, 0, 0, 0x00000000, 0x0000
	.globl MOSSDEEP_CITY_GAME_CORNER_B1F_EventWarps
MOSSDEEP_CITY_GAME_CORNER_B1F_EventWarps: @ 0x0850B704
	warp_def 3, 1, 0, 2, MAP_MOSSDEEP_CITY_GAME_CORNER_1F
	.globl gMapEvents_MOSSDEEP_CITY_GAME_CORNER_B1F
gMapEvents_MOSSDEEP_CITY_GAME_CORNER_B1F: @ 0x0850B70C
	map_events MOSSDEEP_CITY_GAME_CORNER_B1F_EventObjects, MOSSDEEP_CITY_GAME_CORNER_B1F_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_GYM_1F_EventObjects
SOOTOPOLIS_CITY_GYM_1F_EventObjects: @ 0x0850B720
	object_event 1, 218, 0, 8, 2, 0, 8, 0, 0, 0, 0, 0x0820E31C, 0x0000
	object_event 2, 23, 0, 7, 24, 3, 8, 0, 0, 0, 0, SootopolisCity_Gym_1F_EventScript_0020E418, 0x0000
	.globl SOOTOPOLIS_CITY_GYM_1F_EventWarps
SOOTOPOLIS_CITY_GYM_1F_EventWarps: @ 0x0850B750
	warp_def 8, 25, 0, 2, MAP_SOOTOPOLIS_CITY
	warp_def 9, 25, 0, 2, MAP_SOOTOPOLIS_CITY
	warp_def 11, 22, 3, 0, MAP_SOOTOPOLIS_CITY_GYM_B1F
	.globl SOOTOPOLIS_CITY_GYM_1F_EventBgEvents
SOOTOPOLIS_CITY_GYM_1F_EventBgEvents: @ 0x0850B768
	bg_event 6, 24, 0, 0, SootopolisCity_Gym_1F_EventScript_0020E437, 0, 0
	bg_event 10, 24, 0, 1, SootopolisCity_Gym_1F_EventScript_0020E447, 0, 0
	.globl gMapEvents_SOOTOPOLIS_CITY_GYM_1F
gMapEvents_SOOTOPOLIS_CITY_GYM_1F: @ 0x0850B780
	map_events SOOTOPOLIS_CITY_GYM_1F_EventObjects, SOOTOPOLIS_CITY_GYM_1F_EventWarps, 0, SOOTOPOLIS_CITY_GYM_1F_EventBgEvents
	.globl SOOTOPOLIS_CITY_GYM_B1F_EventObjects
SOOTOPOLIS_CITY_GYM_B1F_EventObjects: @ 0x0850B794
	object_event 1, 47, 0, 7, 17, 3, 10, 0, 0, 1, 1, 0x0820EAC7, 0x0000
	object_event 2, 45, 0, 9, 19, 3, 9, 0, 0, 1, 1, 0x0820EB0C, 0x0000
	object_event 3, 20, 0, 12, 7, 3, 9, 0, 0, 1, 1, 0x0820EAF5, 0x0000
	object_event 4, 45, 0, 11, 9, 0, 7, 0, 0, 1, 5, 0x0820EB23, 0x0000
	object_event 5, 45, 0, 5, 6, 3, 8, 0, 0, 1, 4, 0x0820EB51, 0x0000
	object_event 6, 18, 0, 7, 8, 3, 10, 0, 0, 1, 2, 0x0820EB68, 0x0000
	object_event 7, 47, 0, 4, 8, 3, 10, 0, 0, 1, 2, 0x0820EADE, 0x0000
	object_event 8, 45, 0, 9, 7, 3, 8, 0, 0, 1, 3, 0x0820EB3A, 0x0000
	object_event 9, 20, 0, 6, 13, 3, 10, 1, 1, 1, 3, 0x0820EB96, 0x0000
	object_event 10, 18, 0, 10, 13, 3, 9, 1, 1, 1, 3, 0x0820EB7F, 0x0000
	.globl SOOTOPOLIS_CITY_GYM_B1F_EventWarps
SOOTOPOLIS_CITY_GYM_B1F_EventWarps: @ 0x0850B884
	warp_def 11, 22, 3, 2, MAP_SOOTOPOLIS_CITY_GYM_1F
	.globl gMapEvents_SOOTOPOLIS_CITY_GYM_B1F
gMapEvents_SOOTOPOLIS_CITY_GYM_B1F: @ 0x0850B88C
	map_events SOOTOPOLIS_CITY_GYM_B1F_EventObjects, SOOTOPOLIS_CITY_GYM_B1F_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_POKEMON_CENTER_1F_EventObjects
SOOTOPOLIS_CITY_POKEMON_CENTER_1F_EventObjects: @ 0x0850B8A0
	object_event 1, 58, 0, 7, 2, 3, 8, 0, 0, 0, 0, SootopolisCity_PokemonCenter_1F_EventScript_0020EFE4, 0x0000
	object_event 2, 48, 0, 12, 4, 3, 2, 1, 1, 0, 0, SootopolisCity_PokemonCenter_1F_EventScript_0020EFF2, 0x0000
	object_event 3, 34, 0, 4, 7, 3, 5, 1, 0, 0, 0, SootopolisCity_PokemonCenter_1F_EventScript_0020F01C, 0x0000
	object_event 4, 16, 0, 2, 3, 3, 2, 1, 1, 0, 0, 0x08276B72, 0x0000
	.globl SOOTOPOLIS_CITY_POKEMON_CENTER_1F_EventWarps
SOOTOPOLIS_CITY_POKEMON_CENTER_1F_EventWarps: @ 0x0850B900
	warp_def 7, 8, 3, 0, MAP_SOOTOPOLIS_CITY
	warp_def 6, 8, 3, 0, MAP_SOOTOPOLIS_CITY
	warp_def 1, 6, 4, 0, MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_2F
	.globl gMapEvents_SOOTOPOLIS_CITY_POKEMON_CENTER_1F
gMapEvents_SOOTOPOLIS_CITY_POKEMON_CENTER_1F: @ 0x0850B918
	map_events SOOTOPOLIS_CITY_POKEMON_CENTER_1F_EventObjects, SOOTOPOLIS_CITY_POKEMON_CENTER_1F_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_POKEMON_CENTER_2F_EventObjects
SOOTOPOLIS_CITY_POKEMON_CENTER_2F_EventObjects: @ 0x0850B92C
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 3, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	.globl SOOTOPOLIS_CITY_POKEMON_CENTER_2F_EventWarps
SOOTOPOLIS_CITY_POKEMON_CENTER_2F_EventWarps: @ 0x0850B98C
	warp_def 1, 6, 4, 2, MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_SOOTOPOLIS_CITY_POKEMON_CENTER_2F
gMapEvents_SOOTOPOLIS_CITY_POKEMON_CENTER_2F: @ 0x0850B9A4
	map_events SOOTOPOLIS_CITY_POKEMON_CENTER_2F_EventObjects, SOOTOPOLIS_CITY_POKEMON_CENTER_2F_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_MART_EventObjects
SOOTOPOLIS_CITY_MART_EventObjects: @ 0x0850B9B8
	object_event 1, 83, 0, 1, 3, 3, 10, 0, 0, 0, 0, 0x0820F1B8, 0x0000
	object_event 2, 17, 0, 5, 5, 3, 10, 0, 0, 0, 0, 0x0820F1E6, 0x0000
	object_event 3, 48, 0, 9, 5, 3, 10, 0, 0, 0, 0, 0x0820F210, 0x0000
	.globl SOOTOPOLIS_CITY_MART_EventWarps
SOOTOPOLIS_CITY_MART_EventWarps: @ 0x0850BA00
	warp_def 3, 7, 0, 1, MAP_SOOTOPOLIS_CITY
	warp_def 4, 7, 0, 1, MAP_SOOTOPOLIS_CITY
	.globl gMapEvents_SOOTOPOLIS_CITY_MART
gMapEvents_SOOTOPOLIS_CITY_MART: @ 0x0850BA10
	map_events SOOTOPOLIS_CITY_MART_EventObjects, SOOTOPOLIS_CITY_MART_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_HOUSE1_EventObjects
SOOTOPOLIS_CITY_HOUSE1_EventObjects: @ 0x0850BA24
	object_event 1, 44, 0, 2, 4, 3, 10, 0, 0, 0, 0, 0x0820F301, 0x0000
	object_event 2, 204, 0, 2, 3, 3, 8, 0, 0, 0, 0, 0x0820F342, 0x0000
	.globl SOOTOPOLIS_CITY_HOUSE1_EventWarps
SOOTOPOLIS_CITY_HOUSE1_EventWarps: @ 0x0850BA54
	warp_def 3, 6, 0, 4, MAP_SOOTOPOLIS_CITY
	warp_def 4, 6, 0, 4, MAP_SOOTOPOLIS_CITY
	.globl gMapEvents_SOOTOPOLIS_CITY_HOUSE1
gMapEvents_SOOTOPOLIS_CITY_HOUSE1: @ 0x0850BA64
	map_events SOOTOPOLIS_CITY_HOUSE1_EventObjects, SOOTOPOLIS_CITY_HOUSE1_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_HOUSE2_EventObjects
SOOTOPOLIS_CITY_HOUSE2_EventObjects: @ 0x0850BA78
	object_event 1, 22, 0, 3, 3, 3, 10, 0, 0, 0, 0, 0x0820F3C7, 0x0000
	.globl SOOTOPOLIS_CITY_HOUSE2_EventWarps
SOOTOPOLIS_CITY_HOUSE2_EventWarps: @ 0x0850BA90
	warp_def 3, 6, 0, 5, MAP_SOOTOPOLIS_CITY
	warp_def 4, 6, 0, 5, MAP_SOOTOPOLIS_CITY
	.globl gMapEvents_SOOTOPOLIS_CITY_HOUSE2
gMapEvents_SOOTOPOLIS_CITY_HOUSE2: @ 0x0850BAA0
	map_events SOOTOPOLIS_CITY_HOUSE2_EventObjects, SOOTOPOLIS_CITY_HOUSE2_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_HOUSE3_EventObjects
SOOTOPOLIS_CITY_HOUSE3_EventObjects: @ 0x0850BAB4
	object_event 1, 26, 0, 2, 4, 3, 8, 0, 0, 0, 0, 0x0820F47A, 0x0000
	object_event 2, 10, 0, 6, 4, 3, 2, 1, 1, 0, 0, 0x0820F4A3, 0x0000
	.globl SOOTOPOLIS_CITY_HOUSE3_EventWarps
SOOTOPOLIS_CITY_HOUSE3_EventWarps: @ 0x0850BAE4
	warp_def 3, 6, 0, 6, MAP_SOOTOPOLIS_CITY
	warp_def 4, 6, 0, 6, MAP_SOOTOPOLIS_CITY
	.globl gMapEvents_SOOTOPOLIS_CITY_HOUSE3
gMapEvents_SOOTOPOLIS_CITY_HOUSE3: @ 0x0850BAF4
	map_events SOOTOPOLIS_CITY_HOUSE3_EventObjects, SOOTOPOLIS_CITY_HOUSE3_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_HOUSE4_EventObjects
SOOTOPOLIS_CITY_HOUSE4_EventObjects: @ 0x0850BB08
	object_event 1, 19, 0, 2, 4, 3, 10, 0, 0, 0, 0, 0x0820F594, 0x0000
	object_event 2, 26, 0, 5, 2, 3, 7, 1, 2, 0, 0, 0x0820F59D, 0x0000
	object_event 3, 210, 0, 2, 3, 3, 1, 1, 1, 0, 0, 0x0820F5A6, 0x0000
	.globl SOOTOPOLIS_CITY_HOUSE4_EventWarps
SOOTOPOLIS_CITY_HOUSE4_EventWarps: @ 0x0850BB50
	warp_def 3, 6, 0, 7, MAP_SOOTOPOLIS_CITY
	warp_def 4, 6, 0, 7, MAP_SOOTOPOLIS_CITY
	.globl gMapEvents_SOOTOPOLIS_CITY_HOUSE4
gMapEvents_SOOTOPOLIS_CITY_HOUSE4: @ 0x0850BB60
	map_events SOOTOPOLIS_CITY_HOUSE4_EventObjects, SOOTOPOLIS_CITY_HOUSE4_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_HOUSE5_EventObjects
SOOTOPOLIS_CITY_HOUSE5_EventObjects: @ 0x0850BB74
	object_event 1, 39, 0, 3, 3, 3, 10, 0, 0, 0, 0, 0x0820F658, 0x0000
	object_event 2, 14, 0, 6, 3, 3, 9, 0, 0, 0, 0, 0x0820F661, 0x0000
	.globl SOOTOPOLIS_CITY_HOUSE5_EventWarps
SOOTOPOLIS_CITY_HOUSE5_EventWarps: @ 0x0850BBA4
	warp_def 3, 6, 0, 8, MAP_SOOTOPOLIS_CITY
	warp_def 4, 6, 0, 8, MAP_SOOTOPOLIS_CITY
	.globl gMapEvents_SOOTOPOLIS_CITY_HOUSE5
gMapEvents_SOOTOPOLIS_CITY_HOUSE5: @ 0x0850BBB4
	map_events SOOTOPOLIS_CITY_HOUSE5_EventObjects, SOOTOPOLIS_CITY_HOUSE5_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_HOUSE6_EventObjects
SOOTOPOLIS_CITY_HOUSE6_EventObjects: @ 0x0850BBC8
	object_event 1, 20, 0, 4, 3, 3, 2, 1, 1, 0, 0, 0x0820F6D1, 0x0000
	.globl SOOTOPOLIS_CITY_HOUSE6_EventWarps
SOOTOPOLIS_CITY_HOUSE6_EventWarps: @ 0x0850BBE0
	warp_def 3, 6, 0, 9, MAP_SOOTOPOLIS_CITY
	warp_def 4, 6, 0, 9, MAP_SOOTOPOLIS_CITY
	.globl gMapEvents_SOOTOPOLIS_CITY_HOUSE6
gMapEvents_SOOTOPOLIS_CITY_HOUSE6: @ 0x0850BBF0
	map_events SOOTOPOLIS_CITY_HOUSE6_EventObjects, SOOTOPOLIS_CITY_HOUSE6_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_HOUSE7_EventObjects
SOOTOPOLIS_CITY_HOUSE7_EventObjects: @ 0x0850BC04
	object_event 1, 29, 0, 5, 3, 3, 9, 0, 0, 0, 0, 0x0820F7BB, 0x0000
	object_event 2, 18, 0, 1, 4, 3, 2, 1, 1, 0, 0, 0x0820F7C4, 0x0000
	.globl SOOTOPOLIS_CITY_HOUSE7_EventWarps
SOOTOPOLIS_CITY_HOUSE7_EventWarps: @ 0x0850BC34
	warp_def 3, 6, 0, 10, MAP_SOOTOPOLIS_CITY
	warp_def 4, 6, 0, 10, MAP_SOOTOPOLIS_CITY
	.globl gMapEvents_SOOTOPOLIS_CITY_HOUSE7
gMapEvents_SOOTOPOLIS_CITY_HOUSE7: @ 0x0850BC44
	map_events SOOTOPOLIS_CITY_HOUSE7_EventObjects, SOOTOPOLIS_CITY_HOUSE7_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_EventObjects
SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_EventObjects: @ 0x0850BC58
	object_event 1, 50, 0, 2, 4, 3, 10, 0, 0, 0, 0, 0x0820F8F3, 0x0000
	object_event 2, 55, 0, 5, 4, 3, 9, 0, 0, 0, 0, 0x0820F862, 0x0000
	.globl SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_EventWarps
SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_EventWarps: @ 0x0850BC88
	warp_def 3, 6, 0, 11, MAP_SOOTOPOLIS_CITY
	warp_def 4, 6, 0, 11, MAP_SOOTOPOLIS_CITY
	.globl SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_EventBgEvents
SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_EventBgEvents: @ 0x0850BC98
	bg_event 5, 1, 0, 0, 0x0820F984, 0, 0
	bg_event 2, 1, 0, 0, 0x0820F992, 0, 0
	.globl gMapEvents_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE
gMapEvents_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE: @ 0x0850BCB0
	map_events SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_EventObjects, SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_EventWarps, 0, SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_EventBgEvents
	.globl SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_EventObjects
SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_EventObjects: @ 0x0850BCC4
	object_event 1, 29, 0, 6, 4, 0, 10, 0, 0, 0, 0, SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FE31, 0x0000
	.globl SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_EventWarps
SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_EventWarps: @ 0x0850BCDC
	warp_def 3, 7, 0, 12, MAP_SOOTOPOLIS_CITY
	warp_def 4, 7, 0, 12, MAP_SOOTOPOLIS_CITY
	warp_def 3, 1, 3, 0, MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F
	.globl gMapEvents_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F
gMapEvents_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F: @ 0x0850BCF4
	map_events SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_EventObjects, SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F_EventObjects
SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F_EventObjects: @ 0x0850BD08
	object_event 1, 240, 0, 6, 5, 0, 9, 1, 1, 0, 0, 0x00000000, 0x0000
	.globl SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F_EventWarps
SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F_EventWarps: @ 0x0850BD20
	warp_def 3, 1, 0, 2, MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F
	.globl gMapEvents_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F
gMapEvents_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F: @ 0x0850BD28
	map_events SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F_EventObjects, SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_SIDNEYS_ROOM_EventObjects
EVER_GRANDE_CITY_SIDNEYS_ROOM_EventObjects: @ 0x0850BD3C
	object_event 1, 121, 0, 6, 5, 3, 8, 0, 0, 0, 0, 0x08210249, 0x0000
	.globl EVER_GRANDE_CITY_SIDNEYS_ROOM_EventWarps
EVER_GRANDE_CITY_SIDNEYS_ROOM_EventWarps: @ 0x0850BD54
	warp_def 6, 13, 3, 1, MAP_EVER_GRANDE_CITY_HALL5
	warp_def 6, 2, 0, 0, MAP_EVER_GRANDE_CITY_HALL1
	.globl gMapEvents_EVER_GRANDE_CITY_SIDNEYS_ROOM
gMapEvents_EVER_GRANDE_CITY_SIDNEYS_ROOM: @ 0x0850BD64
	map_events EVER_GRANDE_CITY_SIDNEYS_ROOM_EventObjects, EVER_GRANDE_CITY_SIDNEYS_ROOM_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_PHOEBES_ROOM_EventObjects
EVER_GRANDE_CITY_PHOEBES_ROOM_EventObjects: @ 0x0850BD78
	object_event 1, 122, 0, 6, 5, 3, 8, 0, 0, 0, 0, 0x082103C8, 0x0000
	.globl EVER_GRANDE_CITY_PHOEBES_ROOM_EventWarps
EVER_GRANDE_CITY_PHOEBES_ROOM_EventWarps: @ 0x0850BD90
	warp_def 6, 13, 3, 1, MAP_EVER_GRANDE_CITY_HALL1
	warp_def 6, 2, 0, 0, MAP_EVER_GRANDE_CITY_HALL2
	.globl gMapEvents_EVER_GRANDE_CITY_PHOEBES_ROOM
gMapEvents_EVER_GRANDE_CITY_PHOEBES_ROOM: @ 0x0850BDA0
	map_events EVER_GRANDE_CITY_PHOEBES_ROOM_EventObjects, EVER_GRANDE_CITY_PHOEBES_ROOM_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_GLACIAS_ROOM_EventObjects
EVER_GRANDE_CITY_GLACIAS_ROOM_EventObjects: @ 0x0850BDB4
	object_event 1, 123, 0, 6, 5, 3, 8, 0, 0, 0, 0, 0x0821057A, 0x0000
	.globl EVER_GRANDE_CITY_GLACIAS_ROOM_EventWarps
EVER_GRANDE_CITY_GLACIAS_ROOM_EventWarps: @ 0x0850BDCC
	warp_def 6, 13, 3, 1, MAP_EVER_GRANDE_CITY_HALL2
	warp_def 6, 2, 0, 0, MAP_EVER_GRANDE_CITY_HALL3
	.globl gMapEvents_EVER_GRANDE_CITY_GLACIAS_ROOM
gMapEvents_EVER_GRANDE_CITY_GLACIAS_ROOM: @ 0x0850BDDC
	map_events EVER_GRANDE_CITY_GLACIAS_ROOM_EventObjects, EVER_GRANDE_CITY_GLACIAS_ROOM_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_DRAKES_ROOM_EventObjects
EVER_GRANDE_CITY_DRAKES_ROOM_EventObjects: @ 0x0850BDF0
	object_event 1, 124, 0, 6, 5, 3, 8, 0, 0, 0, 0, 0x08210715, 0x0000
	.globl EVER_GRANDE_CITY_DRAKES_ROOM_EventWarps
EVER_GRANDE_CITY_DRAKES_ROOM_EventWarps: @ 0x0850BE08
	warp_def 6, 13, 3, 1, MAP_EVER_GRANDE_CITY_HALL3
	warp_def 6, 2, 0, 0, MAP_EVER_GRANDE_CITY_HALL4
	.globl gMapEvents_EVER_GRANDE_CITY_DRAKES_ROOM
gMapEvents_EVER_GRANDE_CITY_DRAKES_ROOM: @ 0x0850BE18
	map_events EVER_GRANDE_CITY_DRAKES_ROOM_EventObjects, EVER_GRANDE_CITY_DRAKES_ROOM_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_CHAMPIONS_ROOM_EventObjects
EVER_GRANDE_CITY_CHAMPIONS_ROOM_EventObjects: @ 0x0850BE2C
	object_event 1, 133, 0, 6, 5, 3, 8, 0, 0, 0, 0, 0x00000000, 0x0000
	object_event 2, 240, 0, 6, 12, 3, 7, 0, 0, 0, 0, 0x00000000, 0x0398
	object_event 3, 64, 0, 6, 12, 3, 7, 0, 0, 0, 0, 0x00000000, 0x0399
	.globl EVER_GRANDE_CITY_CHAMPIONS_ROOM_EventWarps
EVER_GRANDE_CITY_CHAMPIONS_ROOM_EventWarps: @ 0x0850BE74
	warp_def 6, 12, 3, 1, MAP_EVER_GRANDE_CITY_HALL4
	warp_def 6, 2, 0, 0, MAP_EVER_GRANDE_CITY_HALL_OF_FAME
	.globl gMapEvents_EVER_GRANDE_CITY_CHAMPIONS_ROOM
gMapEvents_EVER_GRANDE_CITY_CHAMPIONS_ROOM: @ 0x0850BE84
	map_events EVER_GRANDE_CITY_CHAMPIONS_ROOM_EventObjects, EVER_GRANDE_CITY_CHAMPIONS_ROOM_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_HALL1_EventObjects
EVER_GRANDE_CITY_HALL1_EventObjects: @ 0x00000000
	.globl EVER_GRANDE_CITY_HALL1_EventWarps
EVER_GRANDE_CITY_HALL1_EventWarps: @ 0x0850BE98
	warp_def 5, 12, 3, 1, MAP_EVER_GRANDE_CITY_SIDNEYS_ROOM
	warp_def 5, 2, 0, 0, MAP_EVER_GRANDE_CITY_PHOEBES_ROOM
	warp_def 4, 12, 3, 1, MAP_EVER_GRANDE_CITY_SIDNEYS_ROOM
	warp_def 6, 12, 3, 1, MAP_EVER_GRANDE_CITY_SIDNEYS_ROOM
	.globl gMapEvents_EVER_GRANDE_CITY_HALL1
gMapEvents_EVER_GRANDE_CITY_HALL1: @ 0x0850BEB8
	map_events 0, EVER_GRANDE_CITY_HALL1_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_HALL2_EventObjects
EVER_GRANDE_CITY_HALL2_EventObjects: @ 0x00000000
	.globl EVER_GRANDE_CITY_HALL2_EventWarps
EVER_GRANDE_CITY_HALL2_EventWarps: @ 0x0850BECC
	warp_def 5, 12, 3, 1, MAP_EVER_GRANDE_CITY_PHOEBES_ROOM
	warp_def 5, 2, 0, 0, MAP_EVER_GRANDE_CITY_GLACIAS_ROOM
	warp_def 4, 12, 3, 1, MAP_EVER_GRANDE_CITY_PHOEBES_ROOM
	warp_def 6, 12, 3, 1, MAP_EVER_GRANDE_CITY_PHOEBES_ROOM
	.globl gMapEvents_EVER_GRANDE_CITY_HALL2
gMapEvents_EVER_GRANDE_CITY_HALL2: @ 0x0850BEEC
	map_events 0, EVER_GRANDE_CITY_HALL2_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_HALL3_EventObjects
EVER_GRANDE_CITY_HALL3_EventObjects: @ 0x00000000
	.globl EVER_GRANDE_CITY_HALL3_EventWarps
EVER_GRANDE_CITY_HALL3_EventWarps: @ 0x0850BF00
	warp_def 5, 12, 3, 1, MAP_EVER_GRANDE_CITY_GLACIAS_ROOM
	warp_def 5, 2, 0, 0, MAP_EVER_GRANDE_CITY_DRAKES_ROOM
	warp_def 4, 12, 3, 1, MAP_EVER_GRANDE_CITY_GLACIAS_ROOM
	warp_def 6, 12, 3, 1, MAP_EVER_GRANDE_CITY_GLACIAS_ROOM
	.globl gMapEvents_EVER_GRANDE_CITY_HALL3
gMapEvents_EVER_GRANDE_CITY_HALL3: @ 0x0850BF20
	map_events 0, EVER_GRANDE_CITY_HALL3_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_HALL4_EventObjects
EVER_GRANDE_CITY_HALL4_EventObjects: @ 0x00000000
	.globl EVER_GRANDE_CITY_HALL4_EventWarps
EVER_GRANDE_CITY_HALL4_EventWarps: @ 0x0850BF34
	warp_def 5, 33, 3, 1, MAP_EVER_GRANDE_CITY_DRAKES_ROOM
	warp_def 5, 2, 0, 0, MAP_EVER_GRANDE_CITY_CHAMPIONS_ROOM
	.globl gMapEvents_EVER_GRANDE_CITY_HALL4
gMapEvents_EVER_GRANDE_CITY_HALL4: @ 0x0850BF44
	map_events 0, EVER_GRANDE_CITY_HALL4_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_HALL5_EventObjects
EVER_GRANDE_CITY_HALL5_EventObjects: @ 0x00000000
	.globl EVER_GRANDE_CITY_HALL5_EventWarps
EVER_GRANDE_CITY_HALL5_EventWarps: @ 0x0850BF58
	warp_def 5, 12, 3, 2, MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F
	warp_def 5, 2, 0, 0, MAP_EVER_GRANDE_CITY_SIDNEYS_ROOM
	warp_def 4, 12, 3, 2, MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F
	warp_def 6, 12, 3, 2, MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F
	.globl gMapEvents_EVER_GRANDE_CITY_HALL5
gMapEvents_EVER_GRANDE_CITY_HALL5: @ 0x0850BF78
	map_events 0, EVER_GRANDE_CITY_HALL5_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_POKEMON_LEAGUE_1F_EventObjects
EVER_GRANDE_CITY_POKEMON_LEAGUE_1F_EventObjects: @ 0x0850BF8C
	object_event 1, 58, 0, 3, 2, 3, 8, 0, 0, 0, 0, EverGrandeCity_PokemonLeague_1F_EventScript_002110FE, 0x0000
	object_event 2, 83, 0, 16, 2, 3, 8, 0, 0, 0, 0, EverGrandeCity_PokemonLeague_1F_EventScript_0021110C, 0x0000
	object_event 3, 33, 0, 8, 2, 3, 8, 1, 1, 0, 0, EverGrandeCity_PokemonLeague_1F_EventScript_00211136, 0x0000
	object_event 4, 33, 0, 11, 2, 3, 8, 1, 1, 0, 0, EverGrandeCity_PokemonLeague_1F_EventScript_00211136, 0x0000
	.globl EVER_GRANDE_CITY_POKEMON_LEAGUE_1F_EventWarps
EVER_GRANDE_CITY_POKEMON_LEAGUE_1F_EventWarps: @ 0x0850BFEC
	warp_def 9, 11, 3, 0, MAP_EVER_GRANDE_CITY
	warp_def 10, 11, 3, 0, MAP_EVER_GRANDE_CITY
	warp_def 9, 1, 3, 0, MAP_EVER_GRANDE_CITY_HALL5
	warp_def 10, 1, 3, 0, MAP_EVER_GRANDE_CITY_HALL5
	warp_def 1, 7, 4, 0, MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_2F
	.globl gMapEvents_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F
gMapEvents_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F: @ 0x0850C014
	map_events EVER_GRANDE_CITY_POKEMON_LEAGUE_1F_EventObjects, EVER_GRANDE_CITY_POKEMON_LEAGUE_1F_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_HALL_OF_FAME_EventObjects
EVER_GRANDE_CITY_HALL_OF_FAME_EventObjects: @ 0x0850C028
	object_event 1, 133, 0, 6, 16, 3, 7, 0, 0, 0, 0, 0x00000000, 0x0000
	.globl EVER_GRANDE_CITY_HALL_OF_FAME_EventWarps
EVER_GRANDE_CITY_HALL_OF_FAME_EventWarps: @ 0x0850C040
	warp_def 7, 11, 3, 1, MAP_EVER_GRANDE_CITY_CHAMPIONS_ROOM
	.globl gMapEvents_EVER_GRANDE_CITY_HALL_OF_FAME
gMapEvents_EVER_GRANDE_CITY_HALL_OF_FAME: @ 0x0850C048
	map_events EVER_GRANDE_CITY_HALL_OF_FAME_EventObjects, EVER_GRANDE_CITY_HALL_OF_FAME_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_POKEMON_CENTER_1F_EventObjects
EVER_GRANDE_CITY_POKEMON_CENTER_1F_EventObjects: @ 0x0850C05C
	object_event 1, 58, 0, 7, 2, 3, 8, 0, 0, 0, 0, EverGrandeCity_PokemonCenter_1F_EventScript_00211421, 0x0000
	object_event 2, 34, 0, 5, 5, 3, 8, 0, 0, 0, 0, EverGrandeCity_PokemonCenter_1F_EventScript_0021142F, 0x0000
	object_event 3, 21, 0, 10, 7, 3, 10, 0, 0, 0, 0, EverGrandeCity_PokemonCenter_1F_EventScript_00211438, 0x0000
	object_event 4, 219, 0, 9, 4, 3, 7, 0, 0, 0, 0, EverGrandeCity_PokemonCenter_1F_EventScript_00211441, 0x0319
	.globl EVER_GRANDE_CITY_POKEMON_CENTER_1F_EventWarps
EVER_GRANDE_CITY_POKEMON_CENTER_1F_EventWarps: @ 0x0850C0BC
	warp_def 7, 8, 3, 1, MAP_EVER_GRANDE_CITY
	warp_def 6, 8, 3, 1, MAP_EVER_GRANDE_CITY
	warp_def 1, 6, 4, 0, MAP_EVER_GRANDE_CITY_POKEMON_CENTER_2F
	.globl gMapEvents_EVER_GRANDE_CITY_POKEMON_CENTER_1F
gMapEvents_EVER_GRANDE_CITY_POKEMON_CENTER_1F: @ 0x0850C0D4
	map_events EVER_GRANDE_CITY_POKEMON_CENTER_1F_EventObjects, EVER_GRANDE_CITY_POKEMON_CENTER_1F_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_POKEMON_CENTER_2F_EventObjects
EVER_GRANDE_CITY_POKEMON_CENTER_2F_EventObjects: @ 0x0850C0E8
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 3, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	.globl EVER_GRANDE_CITY_POKEMON_CENTER_2F_EventWarps
EVER_GRANDE_CITY_POKEMON_CENTER_2F_EventWarps: @ 0x0850C148
	warp_def 1, 6, 4, 2, MAP_EVER_GRANDE_CITY_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_EVER_GRANDE_CITY_POKEMON_CENTER_2F
gMapEvents_EVER_GRANDE_CITY_POKEMON_CENTER_2F: @ 0x0850C160
	map_events EVER_GRANDE_CITY_POKEMON_CENTER_2F_EventObjects, EVER_GRANDE_CITY_POKEMON_CENTER_2F_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_POKEMON_LEAGUE_2F_EventObjects
EVER_GRANDE_CITY_POKEMON_LEAGUE_2F_EventObjects: @ 0x0850C174
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 0, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	.globl EVER_GRANDE_CITY_POKEMON_LEAGUE_2F_EventWarps
EVER_GRANDE_CITY_POKEMON_LEAGUE_2F_EventWarps: @ 0x0850C1D4
	warp_def 1, 6, 4, 4, MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_EVER_GRANDE_CITY_POKEMON_LEAGUE_2F
gMapEvents_EVER_GRANDE_CITY_POKEMON_LEAGUE_2F: @ 0x0850C1EC
	map_events EVER_GRANDE_CITY_POKEMON_LEAGUE_2F_EventObjects, EVER_GRANDE_CITY_POKEMON_LEAGUE_2F_EventWarps, 0, 0
	.globl ROUTE104_MR_BRINEYS_HOUSE_EventObjects
ROUTE104_MR_BRINEYS_HOUSE_EventObjects: @ 0x0850C200
	object_event 1, 21, 0, 5, 3, 3, 50, 3, 3, 0, 0, Route104_MrBrineysHouse_EventScript_00211629, 0x02E3
	object_event 2, 211, 0, 6, 3, 3, 8, 3, 3, 0, 0, Route104_MrBrineysHouse_EventScript_0021171F, 0x0371
	.globl ROUTE104_MR_BRINEYS_HOUSE_EventWarps
ROUTE104_MR_BRINEYS_HOUSE_EventWarps: @ 0x0850C230
	warp_def 5, 8, 0, 0, MAP_ROUTE104
	warp_def 6, 8, 0, 0, MAP_ROUTE104
	.globl gMapEvents_ROUTE104_MR_BRINEYS_HOUSE
gMapEvents_ROUTE104_MR_BRINEYS_HOUSE: @ 0x0850C240
	map_events ROUTE104_MR_BRINEYS_HOUSE_EventObjects, ROUTE104_MR_BRINEYS_HOUSE_EventWarps, 0, 0
	.globl ROUTE104_PRETTY_PETAL_FLOWER_SHOP_EventObjects
ROUTE104_PRETTY_PETAL_FLOWER_SHOP_EventObjects: @ 0x0850C254
	object_event 1, 20, 0, 0, 3, 3, 10, 0, 0, 0, 0, Route104_PrettyPetalFlowerShop_EventScript_002119DB, 0x0000
	object_event 2, 14, 0, 7, 3, 3, 5, 1, 0, 0, 0, Route104_PrettyPetalFlowerShop_EventScript_00211A74, 0x0000
	object_event 3, 8, 0, 11, 6, 4, 2, 2, 2, 0, 0, Route104_PrettyPetalFlowerShop_EventScript_00211AAA, 0x0000
	.globl ROUTE104_PRETTY_PETAL_FLOWER_SHOP_EventWarps
ROUTE104_PRETTY_PETAL_FLOWER_SHOP_EventWarps: @ 0x0850C29C
	warp_def 2, 8, 0, 1, MAP_ROUTE104
	warp_def 3, 8, 0, 1, MAP_ROUTE104
	.globl gMapEvents_ROUTE104_PRETTY_PETAL_FLOWER_SHOP
gMapEvents_ROUTE104_PRETTY_PETAL_FLOWER_SHOP: @ 0x0850C2AC
	map_events ROUTE104_PRETTY_PETAL_FLOWER_SHOP_EventObjects, ROUTE104_PRETTY_PETAL_FLOWER_SHOP_EventWarps, 0, 0
	.globl ROUTE111_WINSTRATE_FAMILYS_HOUSE_EventObjects
ROUTE111_WINSTRATE_FAMILYS_HOUSE_EventObjects: @ 0x0850C2C0
	object_event 1, 47, 0, 7, 5, 3, 9, 0, 0, 0, 0, 0x08211B50, 0x0000
	object_event 2, 19, 0, 4, 5, 3, 10, 0, 0, 0, 0, 0x08211AF5, 0x0000
	object_event 3, 18, 0, 7, 4, 3, 9, 1, 0, 0, 0, 0x08211B0A, 0x0000
	object_event 4, 22, 0, 4, 4, 3, 10, 0, 0, 0, 0, 0x08211B65, 0x0000
	.globl ROUTE111_WINSTRATE_FAMILYS_HOUSE_EventWarps
ROUTE111_WINSTRATE_FAMILYS_HOUSE_EventWarps: @ 0x0850C320
	warp_def 3, 7, 0, 0, MAP_ROUTE111
	warp_def 4, 7, 0, 0, MAP_ROUTE111
	.globl gMapEvents_ROUTE111_WINSTRATE_FAMILYS_HOUSE
gMapEvents_ROUTE111_WINSTRATE_FAMILYS_HOUSE: @ 0x0850C330
	map_events ROUTE111_WINSTRATE_FAMILYS_HOUSE_EventObjects, ROUTE111_WINSTRATE_FAMILYS_HOUSE_EventWarps, 0, 0
	.globl ROUTE111_OLD_LADYS_REST_STOP_EventObjects
ROUTE111_OLD_LADYS_REST_STOP_EventObjects: @ 0x0850C344
	object_event 1, 22, 0, 6, 3, 3, 9, 0, 0, 0, 0, Route111_OldLadysRestStop_EventScript_00211DF7, 0x0000
	.globl ROUTE111_OLD_LADYS_REST_STOP_EventWarps
ROUTE111_OLD_LADYS_REST_STOP_EventWarps: @ 0x0850C35C
	warp_def 3, 7, 0, 2, MAP_ROUTE111
	warp_def 4, 7, 0, 2, MAP_ROUTE111
	.globl gMapEvents_ROUTE111_OLD_LADYS_REST_STOP
gMapEvents_ROUTE111_OLD_LADYS_REST_STOP: @ 0x0850C36C
	map_events ROUTE111_OLD_LADYS_REST_STOP_EventObjects, ROUTE111_OLD_LADYS_REST_STOP_EventWarps, 0, 0
	.globl ROUTE112_CABLE_CAR_STATION_EventObjects
ROUTE112_CABLE_CAR_STATION_EventObjects: @ 0x0850C380
	object_event 1, 45, 0, 6, 6, 3, 8, 0, 0, 0, 0, Route112_CableCarStation_EventScript_00211F63, 0x0000
	object_event 2, 114, 0, 6, 3, 3, 1, 0, 0, 0, 0, 0x00000000, 0x0000
	.globl ROUTE112_CABLE_CAR_STATION_EventWarps
ROUTE112_CABLE_CAR_STATION_EventWarps: @ 0x0850C3B0
	warp_def 6, 11, 0, 0, MAP_ROUTE112
	warp_def 7, 11, 0, 1, MAP_ROUTE112
	.globl gMapEvents_ROUTE112_CABLE_CAR_STATION
gMapEvents_ROUTE112_CABLE_CAR_STATION: @ 0x0850C3C0
	map_events ROUTE112_CABLE_CAR_STATION_EventObjects, ROUTE112_CABLE_CAR_STATION_EventWarps, 0, 0
	.globl MT_CHIMNEY_CABLE_CAR_STATION_EventObjects
MT_CHIMNEY_CABLE_CAR_STATION_EventObjects: @ 0x0850C3D4
	object_event 1, 45, 0, 6, 6, 3, 8, 0, 0, 0, 0, MtChimney_CableCarStation_EventScript_00212070, 0x0000
	object_event 2, 114, 0, 6, 3, 3, 1, 0, 0, 0, 0, 0x00000000, 0x0000
	.globl MT_CHIMNEY_CABLE_CAR_STATION_EventWarps
MT_CHIMNEY_CABLE_CAR_STATION_EventWarps: @ 0x0850C404
	warp_def 6, 11, 0, 0, MAP_MT_CHIMNEY
	warp_def 7, 11, 0, 1, MAP_MT_CHIMNEY
	.globl gMapEvents_MT_CHIMNEY_CABLE_CAR_STATION
gMapEvents_MT_CHIMNEY_CABLE_CAR_STATION: @ 0x0850C414
	map_events MT_CHIMNEY_CABLE_CAR_STATION_EventObjects, MT_CHIMNEY_CABLE_CAR_STATION_EventWarps, 0, 0
	.globl ROUTE114_FOSSIL_MANIACS_HOUSE_EventObjects
ROUTE114_FOSSIL_MANIACS_HOUSE_EventObjects: @ 0x0850C428
	object_event 1, 5, 0, 3, 2, 3, 8, 1, 1, 0, 0, Route114_FossilManiacsHouse_EventScript_00212136, 0x0000
	.globl ROUTE114_FOSSIL_MANIACS_HOUSE_EventWarps
ROUTE114_FOSSIL_MANIACS_HOUSE_EventWarps: @ 0x0850C440
	warp_def 4, 7, 0, 1, MAP_ROUTE114
	warp_def 5, 7, 0, 1, MAP_ROUTE114
	warp_def 4, 1, 0, 0, MAP_ROUTE114_FOSSIL_MANIACS_TUNNEL
	.globl ROUTE114_FOSSIL_MANIACS_HOUSE_EventBgEvents
ROUTE114_FOSSIL_MANIACS_HOUSE_EventBgEvents: @ 0x0850C458
	bg_event 5, 3, 0, 1, Route114_FossilManiacsHouse_EventScript_0021216F, 0, 0
	bg_event 6, 3, 0, 1, Route114_FossilManiacsHouse_EventScript_0021216F, 0, 0
	bg_event 7, 2, 0, 1, Route114_FossilManiacsHouse_EventScript_00212178, 0, 0
	bg_event 8, 2, 0, 1, Route114_FossilManiacsHouse_EventScript_00212178, 0, 0
	.globl gMapEvents_ROUTE114_FOSSIL_MANIACS_HOUSE
gMapEvents_ROUTE114_FOSSIL_MANIACS_HOUSE: @ 0x0850C488
	map_events ROUTE114_FOSSIL_MANIACS_HOUSE_EventObjects, ROUTE114_FOSSIL_MANIACS_HOUSE_EventWarps, 0, ROUTE114_FOSSIL_MANIACS_HOUSE_EventBgEvents
	.globl ROUTE114_FOSSIL_MANIACS_TUNNEL_EventObjects
ROUTE114_FOSSIL_MANIACS_TUNNEL_EventObjects: @ 0x0850C49C
	object_event 1, 39, 0, 5, 3, 3, 7, 1, 1, 0, 0, Route114_FossilManiacsTunnel_EventScript_002122EC, 0x0000
	.globl ROUTE114_FOSSIL_MANIACS_TUNNEL_EventWarps
ROUTE114_FOSSIL_MANIACS_TUNNEL_EventWarps: @ 0x0850C4B4
	warp_def 6, 25, 3, 2, MAP_ROUTE114_FOSSIL_MANIACS_HOUSE
	warp_def 7, 25, 3, 2, MAP_ROUTE114_FOSSIL_MANIACS_HOUSE
	warp_def 6, 2, 0, 0, MAP_DESERT_UNDERPASS
	.globl ROUTE114_FOSSIL_MANIACS_TUNNEL_EventCoordEvents
ROUTE114_FOSSIL_MANIACS_TUNNEL_EventCoordEvents: @ 0x0850C4CC
	coord_event 5, 4, 3, 16588, 1, Route114_FossilManiacsTunnel_EventScript_002122CB
	coord_event 6, 4, 3, 16588, 1, Route114_FossilManiacsTunnel_EventScript_002122CB
	.globl gMapEvents_ROUTE114_FOSSIL_MANIACS_TUNNEL
gMapEvents_ROUTE114_FOSSIL_MANIACS_TUNNEL: @ 0x0850C4EC
	map_events ROUTE114_FOSSIL_MANIACS_TUNNEL_EventObjects, ROUTE114_FOSSIL_MANIACS_TUNNEL_EventWarps, ROUTE114_FOSSIL_MANIACS_TUNNEL_EventCoordEvents, 0
	.globl ROUTE114_LANETTES_HOUSE_EventObjects
ROUTE114_LANETTES_HOUSE_EventObjects: @ 0x0850C500
	object_event 1, 20, 0, 5, 4, 3, 1, 0, 0, 0, 0, Route114_LanettesHouse_EventScript_002124DB, 0x0366
	.globl ROUTE114_LANETTES_HOUSE_EventWarps
ROUTE114_LANETTES_HOUSE_EventWarps: @ 0x0850C518
	warp_def 5, 7, 0, 2, MAP_ROUTE114
	warp_def 6, 7, 0, 2, MAP_ROUTE114
	.globl ROUTE114_LANETTES_HOUSE_EventBgEvents
ROUTE114_LANETTES_HOUSE_EventBgEvents: @ 0x0850C528
	bg_event 5, 1, 0, 0, Route114_LanettesHouse_EventScript_00212512, 0, 0
	bg_event 8, 1, 0, 0, Route114_LanettesHouse_EventScript_0021254E, 0, 0
	bg_event 7, 1, 0, 0, Route114_LanettesHouse_EventScript_0021254E, 0, 0
	.globl gMapEvents_ROUTE114_LANETTES_HOUSE
gMapEvents_ROUTE114_LANETTES_HOUSE: @ 0x0850C54C
	map_events ROUTE114_LANETTES_HOUSE_EventObjects, ROUTE114_LANETTES_HOUSE_EventWarps, 0, ROUTE114_LANETTES_HOUSE_EventBgEvents
	.globl ROUTE116_TUNNELERS_REST_HOUSE_EventObjects
ROUTE116_TUNNELERS_REST_HOUSE_EventObjects: @ 0x0850C560
	object_event 1, 25, 0, 6, 5, 3, 10, 0, 0, 0, 0, Route116_TunnelersRestHouse_EventScript_0021282A, 0x0000
	object_event 2, 25, 0, 3, 6, 3, 1, 1, 1, 0, 0, Route116_TunnelersRestHouse_EventScript_0021283C, 0x0000
	object_event 3, 25, 0, 7, 2, 3, 7, 1, 0, 0, 0, Route116_TunnelersRestHouse_EventScript_00212833, 0x0000
	.globl ROUTE116_TUNNELERS_REST_HOUSE_EventWarps
ROUTE116_TUNNELERS_REST_HOUSE_EventWarps: @ 0x0850C5A8
	warp_def 4, 8, 0, 1, MAP_ROUTE116
	warp_def 5, 8, 0, 1, MAP_ROUTE116
	.globl gMapEvents_ROUTE116_TUNNELERS_REST_HOUSE
gMapEvents_ROUTE116_TUNNELERS_REST_HOUSE: @ 0x0850C5B8
	map_events ROUTE116_TUNNELERS_REST_HOUSE_EventObjects, ROUTE116_TUNNELERS_REST_HOUSE_EventWarps, 0, 0
	.globl ROUTE117_POKEMON_DAY_CARE_EventObjects
ROUTE117_POKEMON_DAY_CARE_EventObjects: @ 0x0850C5CC
	object_event 1, 30, 0, 2, 2, 3, 8, 0, 0, 0, 0, 0x082577DA, 0x0000
	.globl ROUTE117_POKEMON_DAY_CARE_EventWarps
ROUTE117_POKEMON_DAY_CARE_EventWarps: @ 0x0850C5E4
	warp_def 2, 8, 0, 0, MAP_ROUTE117
	warp_def 3, 8, 0, 0, MAP_ROUTE117
	.globl gMapEvents_ROUTE117_POKEMON_DAY_CARE
gMapEvents_ROUTE117_POKEMON_DAY_CARE: @ 0x0850C5F4
	map_events ROUTE117_POKEMON_DAY_CARE_EventObjects, ROUTE117_POKEMON_DAY_CARE_EventWarps, 0, 0
	.globl ROUTE121_SAFARI_ZONE_ENTRANCE_EventObjects
ROUTE121_SAFARI_ZONE_ENTRANCE_EventObjects: @ 0x0850C608
	object_event 1, 32, 0, 17, 9, 3, 9, 0, 0, 0, 0, Route121_SafariZoneEntrance_EventScript_00212A10, 0x0000
	object_event 2, 31, 0, 10, 2, 3, 8, 0, 0, 0, 0, Route121_SafariZoneEntrance_EventScript_00212A19, 0x0000
	object_event 3, 31, 0, 8, 2, 3, 8, 0, 0, 0, 0, 0x00000000, 0x0000
	.globl ROUTE121_SAFARI_ZONE_ENTRANCE_EventWarps
ROUTE121_SAFARI_ZONE_ENTRANCE_EventWarps: @ 0x0850C650
	warp_def 2, 5, 0, 0, MAP_SAFARI_ZONE_SOUTH
	warp_def 3, 5, 0, 0, MAP_SAFARI_ZONE_SOUTH
	warp_def 14, 13, 0, 0, MAP_ROUTE121
	warp_def 15, 13, 0, 0, MAP_ROUTE121
	.globl ROUTE121_SAFARI_ZONE_ENTRANCE_EventCoordEvents
ROUTE121_SAFARI_ZONE_ENTRANCE_EventCoordEvents: @ 0x0850C670
	coord_event 8, 4, 3, 16385, 0, Route121_SafariZoneEntrance_EventScript_00212A42
	.globl ROUTE121_SAFARI_ZONE_ENTRANCE_EventBgEvents
ROUTE121_SAFARI_ZONE_ENTRANCE_EventBgEvents: @ 0x0850C680
	bg_event 15, 1, 0, 0, Route121_SafariZoneEntrance_EventScript_00212B4B, 0, 0
	.globl gMapEvents_ROUTE121_SAFARI_ZONE_ENTRANCE
gMapEvents_ROUTE121_SAFARI_ZONE_ENTRANCE: @ 0x0850C68C
	map_events ROUTE121_SAFARI_ZONE_ENTRANCE_EventObjects, ROUTE121_SAFARI_ZONE_ENTRANCE_EventWarps, ROUTE121_SAFARI_ZONE_ENTRANCE_EventCoordEvents, ROUTE121_SAFARI_ZONE_ENTRANCE_EventBgEvents
	.globl METEOR_FALLS_1F_1R_EventObjects
METEOR_FALLS_1F_1R_EventObjects: @ 0x0850C6A0
	object_event 1, 59, 0, 2, 4, 3, 1, 0, 0, 0, 0, 0x08256F02, 0x0414
	object_event 2, 59, 0, 2, 14, 3, 1, 0, 0, 0, 0, 0x08256F1C, 0x0416
	object_event 3, 59, 0, 27, 5, 3, 1, 0, 0, 0, 0, 0x08256F0F, 0x0415
	object_event 4, 59, 0, 26, 32, 3, 1, 0, 0, 0, 0, 0x08256F29, 0x0417
	object_event 5, 119, 0, 12, 20, 3, 8, 0, 0, 0, 0, 0x00000000, 0x03AB
	object_event 6, 119, 0, 14, 21, 3, 9, 0, 0, 0, 0, 0x00000000, 0x03AB
	object_event 7, 195, 0, 6, 20, 3, 10, 0, 0, 0, 0, 0x00000000, 0x03AA
	object_event 8, 117, 0, 6, 20, 3, 10, 0, 0, 0, 0, 0x00000000, 0x03AA
	object_event 9, 117, 0, 6, 21, 3, 1, 0, 0, 0, 0, 0x00000000, 0x03AA
	object_event 10, 46, 0, 13, 23, 3, 21, 0, 0, 0, 0, MeteorFalls_1F_1R_EventScript_00212D4F, 0x03AE
	.globl METEOR_FALLS_1F_1R_EventWarps
METEOR_FALLS_1F_1R_EventWarps: @ 0x0850C790
	warp_def 27, 18, 4, 0, MAP_ROUTE114
	warp_def 6, 39, 3, 0, MAP_ROUTE115
	warp_def 10, 3, 3, 0, MAP_METEOR_FALLS_1F_2R
	warp_def 5, 4, 3, 4, MAP_METEOR_FALLS_B1F_1R
	warp_def 26, 28, 3, 5, MAP_METEOR_FALLS_B1F_1R
	warp_def 4, 2, 0, 0, MAP_METEOR_FALLS_STEVENS_CAVE
	.globl METEOR_FALLS_1F_1R_EventCoordEvents
METEOR_FALLS_1F_1R_EventCoordEvents: @ 0x0850C7C0
	coord_event 14, 18, 4, 16575, 0, MeteorFalls_1F_1R_EventScript_00212B89
	.globl METEOR_FALLS_1F_1R_EventBgEvents
METEOR_FALLS_1F_1R_EventBgEvents: @ 0x0850C7D0
	bg_event 9, 58, 0, 0, 0x00000000, 0, 0
	.globl gMapEvents_METEOR_FALLS_1F_1R
gMapEvents_METEOR_FALLS_1F_1R: @ 0x0850C7DC
	map_events METEOR_FALLS_1F_1R_EventObjects, METEOR_FALLS_1F_1R_EventWarps, METEOR_FALLS_1F_1R_EventCoordEvents, METEOR_FALLS_1F_1R_EventBgEvents
	.globl METEOR_FALLS_1F_2R_EventObjects
METEOR_FALLS_1F_2R_EventObjects: @ 0x0850C7F0
	object_event 1, 33, 0, 13, 2, 3, 8, 0, 0, 1, 1, 0x0821307A, 0x0000
	object_event 2, 21, 0, 6, 12, 3, 8, 1, 1, 1, 1, 0x082130DC, 0x0000
	object_event 3, 22, 0, 7, 12, 3, 8, 1, 1, 1, 1, 0x08213140, 0x0000
	.globl METEOR_FALLS_1F_2R_EventWarps
METEOR_FALLS_1F_2R_EventWarps: @ 0x0850C838
	warp_def 10, 29, 3, 2, MAP_METEOR_FALLS_1F_1R
	warp_def 4, 14, 3, 0, MAP_METEOR_FALLS_B1F_1R
	warp_def 7, 20, 3, 1, MAP_METEOR_FALLS_B1F_1R
	warp_def 21, 23, 3, 2, MAP_METEOR_FALLS_B1F_1R
	.globl METEOR_FALLS_1F_2R_EventBgEvents
METEOR_FALLS_1F_2R_EventBgEvents: @ 0x0850C858
	bg_event 9, 58, 0, 0, 0x00000000, 0, 0
	.globl gMapEvents_METEOR_FALLS_1F_2R
gMapEvents_METEOR_FALLS_1F_2R: @ 0x0850C864
	map_events METEOR_FALLS_1F_2R_EventObjects, METEOR_FALLS_1F_2R_EventWarps, 0, METEOR_FALLS_1F_2R_EventBgEvents
	.globl METEOR_FALLS_B1F_1R_EventObjects
METEOR_FALLS_B1F_1R_EventObjects: @ 0x00000000
	.globl METEOR_FALLS_B1F_1R_EventWarps
METEOR_FALLS_B1F_1R_EventWarps: @ 0x0850C878
	warp_def 5, 6, 4, 1, MAP_METEOR_FALLS_1F_2R
	warp_def 7, 11, 5, 2, MAP_METEOR_FALLS_1F_2R
	warp_def 18, 15, 4, 3, MAP_METEOR_FALLS_1F_2R
	warp_def 17, 3, 3, 0, MAP_METEOR_FALLS_B1F_2R
	warp_def 3, 23, 5, 3, MAP_METEOR_FALLS_1F_1R
	warp_def 20, 36, 3, 4, MAP_METEOR_FALLS_1F_1R
	.globl gMapEvents_METEOR_FALLS_B1F_1R
gMapEvents_METEOR_FALLS_B1F_1R: @ 0x0850C8A8
	map_events 0, METEOR_FALLS_B1F_1R_EventWarps, 0, 0
	.globl METEOR_FALLS_B1F_2R_EventObjects
METEOR_FALLS_B1F_2R_EventObjects: @ 0x0850C8BC
	object_event 1, 59, 0, 5, 3, 3, 1, 1, 1, 0, 0, 0x08256F36, 0x0438
	.globl METEOR_FALLS_B1F_2R_EventWarps
METEOR_FALLS_B1F_2R_EventWarps: @ 0x0850C8D4
	warp_def 5, 15, 3, 3, MAP_METEOR_FALLS_B1F_1R
	.globl gMapEvents_METEOR_FALLS_B1F_2R
gMapEvents_METEOR_FALLS_B1F_2R: @ 0x0850C8DC
	map_events METEOR_FALLS_B1F_2R_EventObjects, METEOR_FALLS_B1F_2R_EventWarps, 0, 0
	.globl RUSTURF_TUNNEL_EventObjects
RUSTURF_TUNNEL_EventObjects: @ 0x0850C8F0
	object_event 1, 44, 0, 23, 5, 3, 10, 0, 0, 0, 0, RusturfTunnel_EventScript_0021363F, 0x0327
	object_event 2, 86, 0, 24, 5, 3, 1, 0, 0, 0, 0, 0x0825667C, 0x03A3
	object_event 3, 59, 0, 3, 1, 3, 1, 0, 0, 0, 0, 0x08256E8D, 0x0418
	object_event 4, 59, 0, 30, 2, 3, 1, 0, 0, 0, 0, 0x08256E9A, 0x0419
	object_event 5, 21, 0, 5, 4, 3, 10, 0, 0, 0, 0, 0x00000000, 0x036F
	object_event 6, 117, 0, 14, 5, 3, 9, 0, 0, 0, 0, 0x0821388B, 0x036E
	object_event 7, 211, 0, 14, 4, 3, 9, 0, 0, 0, 0, RusturfTunnel_EventScript_00213878, 0x0370
	object_event 8, 86, 0, 24, 4, 3, 8, 0, 0, 0, 0, 0x0825667C, 0x03A4
	object_event 9, 55, 0, 32, 13, 3, 9, 1, 1, 1, 3, 0x0821397A, 0x0000
	object_event 10, 20, 0, 25, 4, 3, 9, 1, 1, 0, 0, RusturfTunnel_EventScript_00213628, 0x03D7
	.globl RUSTURF_TUNNEL_EventWarps
RUSTURF_TUNNEL_EventWarps: @ 0x0850C9E0
	warp_def 4, 10, 3, 0, MAP_ROUTE116
	warp_def 29, 16, 3, 4, MAP_VERDANTURF_TOWN
	warp_def 18, 20, 3, 2, MAP_ROUTE116
	.globl RUSTURF_TUNNEL_EventCoordEvents
RUSTURF_TUNNEL_EventCoordEvents: @ 0x0850C9F8
	coord_event 23, 4, 3, 0, 0, RusturfTunnel_EventScript_0021383A
	coord_event 9, 4, 3, 16538, 2, RusturfTunnel_EventScript_0021384C
	coord_event 9, 5, 3, 16538, 2, RusturfTunnel_EventScript_0021384C
	coord_event 25, 4, 3, 0, 0, RusturfTunnel_EventScript_00213840
	coord_event 25, 5, 3, 0, 0, RusturfTunnel_EventScript_00213846
	.globl gMapEvents_RUSTURF_TUNNEL
gMapEvents_RUSTURF_TUNNEL: @ 0x0850CA48
	map_events RUSTURF_TUNNEL_EventObjects, RUSTURF_TUNNEL_EventWarps, RUSTURF_TUNNEL_EventCoordEvents, 0
	.globl UNDERWATER_SOOTOPOLIS_CITY_EventObjects
UNDERWATER_SOOTOPOLIS_CITY_EventObjects: @ 0x00000000
	.globl UNDERWATER_SOOTOPOLIS_CITY_EventWarps
UNDERWATER_SOOTOPOLIS_CITY_EventWarps: @ 0x0850CA5C
	warp_def 9, 8, 0, 0, MAP_UNDERWATER_ROUTE126
	warp_def 10, 8, 0, 0, MAP_UNDERWATER_ROUTE126
	.globl gMapEvents_UNDERWATER_SOOTOPOLIS_CITY
gMapEvents_UNDERWATER_SOOTOPOLIS_CITY: @ 0x0850CA6C
	map_events 0, UNDERWATER_SOOTOPOLIS_CITY_EventWarps, 0, 0
	.globl DESERT_RUINS_EventObjects
DESERT_RUINS_EventObjects: @ 0x0850CA80
	object_event 1, 200, 0, 8, 7, 3, 8, 0, 0, 0, 0, DesertRuins_EventScript_00213E86, 0x03A7
	.globl DESERT_RUINS_EventWarps
DESERT_RUINS_EventWarps: @ 0x0850CA98
	warp_def 8, 29, 3, 1, MAP_ROUTE111
	warp_def 8, 20, 0, 2, MAP_DESERT_RUINS
	warp_def 8, 11, 3, 1, MAP_DESERT_RUINS
	.globl DESERT_RUINS_EventBgEvents
DESERT_RUINS_EventBgEvents: @ 0x0850CAB0
	bg_event 8, 20, 0, 0, DesertRuins_EventScript_00213E5F, 0, 0
	bg_event 7, 20, 0, 0, DesertRuins_EventScript_00213E7C, 0, 0
	bg_event 9, 20, 0, 0, DesertRuins_EventScript_00213E7C, 0, 0
	.globl gMapEvents_DESERT_RUINS
gMapEvents_DESERT_RUINS: @ 0x0850CAD4
	map_events DESERT_RUINS_EventObjects, DESERT_RUINS_EventWarps, 0, DESERT_RUINS_EventBgEvents
	.globl GRANITE_CAVE_1F_EventObjects
GRANITE_CAVE_1F_EventObjects: @ 0x0850CAE8
	object_event 1, 55, 0, 36, 9, 3, 1, 0, 0, 0, 0, 0x08213EE2, 0x0000
	object_event 2, 59, 0, 17, 7, 3, 8, 0, 0, 0, 0, 0x08256EA7, 0x041A
	.globl GRANITE_CAVE_1F_EventWarps
GRANITE_CAVE_1F_EventWarps: @ 0x0850CB18
	warp_def 37, 12, 3, 0, MAP_ROUTE106
	warp_def 35, 3, 3, 0, MAP_GRANITE_CAVE_B1F
	warp_def 17, 11, 3, 1, MAP_GRANITE_CAVE_B1F
	warp_def 5, 10, 3, 0, MAP_GRANITE_CAVE_STEVENS_ROOM
	.globl gMapEvents_GRANITE_CAVE_1F
gMapEvents_GRANITE_CAVE_1F: @ 0x0850CB38
	map_events GRANITE_CAVE_1F_EventObjects, GRANITE_CAVE_1F_EventWarps, 0, 0
	.globl GRANITE_CAVE_B1F_EventObjects
GRANITE_CAVE_B1F_EventObjects: @ 0x0850CB4C
	object_event 1, 59, 0, 15, 21, 3, 1, 0, 0, 0, 0, 0x08256EB4, 0x041B
	.globl GRANITE_CAVE_B1F_EventWarps
GRANITE_CAVE_B1F_EventWarps: @ 0x0850CB64
	warp_def 25, 13, 3, 1, MAP_GRANITE_CAVE_1F
	warp_def 4, 21, 3, 2, MAP_GRANITE_CAVE_1F
	warp_def 29, 13, 3, 0, MAP_GRANITE_CAVE_B2F
	warp_def 28, 21, 3, 1, MAP_GRANITE_CAVE_B2F
	warp_def 8, 5, 3, 2, MAP_GRANITE_CAVE_B2F
	warp_def 12, 3, 3, 3, MAP_GRANITE_CAVE_B2F
	warp_def 29, 2, 3, 4, MAP_GRANITE_CAVE_B2F
	.globl gMapEvents_GRANITE_CAVE_B1F
gMapEvents_GRANITE_CAVE_B1F: @ 0x0850CB9C
	map_events GRANITE_CAVE_B1F_EventObjects, GRANITE_CAVE_B1F_EventWarps, 0, 0
	.globl GRANITE_CAVE_B2F_EventObjects
GRANITE_CAVE_B2F_EventObjects: @ 0x0850CBB0
	object_event 1, 59, 0, 4, 4, 3, 1, 0, 0, 0, 0, 0x08256EC1, 0x041D
	object_event 2, 59, 0, 29, 4, 3, 1, 0, 0, 0, 0, 0x08256ECE, 0x041E
	object_event 3, 86, 0, 5, 14, 3, 1, 1, 1, 0, 0, 0x0825667C, 0x0011
	object_event 4, 86, 0, 3, 14, 3, 1, 1, 1, 0, 0, 0x0825667C, 0x0012
	object_event 5, 86, 0, 2, 16, 3, 1, 1, 1, 0, 0, 0x0825667C, 0x0013
	object_event 6, 86, 0, 7, 12, 3, 1, 1, 1, 0, 0, 0x0825667C, 0x0014
	object_event 7, 86, 0, 4, 22, 3, 1, 1, 1, 0, 0, 0x0825667C, 0x0015
	object_event 8, 86, 0, 6, 22, 3, 1, 1, 1, 0, 0, 0x0825667C, 0x0016
	object_event 9, 86, 0, 3, 21, 3, 1, 1, 1, 0, 0, 0x0825667C, 0x0017
	.globl GRANITE_CAVE_B2F_EventWarps
GRANITE_CAVE_B2F_EventWarps: @ 0x0850CC88
	warp_def 29, 13, 3, 2, MAP_GRANITE_CAVE_B1F
	warp_def 28, 21, 3, 3, MAP_GRANITE_CAVE_B1F
	warp_def 8, 5, 3, 4, MAP_GRANITE_CAVE_B1F
	warp_def 12, 3, 3, 5, MAP_GRANITE_CAVE_B1F
	warp_def 29, 2, 3, 6, MAP_GRANITE_CAVE_B1F
	.globl GRANITE_CAVE_B2F_EventBgEvents
GRANITE_CAVE_B2F_EventBgEvents: @ 0x0850CCB0
	bg_event 28, 6, 3, 7, 0x00C3, 0x30, 0x00
	bg_event 15, 11, 3, 7, 0x00C3, 0x31, 0x00
	.globl gMapEvents_GRANITE_CAVE_B2F
gMapEvents_GRANITE_CAVE_B2F: @ 0x0850CCC8
	map_events GRANITE_CAVE_B2F_EventObjects, GRANITE_CAVE_B2F_EventWarps, 0, GRANITE_CAVE_B2F_EventBgEvents
	.globl GRANITE_CAVE_STEVENS_ROOM_EventObjects
GRANITE_CAVE_STEVENS_ROOM_EventObjects: @ 0x0850CCDC
	object_event 1, 134, 0, 7, 8, 3, 1, 0, 0, 0, 0, 0x08214028, 0x0341
	.globl GRANITE_CAVE_STEVENS_ROOM_EventWarps
GRANITE_CAVE_STEVENS_ROOM_EventWarps: @ 0x0850CCF4
	warp_def 7, 3, 3, 3, MAP_GRANITE_CAVE_1F
	.globl gMapEvents_GRANITE_CAVE_STEVENS_ROOM
gMapEvents_GRANITE_CAVE_STEVENS_ROOM: @ 0x0850CCFC
	map_events GRANITE_CAVE_STEVENS_ROOM_EventObjects, GRANITE_CAVE_STEVENS_ROOM_EventWarps, 0, 0
	.globl PETALBURG_WOODS_EventObjects
PETALBURG_WOODS_EventObjects: @ 0x0850CD10
	object_event 1, 82, 0, 19, 10, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0011
	object_event 2, 82, 0, 19, 11, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0012
	object_event 3, 117, 0, 26, 17, 3, 10, 0, 0, 0, 0, 0x00000000, 0x02D5
	object_event 4, 23, 0, 26, 20, 3, 1, 0, 0, 0, 0, 0x00000000, 0x02D4
	object_event 5, 59, 0, 45, 7, 3, 8, 0, 0, 0, 0, 0x08256E66, 0x0420
	object_event 6, 59, 0, 35, 20, 3, 8, 0, 0, 0, 0, 0x08256E59, 0x041F
	object_event 7, 59, 0, 4, 8, 3, 1, 0, 0, 0, 0, 0x08256E73, 0x0422
	object_event 8, 9, 0, 15, 19, 3, 3, 1, 2, 0, 0, 0x082144B2, 0x0000
	object_event 9, 36, 0, 7, 32, 3, 22, 0, 0, 1, 3, 0x0821450F, 0x0000
	object_event 10, 36, 0, 4, 14, 3, 20, 0, 0, 1, 3, 0x08214526, 0x0000
	object_event 11, 13, 0, 30, 34, 3, 2, 2, 1, 0, 0, 0x082144BB, 0x0000
	object_event 12, 59, 0, 4, 26, 3, 1, 1, 1, 0, 0, 0x08256E80, 0x045D
	object_event 13, 10, 0, 33, 5, 3, 1, 1, 1, 0, 0, 0x082144C4, 0x0000
	.globl PETALBURG_WOODS_EventWarps
PETALBURG_WOODS_EventWarps: @ 0x0850CE48
	warp_def 14, 5, 0, 2, MAP_ROUTE104
	warp_def 15, 5, 0, 3, MAP_ROUTE104
	warp_def 16, 38, 0, 4, MAP_ROUTE104
	warp_def 17, 38, 0, 5, MAP_ROUTE104
	warp_def 36, 38, 0, 6, MAP_ROUTE104
	warp_def 37, 38, 0, 7, MAP_ROUTE104
	.globl PETALBURG_WOODS_EventCoordEvents
PETALBURG_WOODS_EventCoordEvents: @ 0x0850CE78
	coord_event 26, 23, 3, 16536, 0, 0x08214279
	coord_event 27, 23, 3, 16536, 0, 0x0821431B
	.globl PETALBURG_WOODS_EventBgEvents
PETALBURG_WOODS_EventBgEvents: @ 0x0850CE98
	bg_event 14, 32, 3, 0, 0x082144FD, 0, 0
	bg_event 39, 35, 3, 7, 0x000D, 0x3A, 0x00
	bg_event 26, 6, 3, 7, 0x0067, 0x3B, 0x00
	bg_event 40, 29, 3, 7, 0x0067, 0x3C, 0x00
	bg_event 4, 19, 3, 7, 0x0004, 0x3D, 0x00
	bg_event 11, 8, 3, 0, 0x08214506, 0, 0
	.globl gMapEvents_PETALBURG_WOODS
gMapEvents_PETALBURG_WOODS: @ 0x0850CEE0
	map_events PETALBURG_WOODS_EventObjects, PETALBURG_WOODS_EventWarps, PETALBURG_WOODS_EventCoordEvents, PETALBURG_WOODS_EventBgEvents
	.globl MT_CHIMNEY_EventObjects
MT_CHIMNEY_EventObjects: @ 0x0850CEF4
	object_event 1, 195, 0, 24, 19, 3, 9, 0, 0, 0, 0, MtChimney_EventScript_00214BA8, 0x039E
	object_event 2, 196, 0, 13, 6, 3, 10, 0, 0, 0, 0, 0x08214BDE, 0x039F
	object_event 3, 119, 0, 12, 11, 3, 9, 0, 0, 1, 2, 0x08214E41, 0x039F
	object_event 4, 119, 0, 32, 5, 3, 9, 0, 0, 0, 0, MtChimney_EventScript_00214E93, 0x039F
	object_event 5, 119, 0, 28, 12, 3, 10, 0, 0, 0, 0, MtChimney_EventScript_00214E8A, 0x039F
	object_event 6, 117, 0, 19, 39, 3, 10, 0, 0, 0, 0, MtChimney_EventScript_00214E2F, 0x039E
	object_event 7, 117, 0, 29, 5, 3, 10, 0, 0, 0, 0, MtChimney_EventScript_00214E26, 0x039E
	object_event 8, 117, 0, 31, 12, 3, 9, 0, 0, 0, 0, MtChimney_EventScript_00214E38, 0x039E
	object_event 9, 30, 0, 19, 39, 3, 10, 0, 0, 0, 0, MtChimney_EventScript_00214CC6, 0x03E2
	object_event 10, 119, 0, 22, 39, 3, 9, 0, 0, 0, 0, MtChimney_EventScript_00214E9C, 0x039F
	object_event 11, 220, 0, 23, 19, 3, 74, 0, 0, 0, 0, MtChimney_EventScript_00214EAE, 0x039E
	object_event 12, 220, 0, 23, 18, 3, 64, 0, 0, 0, 0, MtChimney_EventScript_00214EA5, 0x039F
	object_event 13, 119, 0, 23, 17, 3, 8, 0, 0, 0, 0, MtChimney_EventScript_00214E78, 0x039F
	object_event 14, 220, 0, 23, 20, 3, 65, 0, 0, 0, 0, MtChimney_EventScript_00214EA5, 0x039F
	object_event 15, 220, 0, 22, 19, 3, 67, 0, 0, 0, 0, MtChimney_EventScript_00214EA5, 0x039F
	object_event 16, 119, 0, 23, 21, 3, 7, 0, 0, 0, 0, MtChimney_EventScript_00214E81, 0x039F
	object_event 17, 119, 0, 21, 19, 3, 10, 0, 0, 0, 0, MtChimney_EventScript_00214E6F, 0x039F
	object_event 18, 220, 0, 30, 12, 3, 66, 0, 0, 0, 0, MtChimney_EventScript_00214EAE, 0x039E
	object_event 19, 220, 0, 29, 12, 3, 67, 0, 0, 0, 0, MtChimney_EventScript_00214EA5, 0x039F
	object_event 20, 220, 0, 30, 5, 3, 67, 0, 0, 0, 0, MtChimney_EventScript_00214EAE, 0x039E
	object_event 21, 220, 0, 31, 5, 3, 66, 0, 0, 0, 0, MtChimney_EventScript_00214EA5, 0x039F
	object_event 22, 119, 0, 9, 16, 3, 10, 0, 0, 1, 3, 0x08214E58, 0x039F
	object_event 23, 220, 0, 20, 39, 3, 67, 0, 0, 0, 0, MtChimney_EventScript_00214EAE, 0x039E
	object_event 24, 220, 0, 21, 39, 3, 66, 0, 0, 0, 0, MtChimney_EventScript_00214EA5, 0x039F
	object_event 25, 22, 0, 16, 18, 3, 13, 0, 0, 1, 3, 0x08214F1D, 0x036D
	object_event 26, 45, 0, 14, 7, 3, 70, 0, 0, 1, 6, 0x08214F7F, 0x036D
	object_event 27, 45, 0, 29, 7, 3, 17, 1, 1, 1, 3, 0x08214F96, 0x036D
	object_event 28, 45, 0, 27, 17, 3, 16, 1, 1, 1, 3, 0x08214FAD, 0x036D
	object_event 29, 120, 0, 13, 16, 3, 9, 1, 1, 1, 3, 0x08214FC4, 0x039F
	object_event 30, 55, 0, 7, 7, 3, 10, 1, 1, 1, 6, 0x08214FDB, 0x036D
	.globl MT_CHIMNEY_EventWarps
MT_CHIMNEY_EventWarps: @ 0x0850D1C4
	warp_def 17, 36, 0, 0, MAP_MT_CHIMNEY_CABLE_CAR_STATION
	warp_def 18, 36, 0, 1, MAP_MT_CHIMNEY_CABLE_CAR_STATION
	warp_def 20, 41, 3, 2, MAP_JAGGED_PASS
	warp_def 21, 41, 3, 3, MAP_JAGGED_PASS
	.globl MT_CHIMNEY_EventBgEvents
MT_CHIMNEY_EventBgEvents: @ 0x0850D1E4
	bg_event 14, 6, 0, 0, MtChimney_EventScript_00214EB7, 0, 0
	bg_event 24, 37, 3, 0, MtChimney_EventScript_00214F14, 0, 0
	.globl gMapEvents_MT_CHIMNEY
gMapEvents_MT_CHIMNEY: @ 0x0850D1FC
	map_events MT_CHIMNEY_EventObjects, MT_CHIMNEY_EventWarps, 0, MT_CHIMNEY_EventBgEvents
	.globl JAGGED_PASS_EventObjects
JAGGED_PASS_EventObjects: @ 0x0850D210
	object_event 1, 55, 0, 10, 8, 3, 10, 0, 0, 1, 3, 0x08215C21, 0x0000
	object_event 2, 31, 0, 16, 35, 3, 14, 0, 0, 1, 4, 0x08215C97, 0x0000
	object_event 3, 59, 0, 23, 24, 3, 1, 0, 0, 0, 0, 0x08256EDB, 0x042E
	object_event 4, 32, 0, 9, 21, 3, 16, 1, 1, 1, 3, 0x08215C38, 0x0000
	object_event 5, 119, 0, 16, 19, 3, 7, 1, 1, 0, 0, 0x08215BB4, 0x034F
	object_event 6, 32, 0, 14, 25, 3, 10, 1, 1, 1, 3, 0x08215D0D, 0x0000
	object_event 7, 56, 0, 18, 25, 3, 9, 1, 1, 1, 3, 0x08215CF6, 0x0000
	.globl JAGGED_PASS_EventWarps
JAGGED_PASS_EventWarps: @ 0x0850D2B8
	warp_def 14, 40, 3, 2, MAP_ROUTE112
	warp_def 15, 40, 3, 3, MAP_ROUTE112
	warp_def 13, 5, 3, 2, MAP_MT_CHIMNEY
	warp_def 14, 5, 3, 3, MAP_MT_CHIMNEY
	warp_def 16, 18, 0, 0, MAP_MAGMA_HIDEOUT_1F
	.globl JAGGED_PASS_EventCoordEvents
JAGGED_PASS_EventCoordEvents: @ 0x0850D2E0
	coord_event 13, 15, 3, 2, 0, 0x00000000
	coord_event 21, 12, 3, 8, 0, 0x00000000
	coord_event 14, 15, 3, 2, 0, 0x00000000
	coord_event 18, 17, 3, 2, 0, 0x00000000
	coord_event 22, 19, 3, 2, 0, 0x00000000
	coord_event 21, 15, 3, 16584, 1, JaggedPass_EventScript_00215B57
	coord_event 22, 20, 3, 16584, 1, JaggedPass_EventScript_00215B57
	coord_event 21, 20, 3, 16584, 1, JaggedPass_EventScript_00215B57
	coord_event 14, 15, 3, 16584, 1, JaggedPass_EventScript_00215B57
	coord_event 13, 15, 3, 16584, 1, JaggedPass_EventScript_00215B57
	.globl JAGGED_PASS_EventBgEvents
JAGGED_PASS_EventBgEvents: @ 0x0850D380
	bg_event 8, 10, 3, 7, 0x0017, 0x4D, 0x00
	bg_event 7, 29, 3, 7, 0x0003, 0x4C, 0x00
	.globl gMapEvents_JAGGED_PASS
gMapEvents_JAGGED_PASS: @ 0x0850D398
	map_events JAGGED_PASS_EventObjects, JAGGED_PASS_EventWarps, JAGGED_PASS_EventCoordEvents, JAGGED_PASS_EventBgEvents
	.globl FIERY_PATH_EventObjects
FIERY_PATH_EventObjects: @ 0x0850D3AC
	object_event 1, 59, 0, 8, 3, 3, 1, 1, 1, 0, 0, 0x08256EF5, 0x0443
	object_event 2, 87, 0, 10, 15, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0011
	object_event 3, 87, 0, 17, 15, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0012
	object_event 4, 87, 0, 8, 11, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0013
	object_event 5, 87, 0, 3, 12, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0014
	object_event 6, 87, 0, 6, 23, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0015
	object_event 7, 87, 0, 5, 24, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0016
	object_event 8, 59, 0, 7, 32, 3, 1, 1, 1, 0, 0, 0x08256EE8, 0x0457
	.globl FIERY_PATH_EventWarps
FIERY_PATH_EventWarps: @ 0x0850D46C
	warp_def 26, 36, 3, 4, MAP_ROUTE112
	warp_def 26, 4, 3, 5, MAP_ROUTE112
	.globl gMapEvents_FIERY_PATH
gMapEvents_FIERY_PATH: @ 0x0850D47C
	map_events FIERY_PATH_EventObjects, FIERY_PATH_EventWarps, 0, 0
	.globl MT_PYRE_1F_EventObjects
MT_PYRE_1F_EventObjects: @ 0x0850D490
	object_event 1, 30, 0, 21, 2, 3, 8, 1, 1, 0, 0, 0x0821611A, 0x0000
	object_event 2, 18, 0, 17, 8, 3, 7, 1, 1, 0, 0, 0x08216153, 0x0000
	object_event 3, 65, 0, 13, 10, 3, 9, 1, 1, 0, 0, 0x0821615C, 0x0000
	.globl MT_PYRE_1F_EventWarps
MT_PYRE_1F_EventWarps: @ 0x0850D4D8
	warp_def 17, 18, 3, 0, MAP_ROUTE122
	warp_def 3, 6, 3, 0, MAP_MT_PYRE_EXTERIOR
	warp_def 18, 18, 3, 0, MAP_ROUTE122
	warp_def 4, 6, 3, 0, MAP_MT_PYRE_EXTERIOR
	warp_def 11, 1, 3, 0, MAP_MT_PYRE_2F
	warp_def 20, 9, 3, 4, MAP_MT_PYRE_2F
	.globl gMapEvents_MT_PYRE_1F
gMapEvents_MT_PYRE_1F: @ 0x0850D508
	map_events MT_PYRE_1F_EventObjects, MT_PYRE_1F_EventWarps, 0, 0
	.globl MT_PYRE_2F_EventObjects
MT_PYRE_2F_EventObjects: @ 0x0850D51C
	object_event 1, 39, 0, 3, 6, 3, 10, 1, 1, 1, 2, 0x0821625D, 0x0000
	object_event 2, 59, 0, 0, 10, 3, 1, 1, 1, 0, 0, 0x08257054, 0x0469
	object_event 3, 16, 0, 9, 3, 3, 10, 1, 1, 0, 0, MtPyre_2F_EventScript_0021624B, 0x0000
	object_event 4, 25, 0, 12, 10, 3, 8, 1, 1, 0, 0, MtPyre_2F_EventScript_00216254, 0x0000
	object_event 5, 26, 0, 2, 9, 3, 8, 1, 1, 1, 1, 0x0821628F, 0x0000
	object_event 6, 65, 0, 3, 9, 3, 8, 1, 1, 1, 1, 0x08216274, 0x0000
	object_event 7, 44, 0, 6, 9, 3, 7, 1, 1, 1, 2, 0x082162C1, 0x0000
	object_event 8, 40, 0, 6, 6, 3, 17, 1, 1, 1, 2, 0x082162AA, 0x0000
	.globl MT_PYRE_2F_EventWarps
MT_PYRE_2F_EventWarps: @ 0x0850D5DC
	warp_def 2, 1, 3, 4, MAP_MT_PYRE_1F
	warp_def 10, 1, 3, 0, MAP_MT_PYRE_3F
	warp_def 10, 12, 3, 4, MAP_MT_PYRE_3F
	warp_def 6, 12, 3, 5, MAP_MT_PYRE_3F
	warp_def 11, 9, 3, 5, MAP_MT_PYRE_1F
	.globl gMapEvents_MT_PYRE_2F
gMapEvents_MT_PYRE_2F: @ 0x0850D604
	map_events MT_PYRE_2F_EventObjects, MT_PYRE_2F_EventWarps, 0, 0
	.globl MT_PYRE_3F_EventObjects
MT_PYRE_3F_EventObjects: @ 0x0850D618
	object_event 1, 37, 0, 1, 4, 3, 18, 1, 1, 1, 4, 0x082165F2, 0x0000
	object_event 2, 47, 0, 11, 4, 3, 17, 1, 1, 1, 4, 0x08216609, 0x0000
	object_event 3, 59, 0, 0, 7, 3, 1, 1, 1, 0, 0, 0x08257061, 0x0460
	object_event 4, 20, 0, 6, 4, 3, 14, 1, 1, 1, 4, 0x08216620, 0x0000
	.globl MT_PYRE_3F_EventWarps
MT_PYRE_3F_EventWarps: @ 0x0850D678
	warp_def 10, 1, 3, 1, MAP_MT_PYRE_2F
	warp_def 2, 1, 3, 1, MAP_MT_PYRE_4F
	warp_def 9, 10, 3, 4, MAP_MT_PYRE_4F
	warp_def 1, 12, 3, 5, MAP_MT_PYRE_4F
	warp_def 10, 12, 3, 2, MAP_MT_PYRE_2F
	warp_def 6, 12, 3, 3, MAP_MT_PYRE_2F
	.globl gMapEvents_MT_PYRE_3F
gMapEvents_MT_PYRE_3F: @ 0x0850D6A8
	map_events MT_PYRE_3F_EventObjects, MT_PYRE_3F_EventWarps, 0, 0
	.globl MT_PYRE_4F_EventObjects
MT_PYRE_4F_EventObjects: @ 0x0850D6BC
	object_event 1, 40, 0, 11, 7, 3, 24, 1, 1, 1, 2, 0x082168FB, 0x0000
	object_event 2, 59, 0, 3, 11, 3, 1, 1, 1, 0, 0, 0x0825706E, 0x046A
	.globl MT_PYRE_4F_EventWarps
MT_PYRE_4F_EventWarps: @ 0x0850D6EC
	warp_def 10, 1, 3, 1, MAP_MT_PYRE_5F
	warp_def 2, 5, 3, 1, MAP_MT_PYRE_3F
	warp_def 12, 10, 3, 3, MAP_MT_PYRE_5F
	warp_def 12, 12, 3, 4, MAP_MT_PYRE_5F
	warp_def 9, 10, 3, 2, MAP_MT_PYRE_3F
	warp_def 2, 12, 3, 3, MAP_MT_PYRE_3F
	.globl gMapEvents_MT_PYRE_4F
gMapEvents_MT_PYRE_4F: @ 0x0850D71C
	map_events MT_PYRE_4F_EventObjects, MT_PYRE_4F_EventWarps, 0, 0
	.globl MT_PYRE_5F_EventObjects
MT_PYRE_5F_EventObjects: @ 0x0850D730
	object_event 1, 44, 0, 3, 7, 3, 17, 1, 1, 1, 2, 0x08216881, 0x0000
	object_event 2, 59, 0, 6, 11, 3, 1, 1, 1, 0, 0, 0x0825707B, 0x041C
	.globl MT_PYRE_5F_EventWarps
MT_PYRE_5F_EventWarps: @ 0x0850D760
	warp_def 2, 1, 3, 0, MAP_MT_PYRE_6F
	warp_def 10, 5, 3, 0, MAP_MT_PYRE_4F
	warp_def 1, 10, 3, 1, MAP_MT_PYRE_6F
	warp_def 12, 10, 3, 2, MAP_MT_PYRE_4F
	warp_def 12, 12, 3, 3, MAP_MT_PYRE_4F
	.globl gMapEvents_MT_PYRE_5F
gMapEvents_MT_PYRE_5F: @ 0x0850D788
	map_events MT_PYRE_5F_EventObjects, MT_PYRE_5F_EventWarps, 0, 0
	.globl MT_PYRE_6F_EventObjects
MT_PYRE_6F_EventObjects: @ 0x0850D79C
	object_event 1, 40, 0, 6, 3, 3, 23, 1, 1, 1, 3, 0x08216987, 0x0000
	object_event 2, 59, 0, 6, 9, 3, 1, 1, 1, 0, 0, 0x08257088, 0x0441
	object_event 3, 37, 0, 10, 3, 3, 24, 1, 1, 1, 3, 0x082169E9, 0x0000
	.globl MT_PYRE_6F_EventWarps
MT_PYRE_6F_EventWarps: @ 0x0850D7E4
	warp_def 2, 1, 3, 0, MAP_MT_PYRE_5F
	warp_def 1, 10, 3, 2, MAP_MT_PYRE_5F
	.globl gMapEvents_MT_PYRE_6F
gMapEvents_MT_PYRE_6F: @ 0x0850D7F4
	map_events MT_PYRE_6F_EventObjects, MT_PYRE_6F_EventWarps, 0, 0
	.globl MT_PYRE_EXTERIOR_EventObjects
MT_PYRE_EXTERIOR_EventObjects: @ 0x0850D808
	object_event 1, 59, 0, 27, 15, 3, 1, 0, 0, 0, 0, 0x08257095, 0x0431
	object_event 2, 59, 0, 19, 40, 3, 1, 0, 0, 0, 0, 0x082570A2, 0x0432
	.globl MT_PYRE_EXTERIOR_EventWarps
MT_PYRE_EXTERIOR_EventWarps: @ 0x0850D838
	warp_def 10, 42, 3, 1, MAP_MT_PYRE_1F
	warp_def 19, 10, 3, 1, MAP_MT_PYRE_SUMMIT
	warp_def 20, 10, 3, 1, MAP_MT_PYRE_SUMMIT
	.globl MT_PYRE_EXTERIOR_EventCoordEvents
MT_PYRE_EXTERIOR_EventCoordEvents: @ 0x0850D850
	coord_event 24, 21, 3, 0, 0, MtPyre_Exterior_EventScript_00216B6A
	coord_event 25, 21, 3, 0, 0, MtPyre_Exterior_EventScript_00216B6A
	coord_event 22, 27, 3, 0, 0, MtPyre_Exterior_EventScript_00216B6F
	coord_event 23, 28, 3, 0, 0, MtPyre_Exterior_EventScript_00216B6F
	coord_event 26, 21, 3, 0, 0, MtPyre_Exterior_EventScript_00216B6A
	.globl MT_PYRE_EXTERIOR_EventBgEvents
MT_PYRE_EXTERIOR_EventBgEvents: @ 0x0850D8A0
	bg_event 9, 8, 0, 7, 0x0002, 0x1D, 0x00
	bg_event 16, 22, 0, 7, 0x0023, 0x4E, 0x00
	.globl gMapEvents_MT_PYRE_EXTERIOR
gMapEvents_MT_PYRE_EXTERIOR: @ 0x0850D8B8
	map_events MT_PYRE_EXTERIOR_EventObjects, MT_PYRE_EXTERIOR_EventWarps, MT_PYRE_EXTERIOR_EventCoordEvents, MT_PYRE_EXTERIOR_EventBgEvents
	.globl MT_PYRE_SUMMIT_EventObjects
MT_PYRE_SUMMIT_EventObjects: @ 0x0850D8CC
	object_event 1, 29, 0, 22, 5, 3, 8, 0, 0, 0, 0, MtPyre_Summit_EventScript_00216CB9, 0x0000
	object_event 2, 195, 0, 23, 6, 3, 7, 0, 0, 0, 0, 0x00000000, 0x0394
	object_event 3, 22, 0, 23, 5, 3, 8, 0, 0, 0, 0, MtPyre_Summit_EventScript_00216D1F, 0x0000
	object_event 4, 117, 0, 21, 15, 3, 10, 0, 0, 1, 3, 0x08216F7A, 0x0395
	object_event 5, 117, 0, 25, 18, 3, 9, 0, 0, 1, 3, 0x08216F91, 0x0395
	object_event 6, 117, 0, 21, 11, 3, 10, 0, 0, 1, 3, 0x08216FA8, 0x0395
	object_event 7, 118, 0, 25, 11, 3, 9, 1, 1, 1, 3, 0x08216FBF, 0x0395
	object_event 8, 196, 0, 23, 6, 3, 7, 1, 1, 0, 0, 0x00000000, 0x0358
	.globl MT_PYRE_SUMMIT_EventWarps
MT_PYRE_SUMMIT_EventWarps: @ 0x0850D98C
	warp_def 22, 31, 3, 1, MAP_MT_PYRE_EXTERIOR
	warp_def 23, 31, 3, 1, MAP_MT_PYRE_EXTERIOR
	warp_def 24, 31, 3, 1, MAP_MT_PYRE_EXTERIOR
	.globl MT_PYRE_SUMMIT_EventCoordEvents
MT_PYRE_SUMMIT_EventCoordEvents: @ 0x0850D9A4
	coord_event 22, 7, 3, 16569, 0, MtPyre_Summit_EventScript_00216B95
	coord_event 23, 7, 3, 16569, 0, MtPyre_Summit_EventScript_00216BA1
	coord_event 24, 7, 3, 16569, 0, MtPyre_Summit_EventScript_00216BAD
	coord_event 22, 9, 3, 16569, 2, MtPyre_Summit_EventScript_00216D69
	coord_event 23, 9, 3, 16569, 2, MtPyre_Summit_EventScript_00216D75
	coord_event 24, 9, 3, 16569, 2, MtPyre_Summit_EventScript_00216D81
	.globl MT_PYRE_SUMMIT_EventBgEvents
MT_PYRE_SUMMIT_EventBgEvents: @ 0x0850DA04
	bg_event 9, 25, 0, 7, 0x0046, 0x4F, 0x00
	bg_event 37, 7, 3, 7, 0x0044, 0x50, 0x00
	.globl gMapEvents_MT_PYRE_SUMMIT
gMapEvents_MT_PYRE_SUMMIT: @ 0x0850DA1C
	map_events MT_PYRE_SUMMIT_EventObjects, MT_PYRE_SUMMIT_EventWarps, MT_PYRE_SUMMIT_EventCoordEvents, MT_PYRE_SUMMIT_EventBgEvents
	.globl AQUA_HIDEOUT_1F_EventObjects
AQUA_HIDEOUT_1F_EventObjects: @ 0x0850DA30
	object_event 1, 117, 0, 13, 11, 3, 8, 0, 0, 0, 0, 0x08217936, 0x0335
	object_event 2, 117, 0, 14, 11, 3, 8, 0, 0, 0, 0, 0x08217968, 0x0336
	object_event 3, 117, 0, 20, 4, 3, 50, 13, 5, 1, 3, 0x0821799A, 0x039C
	.globl AQUA_HIDEOUT_1F_EventWarps
AQUA_HIDEOUT_1F_EventWarps: @ 0x0850DA78
	warp_def 13, 27, 1, 6, MAP_LILYCOVE_CITY
	warp_def 14, 27, 1, 6, MAP_LILYCOVE_CITY
	warp_def 22, 1, 3, 0, MAP_AQUA_HIDEOUT_B1F
	.globl gMapEvents_AQUA_HIDEOUT_1F
gMapEvents_AQUA_HIDEOUT_1F: @ 0x0850DA90
	map_events AQUA_HIDEOUT_1F_EventObjects, AQUA_HIDEOUT_1F_EventWarps, 0, 0
	.globl AQUA_HIDEOUT_B1F_EventObjects
AQUA_HIDEOUT_B1F_EventObjects: @ 0x0850DAA4
	object_event 1, 117, 0, 28, 16, 3, 8, 0, 0, 1, 4, 0x08217D8E, 0x039C
	object_event 2, 117, 0, 6, 6, 3, 9, 0, 0, 1, 5, 0x08217DB9, 0x039C
	object_event 3, 59, 0, 29, 12, 3, 1, 0, 0, 0, 0, 0x082570C9, 0x042F
	object_event 4, 118, 0, 20, 18, 3, 23, 4, 0, 1, 4, 0x08217DDE, 0x039C
	object_event 5, 59, 0, 15, 9, 3, 1, 1, 1, 0, 0, 0x082570AF, 0x0464
	object_event 6, 59, 0, 16, 9, 3, 1, 1, 1, 0, 0, AquaHideout_B1F_EventScript_00217CF4, 0x03D1
	object_event 7, 59, 0, 15, 10, 3, 1, 1, 1, 0, 0, 0x082570BC, 0x046C
	object_event 8, 59, 0, 16, 10, 3, 1, 1, 1, 0, 0, AquaHideout_B1F_EventScript_00217D41, 0x03D2
	object_event 9, 118, 0, 28, 21, 3, 7, 1, 1, 1, 4, 0x08217DF5, 0x039C
	.globl AQUA_HIDEOUT_B1F_EventWarps
AQUA_HIDEOUT_B1F_EventWarps: @ 0x0850DB7C
	warp_def 29, 1, 3, 2, MAP_AQUA_HIDEOUT_1F
	warp_def 18, 1, 3, 0, MAP_AQUA_HIDEOUT_B2F
	warp_def 12, 1, 3, 1, MAP_AQUA_HIDEOUT_B2F
	warp_def 3, 3, 3, 2, MAP_AQUA_HIDEOUT_B2F
	warp_def 31, 4, 3, 7, MAP_AQUA_HIDEOUT_B1F
	warp_def 27, 4, 3, 8, MAP_AQUA_HIDEOUT_B1F
	warp_def 20, 4, 3, 10, MAP_AQUA_HIDEOUT_B1F
	warp_def 27, 12, 3, 4, MAP_AQUA_HIDEOUT_B1F
	warp_def 3, 15, 3, 5, MAP_AQUA_HIDEOUT_B1F
	warp_def 3, 20, 3, 12, MAP_AQUA_HIDEOUT_B1F
	warp_def 32, 19, 3, 6, MAP_AQUA_HIDEOUT_B1F
	warp_def 23, 10, 3, 22, MAP_AQUA_HIDEOUT_B1F
	warp_def 45, 3, 3, 9, MAP_AQUA_HIDEOUT_B1F
	warp_def 42, 5, 3, 18, MAP_AQUA_HIDEOUT_B1F
	warp_def 45, 5, 3, 12, MAP_AQUA_HIDEOUT_B1F
	warp_def 48, 5, 3, 16, MAP_AQUA_HIDEOUT_B1F
	warp_def 42, 9, 3, 15, MAP_AQUA_HIDEOUT_B1F
	warp_def 45, 9, 3, 20, MAP_AQUA_HIDEOUT_B1F
	warp_def 48, 9, 3, 13, MAP_AQUA_HIDEOUT_B1F
	warp_def 42, 13, 3, 24, MAP_AQUA_HIDEOUT_B1F
	warp_def 45, 13, 3, 17, MAP_AQUA_HIDEOUT_B1F
	warp_def 48, 13, 3, 12, MAP_AQUA_HIDEOUT_B1F
	warp_def 42, 17, 3, 11, MAP_AQUA_HIDEOUT_B1F
	warp_def 45, 17, 3, 17, MAP_AQUA_HIDEOUT_B1F
	warp_def 48, 17, 3, 19, MAP_AQUA_HIDEOUT_B1F
	.globl gMapEvents_AQUA_HIDEOUT_B1F
gMapEvents_AQUA_HIDEOUT_B1F: @ 0x0850DC44
	map_events AQUA_HIDEOUT_B1F_EventObjects, AQUA_HIDEOUT_B1F_EventWarps, 0, 0
	.globl AQUA_HIDEOUT_B2F_EventObjects
AQUA_HIDEOUT_B2F_EventObjects: @ 0x0850DC58
	object_event 1, 117, 0, 23, 19, 3, 9, 0, 0, 0, 0, 0x08217FD9, 0x039C
	object_event 2, 117, 0, 23, 10, 3, 45, 4, 3, 1, 3, 0x0821805A, 0x039C
	object_event 3, 59, 0, 3, 13, 3, 1, 0, 0, 0, 0, 0x082570D6, 0x0430
	object_event 4, 141, 0, 19, 20, 1, 9, 0, 0, 0, 0, 0x00000000, 0x03AF
	object_event 5, 118, 0, 7, 5, 3, 10, 1, 1, 1, 5, 0x0821807F, 0x039C
	object_event 6, 117, 0, 13, 5, 3, 9, 1, 1, 1, 5, 0x08218096, 0x039C
	.globl AQUA_HIDEOUT_B2F_EventWarps
AQUA_HIDEOUT_B2F_EventWarps: @ 0x0850DCE8
	warp_def 18, 1, 3, 1, MAP_AQUA_HIDEOUT_B1F
	warp_def 12, 1, 3, 2, MAP_AQUA_HIDEOUT_B1F
	warp_def 3, 3, 3, 3, MAP_AQUA_HIDEOUT_B1F
	warp_def 31, 8, 3, 5, MAP_AQUA_HIDEOUT_B2F
	warp_def 8, 8, 3, 8, MAP_AQUA_HIDEOUT_B2F
	warp_def 5, 8, 3, 3, MAP_AQUA_HIDEOUT_B2F
	warp_def 18, 13, 3, 7, MAP_AQUA_HIDEOUT_B2F
	warp_def 12, 13, 3, 6, MAP_AQUA_HIDEOUT_B2F
	warp_def 31, 17, 3, 4, MAP_AQUA_HIDEOUT_B2F
	warp_def 32, 20, 3, 4, MAP_AQUA_HIDEOUT_B1F
	.globl AQUA_HIDEOUT_B2F_EventCoordEvents
AQUA_HIDEOUT_B2F_EventCoordEvents: @ 0x0850DD38
	coord_event 28, 17, 3, 16385, 0, AquaHideout_B2F_EventScript_00217FB5
	coord_event 28, 16, 3, 16385, 0, AquaHideout_B2F_EventScript_00217FB5
	.globl gMapEvents_AQUA_HIDEOUT_B2F
gMapEvents_AQUA_HIDEOUT_B2F: @ 0x0850DD58
	map_events AQUA_HIDEOUT_B2F_EventObjects, AQUA_HIDEOUT_B2F_EventWarps, AQUA_HIDEOUT_B2F_EventCoordEvents, 0
	.globl UNDERWATER_SEAFLOOR_CAVERN_EventObjects
UNDERWATER_SEAFLOOR_CAVERN_EventObjects: @ 0x0850DD6C
	object_event 1, 100, 0, 5, 4, 3, 76, 1, 1, 0, 0, Underwater_SeafloorCavern_EventScript_002183EF, 0x03D4
	object_event 2, 100, 0, 6, 4, 3, 76, 1, 1, 0, 0, Underwater_SeafloorCavern_EventScript_002183EF, 0x03D4
	object_event 3, 100, 0, 7, 4, 3, 76, 1, 1, 0, 0, Underwater_SeafloorCavern_EventScript_002183EF, 0x03D4
	object_event 4, 100, 0, 8, 4, 3, 76, 1, 1, 0, 0, Underwater_SeafloorCavern_EventScript_002183EF, 0x03D4
	.globl UNDERWATER_SEAFLOOR_CAVERN_EventWarps
UNDERWATER_SEAFLOOR_CAVERN_EventWarps: @ 0x0850DDCC
	warp_def 6, 7, 0, 0, MAP_UNDERWATER_ROUTE128
	.globl gMapEvents_UNDERWATER_SEAFLOOR_CAVERN
gMapEvents_UNDERWATER_SEAFLOOR_CAVERN: @ 0x0850DDD4
	map_events UNDERWATER_SEAFLOOR_CAVERN_EventObjects, UNDERWATER_SEAFLOOR_CAVERN_EventWarps, 0, 0
	.globl SEAFLOOR_CAVERN_ENTRANCE_EventObjects
SEAFLOOR_CAVERN_ENTRANCE_EventObjects: @ 0x0850DDE8
	object_event 1, 117, 0, 10, 2, 3, 7, 1, 1, 0, 0, SeafloorCavern_Entrance_EventScript_00218465, 0x03AD
	.globl SEAFLOOR_CAVERN_ENTRANCE_EventWarps
SEAFLOOR_CAVERN_ENTRANCE_EventWarps: @ 0x0850DE00
	warp_def 10, 18, 3, 0, MAP_UNDERWATER_ROUTE128
	warp_def 10, 1, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM1
	.globl gMapEvents_SEAFLOOR_CAVERN_ENTRANCE
gMapEvents_SEAFLOOR_CAVERN_ENTRANCE: @ 0x0850DE10
	map_events SEAFLOOR_CAVERN_ENTRANCE_EventObjects, SEAFLOOR_CAVERN_ENTRANCE_EventWarps, 0, 0
	.globl SEAFLOOR_CAVERN_ROOM1_EventObjects
SEAFLOOR_CAVERN_ROOM1_EventObjects: @ 0x0850DE24
	object_event 1, 87, 0, 5, 11, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0011
	object_event 2, 87, 0, 12, 11, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0012
	object_event 3, 86, 0, 5, 10, 3, 1, 0, 0, 0, 0, 0x0825667C, 0x0013
	object_event 4, 117, 0, 8, 6, 3, 1, 1, 1, 1, 2, 0x0821865F, 0x03B2
	object_event 5, 117, 0, 15, 10, 3, 16, 1, 1, 1, 3, 0x08218676, 0x03B2
	.globl SEAFLOOR_CAVERN_ROOM1_EventWarps
SEAFLOOR_CAVERN_ROOM1_EventWarps: @ 0x0850DE9C
	warp_def 5, 18, 3, 1, MAP_SEAFLOOR_CAVERN_ENTRANCE
	warp_def 17, 13, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM5
	warp_def 6, 2, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM2
	.globl gMapEvents_SEAFLOOR_CAVERN_ROOM1
gMapEvents_SEAFLOOR_CAVERN_ROOM1: @ 0x0850DEB4
	map_events SEAFLOOR_CAVERN_ROOM1_EventObjects, SEAFLOOR_CAVERN_ROOM1_EventWarps, 0, 0
	.globl SEAFLOOR_CAVERN_ROOM2_EventObjects
SEAFLOOR_CAVERN_ROOM2_EventObjects: @ 0x0850DEC8
	object_event 1, 87, 0, 13, 3, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0012
	object_event 2, 87, 0, 10, 3, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0013
	object_event 3, 87, 0, 13, 5, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0011
	object_event 4, 87, 0, 4, 5, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0015
	object_event 5, 87, 0, 7, 4, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0016
	object_event 6, 86, 0, 8, 7, 3, 1, 0, 0, 0, 0, 0x0825667C, 0x0018
	object_event 7, 86, 0, 9, 3, 3, 1, 0, 0, 0, 0, 0x0825667C, 0x0019
	object_event 8, 87, 0, 4, 8, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0017
	.globl SEAFLOOR_CAVERN_ROOM2_EventWarps
SEAFLOOR_CAVERN_ROOM2_EventWarps: @ 0x0850DF88
	warp_def 10, 7, 3, 2, MAP_SEAFLOOR_CAVERN_ROOM1
	warp_def 4, 10, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM4
	warp_def 6, 1, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM6
	warp_def 11, 1, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM7
	.globl gMapEvents_SEAFLOOR_CAVERN_ROOM2
gMapEvents_SEAFLOOR_CAVERN_ROOM2: @ 0x0850DFA8
	map_events SEAFLOOR_CAVERN_ROOM2_EventObjects, SEAFLOOR_CAVERN_ROOM2_EventWarps, 0, 0
	.globl SEAFLOOR_CAVERN_ROOM3_EventObjects
SEAFLOOR_CAVERN_ROOM3_EventObjects: @ 0x0850DFBC
	object_event 1, 87, 0, 13, 10, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0012
	object_event 2, 87, 0, 11, 10, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0014
	object_event 3, 87, 0, 12, 9, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0015
	object_event 4, 87, 0, 12, 7, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0016
	object_event 5, 87, 0, 11, 8, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0017
	object_event 6, 87, 0, 12, 11, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0018
	object_event 7, 87, 0, 13, 8, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0019
	object_event 8, 118, 0, 9, 5, 3, 9, 1, 1, 1, 6, 0x0821873F, 0x03B2
	object_event 9, 117, 0, 5, 5, 3, 10, 1, 1, 1, 4, 0x08218756, 0x03B2
	.globl SEAFLOOR_CAVERN_ROOM3_EventWarps
SEAFLOOR_CAVERN_ROOM3_EventWarps: @ 0x0850E094
	warp_def 8, 1, 3, 1, MAP_SEAFLOOR_CAVERN_ROOM8
	warp_def 9, 13, 3, 1, MAP_SEAFLOOR_CAVERN_ROOM7
	warp_def 4, 15, 3, 1, MAP_SEAFLOOR_CAVERN_ROOM6
	.globl gMapEvents_SEAFLOOR_CAVERN_ROOM3
gMapEvents_SEAFLOOR_CAVERN_ROOM3: @ 0x0850E0AC
	map_events SEAFLOOR_CAVERN_ROOM3_EventObjects, SEAFLOOR_CAVERN_ROOM3_EventWarps, 0, 0
	.globl SEAFLOOR_CAVERN_ROOM4_EventObjects
SEAFLOOR_CAVERN_ROOM4_EventObjects: @ 0x0850E0C0
	object_event 1, 117, 0, 5, 8, 3, 17, 1, 1, 1, 3, 0x0821892F, 0x03B2
	object_event 2, 118, 0, 5, 12, 3, 7, 1, 1, 1, 3, 0x08218946, 0x03B2
	.globl SEAFLOOR_CAVERN_ROOM4_EventWarps
SEAFLOOR_CAVERN_ROOM4_EventWarps: @ 0x0850E0F0
	warp_def 13, 1, 3, 1, MAP_SEAFLOOR_CAVERN_ROOM2
	warp_def 4, 1, 3, 1, MAP_SEAFLOOR_CAVERN_ROOM5
	warp_def 9, 10, 3, 2, MAP_SEAFLOOR_CAVERN_ROOM5
	warp_def 10, 15, 3, 1, MAP_SEAFLOOR_CAVERN_ENTRANCE
	.globl gMapEvents_SEAFLOOR_CAVERN_ROOM4
gMapEvents_SEAFLOOR_CAVERN_ROOM4: @ 0x0850E110
	map_events SEAFLOOR_CAVERN_ROOM4_EventObjects, SEAFLOOR_CAVERN_ROOM4_EventWarps, 0, 0
	.incbin "baserom_jp.gba", 0x50E124, 0x9578

	.globl sFrozenIceCubeSubspriteTable
sFrozenIceCubeSubspriteTable: @ 0x851769C
	.incbin "baserom_jp.gba", 0x51769c, 0x8

	.globl sFrozenIceCubeSpriteTemplate
sFrozenIceCubeSpriteTemplate: @ 0x85176A4
	.incbin "baserom_jp.gba", 0x5176a4, 0x18

	.globl sFlashingCircleImpactSpriteTemplate
sFlashingCircleImpactSpriteTemplate: @ 0x85176BC
	.incbin "baserom_jp.gba", 0x5176bc, 0x3e4

	.globl gTitleScreenPokemonLogoTilemap
gTitleScreenPokemonLogoTilemap: @ 0x8517AA0
	.incbin "baserom_jp.gba", 0x517aa0, 0xb8

	.globl gTitleScreenBgPalettes
gTitleScreenBgPalettes: @ 0x8517B58
	.incbin "baserom_jp.gba", 0x517b58, 0xc0

	.globl gTitleScreenPokemonLogoGfx
gTitleScreenPokemonLogoGfx: @ 0x8517C18
	.incbin "baserom_jp.gba", 0x517c18, 0x1e9c

	.globl sTitleScreenRayquazaGfx
sTitleScreenRayquazaGfx: @ 0x8519AB4
	.incbin "baserom_jp.gba", 0x519ab4, 0x7e4

	.globl sTitleScreenRayquazaTilemap
sTitleScreenRayquazaTilemap: @ 0x851A298
	.incbin "baserom_jp.gba", 0x51a298, 0x450

	.globl sTitleScreenCloudsGfx
sTitleScreenCloudsGfx: @ 0x851A6E8
	.incbin "baserom_jp.gba", 0x51a6e8, 0x2e4

	.globl gTitleScreenCloudsTilemap
gTitleScreenCloudsTilemap: @ 0x851A9CC
	.incbin "baserom_jp.gba", 0x51a9cc, 0x240

	.globl gTitleScreenAlphaBlend
gTitleScreenAlphaBlend: @ 0x851AC0C
	.incbin "baserom_jp.gba", 0x51ac0c, 0xa8

	.globl sVersionBannerLeftSpriteTemplate
sVersionBannerLeftSpriteTemplate: @ 0x851ACB4
	.incbin "baserom_jp.gba", 0x51acb4, 0x18

	.globl sVersionBannerRightSpriteTemplate
sVersionBannerRightSpriteTemplate: @ 0x851ACCC
	.incbin "baserom_jp.gba", 0x51accc, 0x18

	.globl sSpriteSheet_EmeraldVersion
sSpriteSheet_EmeraldVersion: @ 0x851ACE4
	.incbin "baserom_jp.gba", 0x51ace4, 0x90

	.globl sStartCopyrightBannerSpriteTemplate
sStartCopyrightBannerSpriteTemplate: @ 0x851AD74
	.incbin "baserom_jp.gba", 0x51ad74, 0x18

	.globl sSpriteSheet_PressStart
sSpriteSheet_PressStart: @ 0x851AD8C
	.incbin "baserom_jp.gba", 0x51ad8c, 0x10

	.globl sSpritePalette_PressStart
sSpritePalette_PressStart: @ 0x851AD9C
	.incbin "baserom_jp.gba", 0x51ad9c, 0x24

	.globl sPokemonLogoShineSpriteTemplate
sPokemonLogoShineSpriteTemplate: @ 0x851ADC0
	.incbin "baserom_jp.gba", 0x51adc0, 0x18

	.globl sPokemonLogoShineSpriteSheet
sPokemonLogoShineSpriteSheet: @ 0x851ADD8
	.incbin "baserom_jp.gba", 0x51add8, 0x10

	.globl gUnknown_851ADE8
gUnknown_851ADE8: @ 0x851ADE8
	.incbin "baserom_jp.gba", 0x51ade8, 0xc000

	.globl gWeatherPtr
gWeatherPtr: @ 0x8526DE8
	.4byte gUnknown_20380F4 @ &gWeather

	.globl gUnknown_8526DEC
gUnknown_8526DEC: @ 0x8526DEC
	.incbin "baserom_jp.gba", 0x526dec, 0xf0

	.globl gUnknown_8526EDC
gUnknown_8526EDC: @ 0x8526EDC
	.incbin "baserom_jp.gba", 0x526edc, 0x10

	.globl gUnknown_8526EEC
gUnknown_8526EEC: @ 0x8526EEC
	.incbin "baserom_jp.gba", 0x526eec, 0x20

	.globl gFogPalette
gFogPalette: @ 0x8526F0C
	.incbin "baserom_jp.gba", 0x526f0c, 0x20

	.globl gUnknown_8526F2C
gUnknown_8526F2C: @ 0x8526F2C
	.incbin "baserom_jp.gba", 0x526f2c, 0x20

	.globl gUnknown_8526F4C
gUnknown_8526F4C: @ 0x8526F4C
	.incbin "baserom_jp.gba", 0x526f4c, 0x820

	.globl gWeatherFogHorizontalTiles
gWeatherFogHorizontalTiles: @ 0x852776C
	.incbin "baserom_jp.gba", 0x52776c, 0x3080

	.globl gUnknown_852A7EC
gUnknown_852A7EC: @ 0x852A7EC
	.incbin "baserom_jp.gba", 0x52a7ec, 0xc

	.globl gUnknown_852A7F8
gUnknown_852A7F8: @ 0x852A7F8
	.incbin "baserom_jp.gba", 0x52a7f8, 0x1c

	.globl gUnknown_852A814
gUnknown_852A814: @ 0x852A814
	.incbin "baserom_jp.gba", 0x52a814, 0x18

	.globl gUnknown_852A82C
gUnknown_852A82C: @ 0x852A82C
	.incbin "baserom_jp.gba", 0x52a82c, 0x9c

	.globl gUnknown_852A8C8
gUnknown_852A8C8: @ 0x852A8C8
	.incbin "baserom_jp.gba", 0x52a8c8, 0x18

	.globl gUnknown_852A8E0
gUnknown_852A8E0: @ 0x852A8E0
	.incbin "baserom_jp.gba", 0x52a8e0, 0x8

	.globl gUnknown_852A8E8
gUnknown_852A8E8: @ 0x852A8E8
	.incbin "baserom_jp.gba", 0x52a8e8, 0x8

	.globl gUnknown_852A8F0
gUnknown_852A8F0: @ 0x852A8F0
	.incbin "baserom_jp.gba", 0x52a8f0, 0x38

	.globl gUnknown_852A928
gUnknown_852A928: @ 0x852A928
	.incbin "baserom_jp.gba", 0x52a928, 0x8c

	.globl gUnknown_852A9B4
gUnknown_852A9B4: @ 0x852A9B4
	.incbin "baserom_jp.gba", 0x52a9b4, 0x18

	.globl gUnknown_852A9CC
gUnknown_852A9CC: @ 0x852A9CC
	.incbin "baserom_jp.gba", 0x52a9cc, 0x8

	.globl gUnknown_852A9D4
gUnknown_852A9D4: @ 0x852A9D4
	.incbin "baserom_jp.gba", 0x52a9d4, 0x20

	.globl gUnknown_852A9F4
gUnknown_852A9F4: @ 0x852A9F4
	.incbin "baserom_jp.gba", 0x52a9f4, 0x18

	.globl gUnknown_852AA0C
gUnknown_852AA0C: @ 0x852AA0C
	.incbin "baserom_jp.gba", 0x52aa0c, 0x1c

	.globl gUnknown_852AA28
gUnknown_852AA28: @ 0x852AA28
	.incbin "baserom_jp.gba", 0x52aa28, 0x38

	.globl gUnknown_852AA60
gUnknown_852AA60: @ 0x852AA60
	.incbin "baserom_jp.gba", 0x52aa60, 0x18

	.globl gUnknown_852AA78
gUnknown_852AA78: @ 0x852AA78
	.incbin "baserom_jp.gba", 0x52aa78, 0x8

	.globl gUnknown_852AA80
gUnknown_852AA80: @ 0x852AA80
	.incbin "baserom_jp.gba", 0x52aa80, 0xc

	.globl gUnknown_852AA8C
gUnknown_852AA8C: @ 0x852AA8C
	.incbin "baserom_jp.gba", 0x52aa8c, 0x8

	.globl gUnknown_852AA94
gUnknown_852AA94: @ 0x852AA94
	.incbin "baserom_jp.gba", 0x52aa94, 0x8

	.globl gUnknown_852AA9C
gUnknown_852AA9C: @ 0x852AA9C
	.incbin "baserom_jp.gba", 0x52aa9c, 0x44

	.globl gUnknown_852AAE0
gUnknown_852AAE0: @ 0x852AAE0
	.incbin "baserom_jp.gba", 0x52aae0, 0x18

	.globl gUnknown_852AAF8
gUnknown_852AAF8: @ 0x852AAF8
	.incbin "baserom_jp.gba", 0x52aaf8, 0x4

	.globl gUnknown_852AAFC
gUnknown_852AAFC: @ 0x852AAFC
	.incbin "baserom_jp.gba", 0x52aafc, 0x4

	.globl sFlashLevelToRadius
sFlashLevelToRadius: @ 0x852AB00
	.hword 0x00C8, 0x0048, 0x0040, 0x0038, 0x0030, 0x0028, 0x0020, 0x0018, 0x0000, 0x0000

	.globl gMaxFlashLevel
gMaxFlashLevel: @ 0x852AB14
	.incbin "baserom_jp.gba", 0x52ab14, 0x4

	.globl sFlashEffectParams
sFlashEffectParams: @ 0x852AB18
	.incbin "baserom_jp.gba", 0x52ab18, 0xc

	.globl sBattleTransitionTable_Wild
sBattleTransitionTable_Wild: @ 0x852AB24
	.byte 0x08, 0x09, 0x05, 0x0A, 0x00, 0x0A, 0x07, 0x06

	.globl sBattleTransitionTable_Trainer
sBattleTransitionTable_Trainer: @ 0x852AB2C
	.byte 0x04, 0x0B, 0x02, 0x03, 0x00, 0x0A, 0x01, 0x06

	.globl sBattleTransitionTable_BattleFrontier
sBattleTransitionTable_BattleFrontier: @ 0x852AB34
	.byte 0x1D, 0x1E, 0x1F, 0x20, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29

	.globl sBattleTransitionTable_BattlePyramid
sBattleTransitionTable_BattlePyramid: @ 0x852AB40
	.byte 0x1F, 0x20, 0x21

	.globl sBattleTransitionTable_BattleDome
sBattleTransitionTable_BattleDome: @ 0x852AB43
	.byte 0x1D, 0x1F, 0x20, 0x21, 0x00

	.globl sOrdinaryBattleParams
sOrdinaryBattleParams: @ 0x852AB48
	.incbin "baserom_jp.gba", 0x52ab48, 0x48

	.globl sContinueScriptBattleParams
sContinueScriptBattleParams: @ 0x852AB90
	.incbin "baserom_jp.gba", 0x52ab90, 0x48

	.globl sDoubleBattleParams
sDoubleBattleParams: @ 0x852ABD8
	.incbin "baserom_jp.gba", 0x52abd8, 0x48

	.globl sOrdinaryNoIntroBattleParams
sOrdinaryNoIntroBattleParams: @ 0x852AC20
	.incbin "baserom_jp.gba", 0x52ac20, 0x48

	.globl sContinueScriptDoubleBattleParams
sContinueScriptDoubleBattleParams: @ 0x852AC68
	.incbin "baserom_jp.gba", 0x52ac68, 0x48

	.globl sTrainerBOrdinaryBattleParams
sTrainerBOrdinaryBattleParams: @ 0x852ACB0
	.incbin "baserom_jp.gba", 0x52acb0, 0x48

	.globl sTrainerBContinueScriptBattleParams
sTrainerBContinueScriptBattleParams: @ 0x852ACF8
	.incbin "baserom_jp.gba", 0x52acf8, 0x48

	.globl gUnknown_852AD40
gUnknown_852AD40: @ 0x852AD40
	.incbin "baserom_jp.gba", 0x52ad40, 0x4e0

	.globl sBadgeFlagsJp
sBadgeFlagsJp: @ 0x852B220
	.hword 0x867 @ FLAG_BADGE01_GET
	.hword 0x868 @ FLAG_BADGE02_GET
	.hword 0x869 @ FLAG_BADGE03_GET
	.hword 0x86A @ FLAG_BADGE04_GET
	.hword 0x86B @ FLAG_BADGE05_GET
	.hword 0x86C @ FLAG_BADGE06_GET
	.hword 0x86D @ FLAG_BADGE07_GET
	.hword 0x86E @ FLAG_BADGE08_GET

	.globl gUnknown_852B230
gUnknown_852B230: @ 0x852B230
	.incbin "baserom_jp.gba", 0x52b230, 0xc

	.globl gUnknown_852B23C
gUnknown_852B23C: @ 0x852B23C
	.incbin "baserom_jp.gba", 0x52b23c, 0x3

	.globl gUnknown_852B23F
gUnknown_852B23F: @ 0x852B23F
	.incbin "baserom_jp.gba", 0x52b23f, 0x199

	.globl sDirectionalApproachDistanceFuncs
sDirectionalApproachDistanceFuncs: @ 0x852B3D8
	.incbin "baserom_jp.gba", 0x52b3d8, 0x10

	.globl sTrainerSeeFuncList
sTrainerSeeFuncList: @ 0x852B3E8
	.incbin "baserom_jp.gba", 0x52b3e8, 0x30

	.globl sTrainerSeeFuncList2
sTrainerSeeFuncList2: @ 0x852B418
	.incbin "baserom_jp.gba", 0x52b418, 0x48

	.globl sSpriteTemplate_ExclamationQuestionMark
sSpriteTemplate_ExclamationQuestionMark: @ 0x852B460
	.incbin "baserom_jp.gba", 0x52b460, 0x18

	.globl sSpriteTemplate_HeartIcon
sSpriteTemplate_HeartIcon: @ 0x852B478
	.incbin "baserom_jp.gba", 0x52b478, 0x257c

	.globl gUnknown_852D9F4
gUnknown_852D9F4: @ 0x852D9F4
	.incbin "baserom_jp.gba", 0x52d9f4, 0x9c4
	.globl gBattlePyramid_1_LandMons
gBattlePyramid_1_LandMons: @ 0x852E3B8
	.byte 5, 5
	.hword SPECIES_BULBASAUR
	.byte 5, 5
	.hword SPECIES_BULBASAUR
	.byte 5, 5
	.hword SPECIES_BULBASAUR
	.byte 5, 5
	.hword SPECIES_BULBASAUR
	.byte 5, 5
	.hword SPECIES_IVYSAUR
	.byte 5, 5
	.hword SPECIES_IVYSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.globl gBattlePyramid_1_LandMonsInfo
gBattlePyramid_1_LandMonsInfo: @ 0x852E3E8
	.byte 4
	.byte 0, 0, 0
	.4byte gBattlePyramid_1_LandMons
	.globl gBattlePyramid_2_LandMons
gBattlePyramid_2_LandMons: @ 0x852E3F0
	.byte 5, 5
	.hword SPECIES_IVYSAUR
	.byte 5, 5
	.hword SPECIES_IVYSAUR
	.byte 5, 5
	.hword SPECIES_IVYSAUR
	.byte 5, 5
	.hword SPECIES_IVYSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.globl gBattlePyramid_2_LandMonsInfo
gBattlePyramid_2_LandMonsInfo: @ 0x852E420
	.byte 4
	.byte 0, 0, 0
	.4byte gBattlePyramid_2_LandMons
	.globl gBattlePyramid_3_LandMons
gBattlePyramid_3_LandMons: @ 0x852E428
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.globl gBattlePyramid_3_LandMonsInfo
gBattlePyramid_3_LandMonsInfo: @ 0x852E458
	.byte 4
	.byte 0, 0, 0
	.4byte gBattlePyramid_3_LandMons
	.globl gBattlePyramid_4_LandMons
gBattlePyramid_4_LandMons: @ 0x852E460
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.globl gBattlePyramid_4_LandMonsInfo
gBattlePyramid_4_LandMonsInfo: @ 0x852E490
	.byte 4
	.byte 0, 0, 0
	.4byte gBattlePyramid_4_LandMons
	.globl gBattlePyramid_5_LandMons
gBattlePyramid_5_LandMons: @ 0x852E498
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.globl gBattlePyramid_5_LandMonsInfo
gBattlePyramid_5_LandMonsInfo: @ 0x852E4C8
	.byte 4
	.byte 0, 0, 0
	.4byte gBattlePyramid_5_LandMons
	.globl gBattlePyramid_6_LandMons
gBattlePyramid_6_LandMons: @ 0x852E4D0
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.globl gBattlePyramid_6_LandMonsInfo
gBattlePyramid_6_LandMonsInfo: @ 0x852E500
	.byte 4
	.byte 0, 0, 0
	.4byte gBattlePyramid_6_LandMons
	.globl gBattlePyramid_7_LandMons
gBattlePyramid_7_LandMons: @ 0x852E508
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.globl gBattlePyramid_7_LandMonsInfo
gBattlePyramid_7_LandMonsInfo: @ 0x852E538
	.byte 8
	.byte 0, 0, 0
	.4byte gBattlePyramid_7_LandMons

	.globl gBattlePyramidWildMonHeaders
gBattlePyramidWildMonHeaders: @ 0x852E540
	.byte 0, 1 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_1_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 0, 2 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_2_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 0, 3 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_3_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 0, 4 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_4_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 0, 5 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_5_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 0, 6 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_6_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 0, 7 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_7_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 255, 255
	.hword 0
	.4byte 0 @ landMonsInfo NULL
	.4byte 0 @ waterMonsInfo NULL
	.4byte 0 @ rockSmashMonsInfo NULL
	.4byte 0 @ fishingMonsInfo NULL
	.globl gBattlePike_1_LandMons
gBattlePike_1_LandMons: @ 0x852E5E0
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_DUSCLOPS
	.byte 5, 5
	.hword SPECIES_DUSCLOPS
	.byte 5, 5
	.hword SPECIES_DUSCLOPS
	.byte 5, 5
	.hword SPECIES_DUSCLOPS
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_DUSCLOPS
	.byte 5, 5
	.hword SPECIES_DUSCLOPS
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.globl gBattlePike_1_LandMonsInfo
gBattlePike_1_LandMonsInfo: @ 0x852E610
	.byte 10
	.byte 0, 0, 0
	.4byte gBattlePike_1_LandMons
	.globl gBattlePike_2_LandMons
gBattlePike_2_LandMons: @ 0x852E618
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_ELECTRODE
	.byte 5, 5
	.hword SPECIES_ELECTRODE
	.byte 5, 5
	.hword SPECIES_ELECTRODE
	.byte 5, 5
	.hword SPECIES_ELECTRODE
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_ELECTRODE
	.byte 5, 5
	.hword SPECIES_ELECTRODE
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.globl gBattlePike_2_LandMonsInfo
gBattlePike_2_LandMonsInfo: @ 0x852E648
	.byte 10
	.byte 0, 0, 0
	.4byte gBattlePike_2_LandMons
	.globl gBattlePike_3_LandMons
gBattlePike_3_LandMons: @ 0x852E650
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_BRELOOM
	.byte 5, 5
	.hword SPECIES_BRELOOM
	.byte 5, 5
	.hword SPECIES_BRELOOM
	.byte 5, 5
	.hword SPECIES_BRELOOM
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_BRELOOM
	.byte 5, 5
	.hword SPECIES_BRELOOM
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.globl gBattlePike_3_LandMonsInfo
gBattlePike_3_LandMonsInfo: @ 0x852E680
	.byte 10
	.byte 0, 0, 0
	.4byte gBattlePike_3_LandMons
	.globl gBattlePike_4_LandMons
gBattlePike_4_LandMons: @ 0x852E688
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_WOBBUFFET
	.byte 5, 5
	.hword SPECIES_WOBBUFFET
	.byte 5, 5
	.hword SPECIES_WOBBUFFET
	.byte 5, 5
	.hword SPECIES_WOBBUFFET
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_WOBBUFFET
	.byte 5, 5
	.hword SPECIES_WOBBUFFET
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.globl gBattlePike_4_LandMonsInfo
gBattlePike_4_LandMonsInfo: @ 0x852E6B8
	.byte 10
	.byte 0, 0, 0
	.4byte gBattlePike_4_LandMons

	.globl gBattlePikeWildMonHeaders
gBattlePikeWildMonHeaders: @ 0x852E6C0
	.byte 0, 1 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePike_1_LandMonsInfo
	.4byte 0 @ waterMonsInfo NULL
	.4byte 0 @ rockSmashMonsInfo NULL
	.4byte 0 @ fishingMonsInfo NULL
	.byte 0, 2 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePike_2_LandMonsInfo
	.4byte 0 @ waterMonsInfo NULL
	.4byte 0 @ rockSmashMonsInfo NULL
	.4byte 0 @ fishingMonsInfo NULL
	.byte 0, 3 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePike_3_LandMonsInfo
	.4byte 0 @ waterMonsInfo NULL
	.4byte 0 @ rockSmashMonsInfo NULL
	.4byte 0 @ fishingMonsInfo NULL
	.byte 0, 4 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePike_4_LandMonsInfo
	.4byte 0 @ waterMonsInfo NULL
	.4byte 0 @ rockSmashMonsInfo NULL
	.4byte 0 @ fishingMonsInfo NULL
	.byte 255, 255
	.hword 0
	.4byte 0 @ landMonsInfo NULL
	.4byte 0 @ waterMonsInfo NULL
	.4byte 0 @ rockSmashMonsInfo NULL
	.4byte 0 @ fishingMonsInfo NULL

	.globl sWildFeebas
sWildFeebas: @ 0x852E724
	.byte 20, 25 @ minLevel, maxLevel
	.hword SPECIES_FEEBAS @ 0x0148

	.globl gUnknown_852E728
gUnknown_852E728: @ 0x852E728
	.incbin "baserom_jp.gba", 0x52e728, 0x73d4

	.globl gUnknown_8535AFC
gUnknown_8535AFC: @ 0x8535AFC
	.incbin "baserom_jp.gba", 0x535afc, 0x200

	.globl gUnknown_8535CFC
gUnknown_8535CFC: @ 0x8535CFC
	.incbin "baserom_jp.gba", 0x535cfc, 0x20

	.globl gUnknown_8535D1C
gUnknown_8535D1C: @ 0x8535D1C
	.incbin "baserom_jp.gba", 0x535d1c, 0x280

	.globl gUnknown_8535F9C
gUnknown_8535F9C: @ 0x8535F9C
	.incbin "baserom_jp.gba", 0x535f9c, 0x80

	.globl gUnknown_853601C
gUnknown_853601C: @ 0x853601C
	.incbin "baserom_jp.gba", 0x53601c, 0x20

	.globl gUnknown_853603C
gUnknown_853603C: @ 0x853603C
	.incbin "baserom_jp.gba", 0x53603c, 0x280

	.globl gUnknown_85362BC
gUnknown_85362BC: @ 0x85362BC
	.incbin "baserom_jp.gba", 0x5362bc, 0x20

	.globl gUnknown_85362DC
gUnknown_85362DC: @ 0x85362DC
	.incbin "baserom_jp.gba", 0x5362dc, 0xbc0

	.globl gUnknown_8536E9C
gUnknown_8536E9C: @ 0x8536E9C
	.incbin "baserom_jp.gba", 0x536e9c, 0x20

	.globl gUnknown_8536EBC
gUnknown_8536EBC: @ 0x8536EBC
	.incbin "baserom_jp.gba", 0x536ebc, 0x20

	.globl gUnknown_8536EDC
gUnknown_8536EDC: @ 0x8536EDC
	.incbin "baserom_jp.gba", 0x536edc, 0x14

	.globl gUnknown_8536EF0
gUnknown_8536EF0: @ 0x8536EF0
	.incbin "baserom_jp.gba", 0x536ef0, 0x68

	.globl gUnknown_8536F58
gUnknown_8536F58: @ 0x8536F58
	.incbin "baserom_jp.gba", 0x536f58, 0x18

	.globl gUnknown_8536F70
gUnknown_8536F70: @ 0x8536F70
	.incbin "baserom_jp.gba", 0x536f70, 0x40

	.globl gUnknown_8536FB0
gUnknown_8536FB0: @ 0x8536FB0
	.incbin "baserom_jp.gba", 0x536fb0, 0x18

	.globl gUnknown_8536FC8
gUnknown_8536FC8: @ 0x8536FC8
	.incbin "baserom_jp.gba", 0x536fc8, 0x18

	.globl gUnknown_8536FE0
gUnknown_8536FE0: @ 0x8536FE0
	.incbin "baserom_jp.gba", 0x536fe0, 0x18

	.globl gUnknown_8536FF8
gUnknown_8536FF8: @ 0x8536FF8
	.incbin "baserom_jp.gba", 0x536ff8, 0x18

	.globl gUnknown_8537010
gUnknown_8537010: @ 0x8537010
	.incbin "baserom_jp.gba", 0x537010, 0x10

	.globl gUnknown_8537020
gUnknown_8537020: @ 0x8537020
	.incbin "baserom_jp.gba", 0x537020, 0x10

	.globl gUnknown_8537030
gUnknown_8537030: @ 0x8537030
	.incbin "baserom_jp.gba", 0x537030, 0x20

	.globl gUnknown_8537050
gUnknown_8537050: @ 0x8537050
	.incbin "baserom_jp.gba", 0x537050, 0x18

	.globl gUnknown_8537068
gUnknown_8537068: @ 0x8537068
	.incbin "baserom_jp.gba", 0x537068, 0x4

	.globl gUnknown_853706C
gUnknown_853706C: @ 0x853706C
	.incbin "baserom_jp.gba", 0x53706c, 0x4

	.globl gUnknown_8537070
gUnknown_8537070: @ 0x8537070
	.incbin "baserom_jp.gba", 0x537070, 0x4

	.globl gUnknown_8537074
gUnknown_8537074: @ 0x8537074
	.incbin "baserom_jp.gba", 0x537074, 0x1c

	.globl gUnknown_8537090
gUnknown_8537090: @ 0x8537090
	.incbin "baserom_jp.gba", 0x537090, 0x18

	.globl gUnknown_85370A8
gUnknown_85370A8: @ 0x85370A8
	.incbin "baserom_jp.gba", 0x5370a8, 0x1c

	.globl gUnknown_85370C4
gUnknown_85370C4: @ 0x85370C4
	.incbin "baserom_jp.gba", 0x5370c4, 0x14

	.globl gUnknown_85370D8
gUnknown_85370D8: @ 0x85370D8
	.incbin "baserom_jp.gba", 0x5370d8, 0xc

	.globl gUnknown_85370E4
gUnknown_85370E4: @ 0x85370E4
	.incbin "baserom_jp.gba", 0x5370e4, 0x18

	.globl gUnknown_85370FC
gUnknown_85370FC: @ 0x85370FC
	.incbin "baserom_jp.gba", 0x5370fc, 0x10

	.globl gUnknown_853710C
gUnknown_853710C: @ 0x853710C
	.incbin "baserom_jp.gba", 0x53710c, 0x14

	.globl gUnknown_8537120
gUnknown_8537120: @ 0x8537120
	.incbin "baserom_jp.gba", 0x537120, 0x8

	.globl gUnknown_8537128
gUnknown_8537128: @ 0x8537128
	.incbin "baserom_jp.gba", 0x537128, 0x8

	.globl gUnknown_8537130
gUnknown_8537130: @ 0x8537130
	.incbin "baserom_jp.gba", 0x537130, 0x8

	.globl gUnknown_8537138
gUnknown_8537138: @ 0x8537138
	.incbin "baserom_jp.gba", 0x537138, 0x10

	.globl gUnknown_8537148
gUnknown_8537148: @ 0x8537148
	.incbin "baserom_jp.gba", 0x537148, 0xc

	.globl gUnknown_8537154
gUnknown_8537154: @ 0x8537154
	.incbin "baserom_jp.gba", 0x537154, 0x1c

	.globl gUnknown_8537170
gUnknown_8537170: @ 0x8537170
	.incbin "baserom_jp.gba", 0x537170, 0x1c

	.globl gUnknown_853718C
gUnknown_853718C: @ 0x853718C
	.incbin "baserom_jp.gba", 0x53718c, 0x14

	.globl gUnknown_85371A0
gUnknown_85371A0: @ 0x85371A0
	.incbin "baserom_jp.gba", 0x5371a0, 0x54

	.globl gUnknown_85371F4
gUnknown_85371F4: @ 0x85371F4
	.incbin "baserom_jp.gba", 0x5371f4, 0x8

	.globl gUnknown_85371FC
gUnknown_85371FC: @ 0x85371FC
	.incbin "baserom_jp.gba", 0x5371fc, 0x1c

	.globl gUnknown_8537218
gUnknown_8537218: @ 0x8537218
	.incbin "baserom_jp.gba", 0x537218, 0x24

	.globl gUnknown_853723C
gUnknown_853723C: @ 0x853723C
	.incbin "baserom_jp.gba", 0x53723c, 0x5c

	.globl gUnknown_8537298
gUnknown_8537298: @ 0x8537298
	.incbin "baserom_jp.gba", 0x537298, 0x18

	.globl gUnknown_85372B0
gUnknown_85372B0: @ 0x85372B0
	.incbin "baserom_jp.gba", 0x5372b0, 0x60

	.globl gUnknown_8537310
gUnknown_8537310: @ 0x8537310
	.incbin "baserom_jp.gba", 0x537310, 0x40

	.globl gUnknown_8537350
gUnknown_8537350: @ 0x8537350
	.incbin "baserom_jp.gba", 0x537350, 0x1c
